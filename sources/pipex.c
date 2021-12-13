/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:44:36 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/07 19:28:33 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_files(int i, t_data *data, char *argv[], int argc)
{
	if (i == 0)
	{
		data->file_in = argv[1];
		data->fd_in = open(data->file_in, O_RDONLY);
		if (data->fd_in == -1 || access(data->file_in, R_OK) != 0)
		{
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			return (0);
		}
	}
	if (i == 1)
	{
		data->file_out = argv[argc - 1];
		data->fd_out = open(data->file_out, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (access(data->file_out, W_OK) != 0)
		{
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	data.cmd = NULL;
	data.args = NULL;
	data.argc = argc;
	if (argc != 5)
	{
		ft_putstr_fd
		("Expected format arguments: \"in_file\" \"cmd1\" \"cmd2\" \"out_file\"", 2);
		return (1);
	}
	if (pipe(data.fd) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	if (fork_function(&data, argv, envp) == 0)
		return (1);
}
