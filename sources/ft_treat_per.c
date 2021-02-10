/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:44:41 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/10 09:04:46 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_treat_per_return(t_struct *spf)
{
	int max_size_or_num2;

	max_size_or_num2 = ft_max(1, spf->num2);
	if (!(spf->point_2 == 1 && spf->num2 == -1))
	{
		ft_putchar_fd('%', 1);
		spf->print_count++;
	}
	while (spf->num1 > (max_size_or_num2 + spf->nbisneg))
	{
		ft_putchar_fd(' ', 1);
		spf->print_count++;
		spf->num1--;
	}
}

void	ft_treat_per(t_struct *spf)
{
	int max_size_or_num2;

	max_size_or_num2 = ft_max(1, spf->num2);
	while (spf->num1 > (max_size_or_num2 + spf->nbisneg))
	{
		if (spf->point_1 || spf->zero)
			ft_put_char_count('0', spf);
		else
			ft_put_char_count(' ', spf);
		spf->num1--;
	}
	if (!((spf->point_1 || spf->point_2) && (spf->num2 == 0 || spf->num1 == 0)))
	{
		ft_put_char_count('%', spf);
	}
}
