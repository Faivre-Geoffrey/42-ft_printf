/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 08:39:25 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/12 08:40:24 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_space_u_return(t_struct *spf)
{
	if (spf->point_2 > 0 || spf->zero > 0 || spf->point_1 > 0)
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
	spf->print_count++;
	if (spf->point_1)
		spf->num1--;
	else
		spf->num2--;
}
