/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:13:28 by yelousse          #+#    #+#             */
/*   Updated: 2022/01/15 14:55:38 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	long	nb;
    int len;

    len =0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
        len++;
	}
	if (nb <= 9)
	{
		c = nb + 48;
		len += ft_putchar(c);
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		c = (nb % 10) + 48;
		len += ft_putchar(c);
	}
    return (len);
}