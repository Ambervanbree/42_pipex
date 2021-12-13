/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_location_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:45:17 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/07 17:23:06 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

void	free_path_table(char ***path_table, char **path)
{
	int	i;

	i = 0;
	if (path_table)
	{
		while ((*path_table)[i] != 0)
		{
			free((*path_table)[i]);
			(*path_table)[i] = 0;
			i++;
		}
	}
	free((*path_table));
	(*path_table) = 0;
	if (access(*path, F_OK) != 0)
	{
		free(*path);
		*path = NULL;
	}
}

char	*find_location2(char *path_table[], char *path, char *entry)
{
	int		i;
	char	*temp;

	i = 0;
	temp = 0;
	while (path_table[i] != 0)
	{
		if (path)
		{
			free(path);
			path = 0;
		}
		temp = path_table[i];
		path_table[i] = ft_strjoin(path_table[i], "/");
		path = ft_strjoin(path_table[i], entry);
		free(temp);
		temp = 0;
		if (access(path, F_OK) == 0)
			break ;
		i++;
	}
	free_path_table(&path_table, &path);
	return (path);
}

char	*find_location(char *envp[], char *entry)
{
	int		i;
	char	*path;
	char	**path_table;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			path_table = ft_split(path, ':');
		}
		i++;
	}
	return (find_location2(path_table, path, entry));
}

char	**split_argument(char *entry)
{
	char	**args_table;

	args_table = ft_split(entry, ' ');
	return (args_table);
}
