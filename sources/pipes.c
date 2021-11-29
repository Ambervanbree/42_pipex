/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:06:38 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/29 15:31:27 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_right(int *fd, t_data *data, char *envp[])
{
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(data->fd_out, 1);
	if (execve(data->cmd, data->args, envp) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (0);
	}
	close(fd[0]);
	return (1);
}

int	pipe_left(int *fd, t_data *data, char *envp[])
{
	close(fd[0]);
	dup2(data->fd_in, 0);
	dup2(fd[1], 1);
	if (execve(data->cmd, data->args, envp) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (0);
	}
	close(fd[1]);
	return (1);
}
