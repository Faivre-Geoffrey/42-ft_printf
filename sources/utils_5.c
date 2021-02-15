/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:33:33 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/15 11:04:03 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_set_struct(t_struct *spf)
{
	spf->type = 'a';
	spf->minus = 0;
	spf->zero = 0;
	spf->point_1 = 0;
	spf->point_2 = 0;
	spf->wildcard = 0;
	spf->num1 = -1;
	spf->num2 = -1;
	spf->nbisneg = 0;
	spf->allprint = 0;
	spf->printminus = 0;
	spf->i = 0;
	spf->u = 0;
	spf->nb = 0;
	spf->size = 0;
}

void	ft_makeflags1(va_list args, t_struct *spf, char c, int first_time[0])
{
	if (c == '-')
		spf->minus = 1;
	if (c == '0')
		spf->zero = 1;
	if (c == '.')
		spf->point_1 = 1;
	if (c == '*')
	{
		spf->num1 = va_arg(args, int);
		spf->wildcard = 1;
		first_time[0] = 1;
	}
}

void	ft_makeflags2(va_list args, t_struct *spf, char c, int first_time[1])
{
	if (c == '-')
		spf->minus = 1;
	if (c == '0')
		spf->zero = 1;
	if (c == '.')
		spf->point_2 = 1;
	if (c == '*')
	{
		spf->num2 = va_arg(args, int);
		spf->wildcard = 1;
		first_time[1] = 1;
	}
}

int		ft_strzero(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[0] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int		ft_atoi_pf(const char *str, int *x)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	*x += (int)i;
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}
