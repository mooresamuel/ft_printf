/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:55:34 by samoore           #+#    #+#             */
/*   Updated: 2023/11/27 16:39:11 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	static int	len = 0;
	char		x;
	int			tmp;

	x = (unsigned char)c;
	if (c < 0)
	{
		tmp = len;
		len = 0;
		return (tmp);
	}
	write(1, &x, 1);
	len++;
	return (0);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar((unsigned char)s[i]);
		i++;
	}
}

void	ft_putstr_len(char *s, int len)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
	{
		ft_putchar((unsigned char)s[i]);
		i++;
	}
}

void	ft_putnum(unsigned int n)
{
	if (n == 0)
		return ;
	ft_putnum(n / 10);
	ft_putchar (n % 10 + '0');
}

void	ft_puthex(unsigned long long int n, char c)
{
	if (n == 0)
		return ;
	ft_puthex(n / 16, c);
	if ((n % 16) < 10)
		ft_putchar((n % 16) + '0');
	else
	{
		if (c == 'x')
			ft_putchar((n % 16) + ('a' - 10));
		else
			ft_putchar(n % 16 + ('A' - 10));
	}
}
