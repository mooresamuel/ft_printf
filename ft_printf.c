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

// #include <limits.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int a = printf("%c%c%c%c œ %c%c\n", -1278, -1, 0, 1, 255, 1234);
// 	int b = ft_printf("%c%c%c%c œ %c%c\n", -1278, -1, 0, 1, 255, 1234);
// 	printf("%d %d\n", a, b);
// }
