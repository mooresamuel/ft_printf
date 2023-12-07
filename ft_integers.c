/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:05:14 by samoore           #+#    #+#             */
/*   Updated: 2023/11/28 14:34:09 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(unsigned int n, t_box *box)
{
	int	len;

	len = ft_numlen(n);
	if (box->precision == 0 && n == 0)
		len = 0;
	if (!box->left)
		pre_sign(box, len);
	prefix(box);
	pre_pad(box, len);
	if (n == 0 && box->precision != 0)
		ft_putchar('0');
	else
		ft_putnum(n);
	box->left_len += len;
	if (box->left)
		ft_pad(' ', max((box->width - box->left_len), 0));
}

void	ft_integer(int n, t_box *box)
{
	unsigned int	t;

	if (n < 0)
	{
		box->neg = 1;
		t = (unsigned int)(n * -1);
	}
	else
		t = (unsigned int)n;
	ft_unsigned(t, box);
}
