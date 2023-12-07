/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_and_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 08:10:19 by samoore           #+#    #+#             */
/*   Updated: 2023/11/28 14:41:02 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(char *s, t_box *box)
{
	int	len;

	if (!s)
	{
		if (box->width > 6)
			ft_pad(' ', box->width - 6);
		if (box->precision == -1 || box->precision >= 6)
			ft_putstr("(null)");
		return ;
	}
	len = ft_strlen(s);
	if (box->precision != -1 && len > box->precision)
		len = box->precision;
	if (!box->left && box->width > len)
		ft_pad(' ', box->width - len);
	ft_putstr_len(s, len);
	if (box->left && box->width > len)
		ft_pad(' ', box->width - len);
}

void	ft_char(int c, t_box *box)
{
	if (box->width != -1 && !box->left)
		ft_pad(' ', box->width - 1);
	ft_putchar((unsigned char)c);
	if (box->width != -1 && box->left)
		ft_pad(' ', box->width - 1);
}

void	zero_hex(t_box *box)
{
	int	len;

	if (box->precision == -1)
		len = 1;
	else
		len = box->precision;
	if (!box->left)
	{
		ft_pad(' ', max(0, (box->width - len)));
		ft_pad('0', len);
	}
	if (box->left)
	{
		ft_pad('0', len);
		ft_pad(' ', max(0, box->width - len));
		return ;
	}
}

void	ft_hex(unsigned long long int n, t_box *box, char c)
{
	int	len;

	if (n == 0)
	{
		zero_hex(box);
		return ;
	}
	len = ft_hexlen(n);
	if (!box->left)
		pre_sign(box, len);
	prefix(box);
	pre_pad(box, len);
	ft_puthex(n, c);
	box->left_len += len;
	if (box->left && box->left_len < (box->width))
		ft_pad(' ', box->width - box->left_len);
}

void	ft_pointer(unsigned long long int n, t_box *box)
{
	if (n == 0)
	{
		if (box->width > 5)
			ft_pad(' ', box->width - 5);
		ft_putstr("(nil)");
		return ;
	}
	box->hash = 1;
	box->precision = 1;
	ft_hex(n, box, 'x');
}
