/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_to_args_type.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:38:33 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/15 11:28:04 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_redirect_to_args_type(va_list args, t_struct *spf)
{
	if (spf->type == 'p')
		ft_first_treat_p(va_arg(args, unsigned long), spf);
	if (spf->type == '%')
	{
		if (spf->num1 && spf->num2 && spf->minus)
			ft_treat_per_return(spf);
		else
			ft_treat_per(spf);
	}
	if (spf->type == 'c')
		ft_first_treat_c(va_arg(args, int),spf);
	if (spf->type == 's')
		ft_first_treat_s(va_arg(args, char*), spf);
	if (spf->type == 'i' || spf->type == 'd')
		ft_first_treat_i(va_arg(args, int), spf);
	if (spf->type == 'u')
		ft_first_treat_u(va_arg(args, unsigned int), spf);
	if (spf->type == 'x')
		ft_first_treat_x(va_arg(args, unsigned int), spf);
	if (spf->type == 'X')
		ft_first_treat_xup(va_arg(args, unsigned int), spf);
}
