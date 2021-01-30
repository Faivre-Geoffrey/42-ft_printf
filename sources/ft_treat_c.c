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

void ft_treat_c(char c, t_struct *struct_pf)
{
	/*char *preprint;*/

	while (struct_pf->num1 > 1)
	{
		ft_putchar_fd(' ', 1);
		struct_pf->num1--;
	}
	ft_putchar_fd(c, 1);
	struct_pf->print_count++;
}
