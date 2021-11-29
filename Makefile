# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 10:09:38 by avan-bre          #+#    #+#              #
#    Updated: 2021/11/29 15:38:40 by avan-bre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 RULES                                        #
################################################################################

NAME	=	pipex
B_NAME	=	pipex_b
LIBFT	=	libft/libft.a
RM		=	@rm -rf
CC		=	@clang
IFLAGS	=	-I. -Ilibft
CFLAGS	:=	-Wall -Werror -Wextra $(IFLAGS)
LFLAGS	:=	-Llibft -lft
SRCS	=	pipex.c find_location.c fork.c pipes.c
B_SRCS	=	pipex_b.c find_location_b.c fork_b.c pipes_b.c
S_DIR	=	sources/
B_DIR	=	bonus_sources/
OBJS	=	$(addprefix $(S_DIR), $(SRCS:.c=.o))
B_OBJS	=	$(addprefix $(B_DIR), $(B_SRCS:.c=.o))

################################################################################
#                                 RULES                                        #
################################################################################

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	@echo "Compiling sources.."
	$(CC) $(OBJS) $(LFLAGS) -o $@   
	@echo "Ready!"

$(LIBFT):
	@echo "Compiling libft.."
	@make -s -C libft
	@echo "Libft ready!"

bonus:	${B_OBJS} ${LIBFT}
	@echo "Compiling bonus sources.."
	${CC} ${B_OBJS} ${LFLAGS} -o ${B_NAME}
	@echo "Ready!"

clean:
	$(RM) $(OBJS) ${B_OBJS}
	@make $@ -s -C libft
	@echo "Removed objects"

fclean:		clean
	$(RM) $(NAME) ${B_NAME}
	@make $@ -s -C libft
	@echo "Removed executable files"

re:			clean all

.PHONY:		re, all, clean, fclean
