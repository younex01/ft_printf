/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:17:26 by yelousse          #+#    #+#             */
/*   Updated: 2022/01/15 16:21:16 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int no, char ch)
{
	int			hex;
	int	len = 0;
	char		c;

	hex = no;
	if (no >= 16)
	{  
		hex = no % 16;
		len += ft_puthex(no / 16, ch);
	}
	if (hex > 9)
	{
		c = 'a' + (hex - 10);
		if (ch == 'X')
			c = 'A' + (hex - 10);
		len += ft_putchar(c);
	}
	else
		len += ft_putchar(hex + 48);
	return (len);
}
