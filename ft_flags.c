/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:46:53 by samoore           #+#    #+#             */
/*   Updated: 2023/11/28 10:40:02 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(const char *s, int *i, va_list ap, t_box *box)
{
	int	n;
	int	j;

	n = 0;
	(*i)++;
	j = *i;
	if (s[j] && s[j] == '*')
	{
		n = va_arg(ap, int);
	}		
	else
	{
		while (s[j] && (s[j] >= '0' && s[j] <= '9'))
		{
			n *= 10;
			n += (s[j] - '0');
			j++;
		}
		*i = (j - 1);
	}
	box->precision = n;
}

void	get_width(const char *s, int *i, va_list ap, t_box *box)
{
	int	n;
	int	j;

	n = 0;
	j = *i;
	if (s[j] && s[j] == '*')
	{
		n = va_arg(ap, int);
	}
	else
	{
		while (s[j] && (s[j] >= '0' && s[j] <= '9'))
		{
			n *= 10;
			n += (s[j] - '0');
			j++;
		}
		(*i) = (j - 1);
	}
	box->width = n;
}

void	set_flags(const char *s, int *j, t_box *box)
{
	while (s[*j] && in_set(s[*j], "+# -0"))
	{
		if (s[*j] == '+')
			(*box).plus = 1;
		else if (s[*j] == '0')
			(*box).zero = 1;
		else if (s[*j] == '#')
			(*box).hash = 1;
		else if (s[*j] == '-')
			(*box).left = 1;
		else if (s[*j] == ' ')
			(*box).space = 1;
		(*j)++;
	}
}

void	clean_box(t_box *box)
{
	if (box->c == 'u' || box->c == 'x' || box->c == 'X'
		|| box->c == 'p')
	{
		box->plus = 0;
		box->space = 0;
	}
	if (box->width < 0)
		box->width = -1;
	if (box->precision < 0)
		box->precision = -1;
	box->left_len = 0;
}

void	process_flags(const char *s, int *i, va_list ap, t_box *b)
{
	int	j;

	j = *i;
	set_flags(s, &j, b);
	while (in_set(s[j], "123456789*."))
	{
		if (s[j] == '.' && b->precision == -1)
			get_precision(s, &j, ap, b);
		else if ((s[j] == '*' || (s[j] > '0' && s[j] <= '9')) && b->width == -1)
			get_width(s, &j, ap, b);
		else
		{
			(*i)--;
			return ;
		}
		j++;
	}
	if (!in_set(s[j], "cspdiuxX%"))
	{
		ft_putchar('%');
		*i -= 1;
		return ;
	}
	if (s[j])
		*i = j;
}
