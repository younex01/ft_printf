/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:03:40 by yelousse          #+#    #+#             */
/*   Updated: 2022/01/19 23:29:54 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr(int n);
int	ft_puthex(unsigned int no, char ch);
int	ft_putadr(unsigned long n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putusd(unsigned int n);
int	ft_printf(const char *s, ...);
int	ft_sharp(const char *s, int *i, unsigned int nbr);
int	ft_strlen(char *str);
int	count(const char *s, int *i);
int	ft_wigth(char *str, int n);

#endif