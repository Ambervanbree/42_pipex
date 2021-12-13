/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:44:36 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/07 16:53:09 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

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
	else
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

void	set_struct(int argc, t_data *data)
{
	int	i;

	data->cmd = NULL;
	data->args = NULL;
	data->fd_in = 0;
	data->fd_out = 0;
	data->nr_pipes = argc - 4;
	data->nr_cmds = argc - 3;
	data->argc = argc;
	i = 0;
	while (i < 1024)
	{
		data->child_id[i] = 0;
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	t_data	data;

	set_struct(argc, &data);
	if (argc < 5)
	{
		ft_putstr_fd("Function should have at least 4 arguments", 2);
		return (1);
	}
	i = -1;
	while (i++ < data.nr_pipes)
	{
		if (pipe(data.fd[i]) == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			ft_putstr_fd("\n", 2);
			return (1);
		}
	}
	if (fork_function(&data, argv, envp) == 0)
		return (1);
}
