/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:50:51 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/12 10:55:19 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_space(t_struct *spf)
{
	if ((spf->point_1 || spf->zero)
	&& !(spf->zero == 1 && spf->minus == 1))
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
	spf->print_count++;
	spf->num1--;
}
