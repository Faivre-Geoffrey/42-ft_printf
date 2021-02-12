/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_i_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 08:33:37 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/12 10:31:35 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_if_i_return(t_struct *spf, int nb)
{
	return (!((((spf->point_1 == 1 && spf->num1 < 0) || (spf->point_2 == 1
	&& spf->num2 < 0 && spf->wildcard == 0)) || (spf->point_2 && spf->wildcard
	&& spf->num2 == 0)) && nb == 0) || (spf->point_1 && spf->num1 < 0
	&& spf->num2 < 0 && spf->wildcard));
}

int		ft_if_i(t_struct *spf, int nb)
{
	return (((spf->nbisneg && spf->point_1 && spf->zero == 0
	&& spf->printminus == 0) || (spf->nbisneg && spf->point_2 == 0 && spf->zero
	&& spf->printminus == 0) || (spf->nbisneg && spf->point_2 && spf->zero
	&& spf->num2 < 0 && spf->printminus == 0)) && nb != -2147483648);
}

int		ft_if_i_2(t_struct *spf, int nb)
{
	return ((((spf->minus && spf->num1 > spf->size) && !(spf->point_2
	&& spf->num2 && nb == 0)) || (spf->point_1 && spf->num1 < 0
	&& spf->num2 < 0 && spf->wildcard) || (spf->point_2 && spf->num1 > -1
	&& spf->num2 != 0 && spf->wildcard)) && !(spf->point_2 && spf->num1 < 1
	&& spf->num2 < 0 && spf->wildcard && spf->nbisneg) && !(spf->point_2
	&& spf->num1 > -1 && spf->num2 != 0 && spf->wildcard && spf->nbisneg)
	&& !(spf->point_2 && spf->num1 > -1 && spf->num2 > 0 && spf->wildcard
	&& spf->nbisneg == 0 && nb != 0));
}

void	ft_space_i_1(t_struct *spf)
{
	if ((spf->zero || spf->point_1) && spf->num2 < 0)
		ft_put_char_count('0', spf);
	else
		ft_put_char_count(' ', spf);
	spf->num1--;
}

void	ft_space_i_2(t_struct *spf)
{
	if (spf->point_2 || spf->zero)
		ft_put_char_count('0', spf);
	else
		ft_put_char_count(' ', spf);
	spf->num2--;
}
