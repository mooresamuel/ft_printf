/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:38:11 by samoore           #+#    #+#             */
/*   Updated: 2023/11/28 14:40:32 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_box{
	int		width;
	int		precision;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		left;
	int		neg;
	int		left_len;
	char	c;
}	t_box;

void	clean_box(t_box *box);
void	ft_char(int c, t_box *box);
int		ft_numlen(unsigned int n);
void	ft_hex(unsigned long long int n, t_box *box, char c);
int		ft_hexlen(unsigned long long int n);
void	ft_integer(int n, t_box *box);
int		ft_printf(const char *s, ...);
void	ft_pad(char c, int i);
void	ft_pointer(unsigned long long int n, t_box *box);
int		ft_putchar(int c);
void	ft_puthex(unsigned long long int n, char c);
void	ft_putnum(unsigned int n);
void	ft_putstr(char *s);
void	ft_putstr_len(char *s, int num);
int		ft_strlen(char *s);
int		ft_hexlen(unsigned long long int n);
void	ft_string(char *s, t_box *box);
int		in_set(char c, char *set);
void	ft_unsigned(unsigned int n, t_box *box);
int		max(int n1, int n2);
void	prefix(t_box *box);
void	pre_pad(t_box *box, int len);
void	pre_sign(t_box *box, int len);
void	process(const char *s, int *j, va_list ap);
void	process_flags(const char *s, int *i, va_list ap, t_box *box);

#endif
