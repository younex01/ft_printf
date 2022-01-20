/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:57:05 by yelousse          #+#    #+#             */
/*   Updated: 2022/01/19 23:29:31 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sharp(const char *s, int *i, unsigned int nbr)
{
	*i += 1;
	if (nbr == 0)
		return (ft_putchar('0'));
	return (ft_putchar('0') + ft_putchar(s[*i]) + ft_puthex(nbr, s[*i]));
}

int	ft_strlen(char *str)
{
	if (!(*str))
		return (0);
	return (1 + ft_strlen(str + 1));
}

int	count(const char *s, int *i)
{
	int	total;

	total = 0;
	while (s[*i] >= '0' && s[*i] < '9')
	{
		total *= 10;
		total += s[*i] - '0';
		*i += 1;
	}
	return (total);
}

int	ft_wigth(char *str, int n)
{
	int	len;
	int	total;

	total = 0;
	len = ft_strlen(str);
	while (total + len < n)
		total += ft_putchar(' ');
	return (total + ft_putstr(str));
}
