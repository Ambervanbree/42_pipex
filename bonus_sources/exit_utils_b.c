/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:36:45 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/07 18:23:15 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

void	free_struct(t_data **data)
{
	int	i;

	i = 0;
	if ((*data)->cmd != 0)
	{
		free((*data)->cmd);
		(*data)->cmd = 0;
	}
	if ((*data)->args != 0)
	{
		while ((*data)->args[i] != 0)
		{
			free((*data)->args[i]);
			(*data)->args[i] = 0;
			i++;
		}
		free((*data)->args);
	}
}

void	finish_up(int *id_child, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nr_pipes)
	{
		if (data->fd[i][0])
			close(data->fd[i][0]);
		if (data->fd[i][1])
			close(data->fd[i][1]);
		i++;
	}
	i = 0;
	while (i < data->nr_cmds)
	{
		if (id_child[i])
			waitpid(id_child[i], NULL, 0);
		i++;
	}
}
