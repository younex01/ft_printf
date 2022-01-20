/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelousse <yelousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:05:44 by yelousse          #+#    #+#             */
/*   Updated: 2022/01/15 15:43:05 by yelousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if(!s)
		return (ft_putstr("(null)"));
	i = 0;
    while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
    return (i);
}