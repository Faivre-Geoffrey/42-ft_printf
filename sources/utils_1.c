/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:29:28 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/12 10:54:07 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
	c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int		ft_isflags(char c)
{
	return (c == '-' || c == '0' || c == '.' || c == '*');
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	int x;

	if (a < b)
		x = a;
	else
		x = b;
	if (x < 0)
		x = 0;
	return (x);
}

void	ft_ifisneg(int *nb, t_struct *spf)
{
	*nb *= -1;
	spf->nbisneg = 1;
}
