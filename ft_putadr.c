/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:17:46 by yelousse          #+#    #+#             */
/*   Updated: 2022/01/15 16:25:29 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_puthexa(unsigned long no, char ch)
{
	int			hex;
	int	len = 0;
	char		c;

	hex = no;
	if (no >= 16)
	{  
		hex = no % 16;
		len += ft_puthexa(no / 16, ch);
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

int	ft_putadr(unsigned long n)
{
	return (ft_putstr("0x") + ft_puthexa(n , 'x'));	
}
