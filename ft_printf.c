/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 08:22:10 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/14 11:25:51 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_make_args_make_num(t_struct *spf)
{
	if (spf->num1 < -1)
	{
		spf->num1 *= -1;
		spf->minus = 1;
		if (spf->point_1)
			spf->num1 = -1;
	}
	if (spf->num2 < -1)
	{
		spf->num2 = -1;
		spf->point_2 = 0;
	}
}

void	ft_set_first_time_to_zero(int first_time[2])
{
	first_time[0] = 0;
	first_time[1] = 0;
}

int		ft_make_args(va_list args, char *s, t_struct *spf)
{
	int i;
	int j;
	int g;
	int first_time[2];

	i = 1;
	j = 0;
	g = 0;
	ft_set_first_time_to_zero(first_time);
	while (ft_isflags(s[i]) && !(s[i] == '0' && s[i - 1] == '.') && s[i] != '*')
		ft_makeflags1(args, spf, s[i++], first_time);
	if (s[i] == '*')
		ft_makeflags1(args, spf, s[i++], first_time);
	if (ft_isdigit(s[i]) && first_time[0] == 0)
		spf->num1 = ft_atoi_pf(s + i, &i);
	while (ft_isflags(s[i]) && !(s[i] == '0' && s[i - 1] == '.') && s[i] != '*')
		ft_makeflags2(args, spf, s[i++], first_time);
	if (s[i] == '*')
		ft_makeflags2(args, spf, s[i++], first_time);
	if (ft_isdigit(s[i]) && first_time[1] == 0)
		spf->num2 = ft_atoi_pf(s + i, &i);
	ft_make_args_make_num(spf);
	if ((spf->type = s[i]) && (ft_istype(s[i])))
		return (++i);
	return (1);
}

void	ft_treat_str(char *str, va_list args, t_struct *spf)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && (i += ft_make_args(args, str + i, spf)))
		{
			ft_redirect_to_args_type(args, spf);
			ft_set_struct(spf);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			spf->print_count++;
			i++;
		}
	}
}

int		ft_printf(const char *input, ...)
{
	t_struct	spf;
	char		*str;
	va_list		args;

	ft_set_struct(&spf);
	spf.print_count = 0;
	str = ft_strdup(input);
	va_start(args, input);
	ft_treat_str(str, args, &spf);
	va_end(args);
	free((char *)str);
	return (spf.print_count);
}
