/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:03:46 by yelousse          #+#    #+#             */
/*   Updated: 2022/01/19 23:35:38 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	instr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	nor_flag(char c, va_list ptr)
{
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(ptr, int)));
	if (c == 'c')
		return (ft_putchar(va_arg(ptr, unsigned int)));
	if (c == 's')
		return (ft_putstr(va_arg(ptr, void *)));
	if (c == 'u')
		return (ft_putusd(va_arg(ptr, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ptr, unsigned long), c));
	if (c == 'p')
		return (ft_putadr(va_arg(ptr, unsigned long)));
	return (ft_putchar('%'));
}

static int	flag_bonus(const char *s, int *i, va_list ptr)
{
	char	c;
	int		num;

	c = s[*i];
	while (s[*i + 1] == c)
		*i += 1;
	if (c == '#')
		return (ft_sharp(s, i, va_arg(ptr, unsigned int)));
	*i += 1;
	if (s[*i] == 'i' || s[*i] == 'd')
	{
		num = va_arg(ptr, int);
		if (num >= 0)
			return (ft_putchar(c) + ft_putnbr(num));
		return (ft_putnbr(num));
	}
	num = count(s, i);
	if (s[*i] == 's' && c == ' ')
		return (ft_wigth(va_arg(ptr, void *), num));
	return (0);
}

static int	flag(const char *s, int *i, va_list ptr)
{
	if (instr("cspdiuxX%", s[*i]))
		return (nor_flag(s[*i], ptr));
	return (flag_bonus(s, i, ptr));
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	va_start(ptr, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += flag(s, &i, ptr);
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(ptr);
	return (len);
}
