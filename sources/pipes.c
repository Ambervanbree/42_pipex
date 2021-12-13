/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:06:38 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/07 18:05:13 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_right(t_data *data, char *envp[])
{
	close(data->fd[1]);
	dup2(data->fd[0], STDIN_FILENO);
	close(data->fd[0]);
	dup2(data->fd_out, STDOUT_FILENO);
	close(data->fd_out);
	if (execve(data->cmd, data->args, envp) == -1)
	{
		free_struct(&data);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}

int	cmd_left(t_data *data, char *envp[])
{
	close(data->fd[0]);
	dup2(data->fd_in, STDIN_FILENO);
	close(data->fd_in);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[1]);
	if (execve(data->cmd, data->args, envp) == -1)
	{
		free_struct(&data);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}
