/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:44:41 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/01 13:44:41 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_treat_c_return(char c, t_struct *spf)
{
	int max_size_or_num2;

	max_size_or_num2 = ft_max(1, spf->num2);
	if (!(spf->point_2 == 1 && spf->num2 == -1))
	{
		ft_putchar_fd(c, 1);
		spf->print_count++;
	}
	while (spf->num1 > (max_size_or_num2 + spf->nbisneg))
	{
		ft_putchar_fd(' ', 1);
		spf->print_count++;
		spf->num1--;
	}
}

void	ft_treat_c(char c, t_struct *spf)
{
	int max_size_or_num2;

	max_size_or_num2 = ft_max(1, spf->num2);
	while (spf->num1 > (max_size_or_num2 + spf->nbisneg))
		ft_space(spf);
	if (!((spf->point_1 || spf->point_2) && (spf->num2 == 0 || spf->num1 == 0)))
	{
		ft_putchar_fd(c, 1);
		spf->print_count++;
	}
}
