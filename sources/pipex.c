/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:44:36 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/29 15:52:05 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	open_files(t_data *data, char *argv[])
{
	data->file_in = argv[1];
	data->fd_in = open(data->file_in, O_RDONLY);
	if (data->fd_in == -1 || access(data->file_in, R_OK) != 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (0);
	}
	data->file_out = argv[data->argc - 1];
	data->fd_out = open(data->file_out, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (access(data->file_out, W_OK) != 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	t_data	data;

	if (argc < 5)
	{
		ft_putstr_fd("Function should have at least 4 arguments", 2);
		return (1);
	}
	data.argc = argc;
	if (open_files(&data, argv) == 0)
		return (1);
	if (pipe(fd) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (1);
	}
	fork_function(fd, &data, argv, envp);
}
