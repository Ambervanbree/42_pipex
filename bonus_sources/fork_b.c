/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:47:17 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/07 18:21:26 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

int	fill_structure(int id, t_data **data, char *argv[], char *envp[])
{
	int	i;

	i = 0;
	(*data)->args = ft_split(argv[id], ' ');
	(*data)->cmd = find_location(envp, (*data)->args[0]);
	if ((*data)->cmd == NULL)
	{
		ft_putstr_fd("command not found\n", 2);
		while ((*data)->args[i] != 0)
		{
			free((*data)->args[i]);
			(*data)->args[i] = 0;
			i++;
		}
		free((*data)->args);
		return (0);
	}
	return (1);
}

int	execute_middle(int i, t_data *data, char *envp[], char *argv[])
{
	if (fill_structure(i + 2, &data, argv, envp) == 0)
		return (0);
	if (cmd_middle(i, data, envp) == 0)
		return (0);
	return (1);
}

int	execute_cmds(int i, t_data *data, char *envp[], char *argv[])
{
	if (i == 0)
	{
		if (open_files(i, data, argv, data->argc) == 0)
			return (0);
		if (fill_structure(i + 2, &data, argv, envp) == 0)
			return (0);
		if (cmd_left(data, envp) == 0)
			return (0);
	}
	else if (i == data->nr_cmds - 1)
	{
		if (open_files(i, data, argv, data->argc) == 0)
			return (0);
		if (fill_structure(i + 2, &data, argv, envp) == 0)
			return (0);
		if (cmd_right(data, envp) == 0)
			return (0);
	}
	else
		if (execute_middle(i, data, envp, argv) == 0)
			return (0);
	return (1);
}

int	fork_child(int i, t_data *data, char *argv[], char *envp[])
{
	int	id;

	id = fork();
	if (id == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	else if (id == 0)
	{
		if (execute_cmds(i, data, envp, argv) == 0)
			return (0);
	}
	return (id);
}

int	fork_function(t_data *data, char *argv[], char *envp[])
{
	int	i;

	i = 0;
	while (i < data->nr_cmds)
	{
		data->child_id[i] = fork_child(i, data, argv, envp);
		if (data->child_id[i] == 0)
		{
			finish_up(data->child_id, data);
			return (0);
		}
		i++;
	}
	finish_up(data->child_id, data);
	return (1);
}
