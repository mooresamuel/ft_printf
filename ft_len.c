/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:38:34 by samoore           #+#    #+#             */
/*   Updated: 2023/11/27 16:38:55 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_numlen(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10 > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_hexlen(unsigned long long int n)
{
	int	i;

	i = 1;
	while (n / 16 > 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}
