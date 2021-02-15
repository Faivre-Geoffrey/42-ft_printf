/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 08:22:10 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/15 10:34:18 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
