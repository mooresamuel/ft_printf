/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:13:49 by samoore           #+#    #+#             */
/*   Updated: 2023/11/28 14:24:58 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	in_set(char c, char *set)
{
	int		i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (set[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

void	ft_pad(char c, int i)
{
	int	j;

	j = 1;
	while (j <= i)
	{
		ft_putchar(c);
		j++;
	}
}

void	init_box(t_box *box)
{
	box->width = -1;
	box->precision = -1;
	box->zero = 0;
	box->hash = 0;
	box->space = 0;
	box->plus = 0;
	box->left = 0;
	box->neg = 0;
	box->left_len = 0;
}

void	format_print(va_list ap, t_box *box, char c)
{
	box->c = c;
	if (c == 's')
		ft_string(va_arg(ap, char *), box);
	if (c == 'c')
		ft_char(va_arg(ap, int), box);
	if (c == 'x' || c == 'X')
		ft_hex((unsigned long long int)va_arg(ap, unsigned int), box, c);
	if (c == 'p')
		ft_pointer(va_arg(ap, unsigned long long int), box);
	if (c == '%')
		ft_putchar('%');
	if (c == 'u')
		ft_unsigned(va_arg(ap, unsigned int), box);
	if (c == 'i' || c == 'd')
		ft_integer(va_arg(ap, int), box);
}

void	process(const char *s, int *i, va_list ap)
{
	t_box	box;

	init_box(&box);
	(*i)++;
	if ((s[*i] && in_set(s[*i], "+ #0.-*")) || (s[*i] >= '1' && s[*i] <= '9'))
		process_flags(s, i, ap, &box);
	box.c = s[*i];
	clean_box(&box);
	if (s[*i] && in_set(s[*i], "cspdiuxX%"))
		format_print(ap, &box, s[*i]);
}
