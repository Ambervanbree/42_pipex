/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:47:17 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/29 17:04:46 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fill_structure(int id, t_data *data, char *argv[], char *envp[])
{
	data->args = NULL;
	if (id == 0)
		data->args = split_argument(argv[2]);
	else
		data->args = split_argument(argv[3]);
	data->cmd = find_location(envp, data->args[0]);
	if (data->cmd == 0)
	{
		ft_putstr_fd("Command not found\n", 2);
		return (0);
	}
	return (1);
}

int	fork_again(int *fd, t_data *data, char *argv[], char *envp[])
{
	int	id;

	id = fork();
	if (id == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (0);
	}
	else if (id == 0)
	{
		if (fill_structure(1, data, argv, envp) == 0
			|| pipe_right(fd, data, envp) == 0)
			return (0);
	}
	return (id);
}

int	fork_function(int *fd, t_data *data, char *argv[], char *envp[])
{
	int	id;

	id = fork();
	if (id == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (0);
	}
	else if (id == 0)
	{
		if (fill_structure(0, data, argv, envp) == 0
			|| pipe_left(fd, data, envp) == 0)
			return (0);
	}
	else
		if (fork_again(fd, data, argv, envp) == 0)
			return (0);
	wait(NULL);
	return (1);
}
