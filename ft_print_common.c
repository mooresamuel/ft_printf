/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_common.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:06:23 by samoore           #+#    #+#             */
/*   Updated: 2023/11/28 14:39:48 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

void	pre_pad(t_box *box, int len)
{
	if (len < box->precision)
	{
		ft_pad('0', box->precision - len);
		box->left_len += max((box->precision - len), 0);
	}
	if (box->zero && box->precision == -1)
		ft_pad('0', max(0, (box->width - len - box->left_len)));
}

void	prefix(t_box *box)
{
	if (box->c == 'p')
		ft_putstr("0x");
	else if (box->c == 'x' && box->hash)
		ft_putstr("0x");
	else if (box->c == 'X' && box->hash)
		ft_putstr("0X");
	else if (box->neg)
		ft_putchar('-');
	else if (box->plus)
		ft_putchar('+');
	else if (box->space)
		ft_putchar(' ');
	if (box->c == 'p' || ((box->c == 'x' || box->c == 'X') && box->hash))
		box->left_len += 2;
	if (box->neg || box->plus || box->space)
		box->left_len += 1;
}

void	pre_sign(t_box *box, int len)
{
	int	sign;
	int	tmp_len;

	sign = 0;
	if (box->hash || box->c == 'p')
		sign = 2;
	else if (box->neg || box->space || box->plus)
		sign = 1;
	tmp_len = sign;
	if (box->precision > len)
		tmp_len += box->precision;
	else
		tmp_len += len;
	if (!box->zero || box->precision != -1)
		ft_pad(' ', max(0, (box->width - tmp_len)));
}
