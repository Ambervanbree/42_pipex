# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/26 10:49:58 by avan-bre          #+#    #+#              #
#    Updated: 2021/10/27 16:51:19 by avan-bre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc -c -o 

AR 		=	ar rcs

RM		=	rm -rf

INC		=	libft.h

SRCS	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c in_set.c get_next_line.c \
			get_next_line_utils.c printf/ft_printf.c printf/print_char.c \
			printf/print_string.c printf/print_int.c printf/print_uns_int.c \
			printf/print_hex.c printf/print_hex_cap.c printf/print_ptr.c \
	
BONUS	=	ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS =		$(SRCS:.c=.o)

OBJS_B =	$(BONUS:.c=.o)

CFLAGS =	-Wall -Werror -Wextra

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

all:	$(NAME)

bonus:	$(OBJS) $(OBJS_B) $(INC)
	$(AR) $(NAME) $(OBJS) $(OBJS_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:	clean
	$(RM) $(NAME)

re:		clean all

.PHONY:	re, all, clean, fclean, bonus
	
