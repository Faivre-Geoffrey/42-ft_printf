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

void	ft_treat_c_return(char c, t_struct *struct_pf)
{
	int max_size_or_num2;

	max_size_or_num2 = ft_max(1, struct_pf->num2);
	if (!(struct_pf->point_2 == 1 && struct_pf->num2 == -1 ))
	{
		ft_putchar_fd(c,1);
		struct_pf->print_count++;
	}
	while (struct_pf->num1 > (max_size_or_num2  + struct_pf->nbisneg))
	{
		ft_putchar_fd(' ',1);
		struct_pf->print_count++;
		struct_pf->num1--;
	}
}

void	ft_treat_c(char c, t_struct *struct_pf)
{
	int max_size_or_num2;


	max_size_or_num2 = ft_max(1, struct_pf->num2);
	while (struct_pf->num1 > (max_size_or_num2  + struct_pf->nbisneg))
		ft_space(struct_pf);
	if (!((struct_pf->point_1 || struct_pf->point_2) && (struct_pf->num2 == 0 || struct_pf->num1 == 0)))
	{
		ft_putchar_fd(c,1);
		struct_pf->print_count++;
	}
}
