/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:43:22 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/10 11:08:57 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_first_treat_s(char *str, t_struct *spf)
{
	int size;
	int m_m[2];

	if (!str)
		str = "(null)";
	size = ft_strlen(str);
	m_m[0] = ft_min(size, spf->num2);
	m_m[1] = ft_max(size, spf->num2);
	if (spf->num1 && spf->num2 && spf->minus)
		ft_treat_s_return(str, spf, m_m, size);
	else
		ft_treat_s(str, spf, m_m, size);
}

void	ft_s_print_str(t_struct *spf, char *str)
{
	if (spf->nbisneg == 0)
	{
		ft_put_char_count(str[spf->i], spf);
		if (spf->point_1 && spf->num1 > 0)
			spf->num1--;
		spf->i++;
		if (!(str[spf->i]) || spf->num1 == 0)
			spf->allprint = 1;
	}
	else
	{
		ft_put_char_count(str[spf->i], spf);
		if (spf->point_1 && spf->num1 > 0)
			spf->num1--;
		spf->i++;
		if (!(str[spf->i]) || spf->i == spf->num2)
			spf->allprint = 1;
	}
}

void	ft_treat_s_return(char *str, t_struct *spf, int m_m[2], int size)
{
	while (size != 0 && str[spf->i] &&
		((spf->point_2 && ((spf->num2 && spf->i < spf->num2)))
		|| (spf->point_2 && spf->wildcard && spf->num2 < 0 && spf->num1)))
	{
		ft_putchar_fd(str[spf->i], 1);
		spf->i++;
		spf->print_count++;
	}
	if (((!(spf->point_2 && spf->num1 >= 0)) && size != 0) && !(spf->wildcard &&
	spf->num1 == -1 && (spf->num2 == 0 || spf->i <= spf->num2)))
		spf->i = ft_printfstr(str, spf->i, spf);
	while ((spf->num1 > (m_m[0]) && spf->point_2 && !(spf->point_1
	&& size == 0)) && !(spf->wildcard && spf->num1 && spf->num2 < 0)
	&& !((spf->point_1 == 1 && spf->minus)))
		ft_space(spf);
	while (spf->num1 > (m_m[1]) && !(spf->point_1 && size == 0)
	&& !((spf->point_1 == 1 && spf->minus)))
		ft_space(spf);
}

void	ft_treat_s(char *str, t_struct *spf, int m_m[2], int size)
{
	if (spf->point_1 && spf->num1 == 0)
		return ;
	if (spf->point_1 == 1 && spf->num1 == -1 && !spf->wildcard)
		spf->allprint = 1;
	while (spf->point_1 && spf->num1 > 0 && str[spf->i]
	&& spf->allprint == 0)
		ft_s_print_str(spf, str);
	while ((spf->num1 > m_m[0]) && spf->point_2
	&& !(spf->wildcard && spf->u == 0 && spf->num2 == -1))
		ft_space(spf);
	while (spf->num1 > (m_m[1]) && !(spf->point_1))
		ft_space(spf);
	spf->nbisneg = 1;
	while (spf->point_2 && ((spf->wildcard && spf->num2 == -1)
	|| spf->i < spf->num2) && spf->allprint == 0 && size != 0)
		ft_s_print_str(spf, str);
	if ((spf->allprint == 0 && !(spf->point_2 && spf->num1 >= 0))
	&& !(spf->num1 == -1 && (spf->num2 == 0)))
		spf->i = ft_printfstr(str, spf->i, spf);
	else if (spf->wildcard && spf->num1 == -1 && (spf->num2 == 0))
		ft_put_char_count(' ', spf);
}
