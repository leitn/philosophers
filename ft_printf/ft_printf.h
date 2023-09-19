/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 06:07:30 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/30 12:08:31 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
int		ft_putstr(char	*str);
int		ft_putchar(char c);
int		ft_nbrcounter(long long nb, int base_len);
int		ft_putnbr(long long n, char *base, int trigger);
int		checkflag(va_list args, const char c);
int		ft_printf(const char *mandatory_argument, ...);
int		ft_pointer(unsigned long long ptr, char *base, int trigger);
int		ft_ptrlen(unsigned long long n, int base_len);
#endif
