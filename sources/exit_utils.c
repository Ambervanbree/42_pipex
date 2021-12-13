/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:36:45 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/08 10:12:15 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_struct(t_data **data)
{
	int	i;

	if ((*data)->cmd != 0)
	{
		free((*data)->cmd);
		(*data)->cmd = 0;
	}
	i = 0;
	if ((*data)->args != 0)
	{
		while ((*data)->args[i] != 0)
		{
			printf("args: %s\n", (*data)->args[i]);
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

	close(data->fd[0]);
	close(data->fd[1]);
	i = 0;
	while (i < 2)
	{
		if (id_child[i])
			waitpid(id_child[i], NULL, 0);
		i++;
	}
}
