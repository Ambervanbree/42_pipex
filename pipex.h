/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:27:37 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/07 17:35:37 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include <errno.h>
# include <string.h>
# include <stdio.h>

typedef struct s_data
{
	char	*cmd;
	char	**args;
	char	*file_in;
	char	*file_out;
	int		fd_in;
	int		fd_out;
	int		fd[2];
	int		argc;
}	t_data;

char	*find_location(char *envp[], char *entry);
char	**split_argument(char *entry);
int		fork_function(t_data *data, char *argv[], char *envp[]);
int		cmd_right(t_data *data, char *envp[]);
int		cmd_left(t_data *data, char *envp[]);
void	exit_function(t_data *data);
void	close_all_except(t_data *data, int table, int index);
void	free_struct(t_data **data);
void	finish_up(int *id_child, t_data *data);
int		open_files(int i, t_data *data, char *argv[], int argc);

#endif