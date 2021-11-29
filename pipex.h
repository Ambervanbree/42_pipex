/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:09:23 by avan-bre          #+#    #+#             */
/*   Updated: 2021/11/29 15:33:55 by avan-bre         ###   ########.fr       */
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

typedef struct	s_data
{
	char	*cmd;
	char	**args;
	char	*file_in;
	char	*file_out;
	int		fd_in;
	int		fd_out;
	int		argc;
}	t_data;

char	*find_location(char *envp[], char *entry);
char	**split_argument(char *entry);
int		fork_function(int *fd, t_data *data, char *argv[], char *envp[]);
int		pipe_right(int *fd, t_data *data, char *envp[]);
int		pipe_left(int *fd, t_data *data, char *envp[]);

#endif