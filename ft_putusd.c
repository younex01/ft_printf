/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:18:57 by yelousse          #+#    #+#             */
/*   Updated: 2022/01/15 15:50:19 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putusd(unsigned int n)
{
	char	c;
	long	nb;
    int len;

    len =0;
	nb = n;
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