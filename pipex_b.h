/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:09:23 by avan-bre          #+#    #+#             */
/*   Updated: 2021/12/07 15:23:51 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_B_H
# define PIPEX_B_H

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
	int		nr_pipes;
	int		nr_cmds;
	int		fd[1023][2];
	int		child_id[1024];
	int		argc;
}	t_data;

char	*find_location(char *envp[], char *entry);
char	**split_argument(char *entry);
int		fork_function(t_data *data, char *argv[], char *envp[]);
int		cmd_right(t_data *data, char *envp[]);
int		cmd_middle(int i, t_data *data, char *envp[]);
int		cmd_left(t_data *data, char *envp[]);
void	exit_function(t_data *data);
void	close_all_except(t_data *data, int table, int index);
void	free_struct(t_data **data);
void	finish_up(int *id_child, t_data *data);
int		open_files(int i, t_data *data, char *argv[], int argc);

#endif