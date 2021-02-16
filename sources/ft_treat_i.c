/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:41:47 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/12 10:31:18 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_first_treat_i(int nb, t_struct *spf)
{
	char *str;

	if (nb < 0)
		ft_ifisneg(&nb, spf);
	str = ft_itoa(nb);
	spf->size = ft_strlen(str);
	spf->m_m[1] = ft_max(spf->size, spf->num2);
	if ((spf->num1 && spf->num2 && spf->minus) || (spf->num1
	&& spf->num2 > -1 && spf->minus && spf->wildcard))
		ft_treat_i_return(nb, spf, str);
	else
		ft_treat_i(nb, spf, str);
}

void	ft_treat_i_return(int nb, t_struct *spf, char *str)
{
	if (spf->nbisneg && nb != -2147483648)
		ft_put_char_count('-', spf);
	while (spf->num2 > spf->size || (spf->num1 > spf->size && spf->point_1
	&& spf->minus && spf->num2 < 0))
	{
		if (spf->point_2 > 0 || spf->zero > 0 || (spf->num1 && spf->point_1
		&& spf->minus && spf->num2 < 0))
			ft_put_char_count('0', spf);
		else
			ft_put_char_count(' ', spf);
		if (spf->point_1 == 1)
			spf->num1--;
		else
			spf->num2--;
	}
	if (ft_if_i_return(spf, nb))
		spf->i = ft_printfstr(str, spf->i, spf);
	else if (!(spf->point_1 && nb == 0 && spf->num1 < 0))
		ft_put_char_count(' ', spf);
	while (spf->num1 > (spf->m_m[1] + spf->nbisneg))
	{
		ft_put_char_count(' ', spf);
		spf->num1--;
	}
	free(str);
}

void	ft_treat_i_2(int nb, t_struct *spf, char *str)
{
	if (spf->nbisneg && spf->printminus == 0 && nb != -2147483648)
	{
		ft_put_char_count('-', spf);
		spf->printminus = 1;
		spf->m_m[1]--;
	}
	while (spf->num2 > spf->size)
		ft_space_i_2(spf);
	if (spf->point_1 == 1 && spf->num1 == -1 && nb == 0)
		return ;
	if (spf->point_2 == 1 && spf->num2 == -1 && nb == 0 && !(spf->wildcard))
		ft_put_char_count(' ', spf);
	if (spf->allprint == 0 && !(nb == 0 && (spf->point_1 || spf->point_2)
	&& (spf->num2 == 0 || spf->num1 == 0)) && !(spf->point_2 == 1
	&& spf->num2 == -1 && nb == 0 && !(spf->wildcard)))
		spf->i = ft_printfstr(str, spf->i, spf);
	else if (spf->allprint == 0 && ((nb == 0 && spf->point_2 && spf->num1 > 0)
	|| (spf->point_2 == 1 && spf->num1 == -1 && spf->wildcard == 1))
	&& !(spf->point_2 == 1 && spf->num2 == -1 && nb == 0 && !(spf->wildcard)))
		ft_put_char_count(' ', spf);
	free(str);
}

void	ft_treat_i(int nb, t_struct *spf, char *str)
{
	if (spf->nbisneg && spf->point_1 && spf->num2 == -1 && spf->printminus == 0
	&& nb != -2147483648)
	{
		ft_put_char_count('-', spf);
		spf->printminus = 1;
		spf->num1++;
	}
	if (ft_if_i(spf, nb))
	{
		ft_put_char_count('-', spf);
		spf->printminus = 1;
		spf->size++;
	}
	while (spf->num1 > (spf->m_m[1] + spf->nbisneg))
		ft_space_i_1(spf);
	if (ft_if_i_2(spf, nb))
	{
		spf->i = ft_printfstr(str, spf->i, spf);
		spf->allprint = 1;
	}
	ft_treat_i_2(nb, spf, str);
}
