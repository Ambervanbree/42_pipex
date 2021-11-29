/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:37:34 by avan-bre          #+#    #+#             */
/*   Updated: 2021/10/27 16:50:39 by avan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_string(char *string);
int		print_int(int i, int count);
int		print_uns_int(unsigned int number, int count);
int		print_hex(unsigned int i, int count);
int		print_hex_cap(unsigned int i, int count);
int		print_ptr(long unsigned int number, int count);

#endif
