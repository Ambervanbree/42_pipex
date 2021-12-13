/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:06:38 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/07 15:24:06 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

void	close_all_except(t_data *data, int pipe, int index)
{
	int	i;

	i = 0;
	while (i < data->nr_pipes)
	{
		if (i != pipe)
		{
			close(data->fd[i][0]);
			close(data->fd[i][1]);
		}
		else
		{
			if (index == 0)
				close(data->fd[i][1]);
			else
				close(data->fd[i][0]);
		}
		i++;
	}
}

void	close_all_except_two(t_data *data, int pipe)
{
	int	i;

	i = 0;
	while (i < data->nr_pipes)
	{
		if (i == pipe)
		{
			close(data->fd[i][1]);
			i++;
			close(data->fd[i][0]);
		}
		else
		{
			close(data->fd[i][0]);
			close(data->fd[i][1]);
		}
		i++;
	}
}

int	cmd_right(t_data *data, char *envp[])
{
	close_all_except(data, data->nr_pipes - 1, 0);
	dup2(data->fd[data->nr_pipes - 1][0], STDIN_FILENO);
	close(data->fd[data->nr_pipes - 1][0]);
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

int	cmd_middle(int i, t_data *data, char *envp[])
{
	close_all_except_two(data, i - 1);
	dup2(data->fd[i - 1][0], STDIN_FILENO);
	close(data->fd[i - 1][0]);
	dup2(data->fd[i][1], STDOUT_FILENO);
	close(data->fd[i][1]);
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
	close_all_except(data, 0, 1);
	dup2(data->fd_in, STDIN_FILENO);
	close(data->fd_in);
	dup2(data->fd[0][1], STDOUT_FILENO);
	close(data->fd[0][1]);
	if (execve(data->cmd, data->args, envp) == -1)
	{
		free_struct(&data);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}
