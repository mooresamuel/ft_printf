/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <samoore@student.42london.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:54:06 by samoore           #+#    #+#             */
/*   Updated: 2023/11/28 14:50:00 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar((unsigned char)s[i]);
		else
			process(s, &i, ap);
		i++;
	}	
	va_end(ap);
	return (ft_putchar(-1));
}
