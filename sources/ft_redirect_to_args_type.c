/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_to_args_type.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:38:33 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/01 13:38:33 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_redirect_to_args_type(va_list args, t_struct *struct_pf)
{
 	if (struct_pf->type == 'p')
	{
		if (struct_pf->num1 && struct_pf->num2 && struct_pf->minus)
			ft_treat_p_return(va_arg(args, unsigned long long), struct_pf);
		else 
			ft_treat_p(va_arg(args, unsigned long long), struct_pf);
	}
	if (struct_pf->type == '%')
	{
		if (struct_pf->num1 && struct_pf->num2 && struct_pf->minus)
			ft_treat_per_return(struct_pf);
		else
			ft_treat_per(struct_pf);
	}
	if (struct_pf->type == 'c')
	{
		if (struct_pf->num1 && struct_pf->num2 && struct_pf->minus)
			ft_treat_c_return(va_arg(args, int),struct_pf);
		else
			ft_treat_c(va_arg(args, int), struct_pf);
	}
	if (struct_pf->type == 's')
	{

		if (struct_pf->num1 && struct_pf->num2 && struct_pf->minus)
			ft_treat_s_return(va_arg(args, char*), struct_pf);
		else 
			ft_treat_s(va_arg(args, char*), struct_pf);
	}
	if (struct_pf->type == 'i' || struct_pf->type == 'd')
	{
		if ((struct_pf->num1 && struct_pf->num2 && struct_pf->minus) || (struct_pf->num1 && struct_pf->num2 > -1 && struct_pf->minus && struct_pf->wildcard))
			ft_treat_i_return(va_arg(args, int), struct_pf);
		else
			ft_treat_i(va_arg(args,int), struct_pf);
	}
	if (struct_pf->type == 'u')
	{
		if ((struct_pf->num1 && struct_pf->num2 && struct_pf->minus) || (struct_pf->num1 && struct_pf->num2 > -1 && struct_pf->minus && struct_pf->wildcard))
			ft_treat_u_return(va_arg(args, unsigned int), struct_pf);
		else
			ft_treat_u(va_arg(args, unsigned int), struct_pf);
	}
	if (struct_pf->type == 'x')
	{
		if ((struct_pf->num1 && struct_pf->num2 && struct_pf->minus) || (struct_pf->num1 && struct_pf->num2 > -1 && struct_pf->minus && struct_pf->wildcard))
			ft_treat_x_return(va_arg(args, unsigned int), struct_pf);
		else
			ft_treat_x(va_arg(args, unsigned int), struct_pf);
	}
	if (struct_pf->type == 'X')
	{
		if ((struct_pf->num1 && struct_pf->num2 && struct_pf->minus) || (struct_pf->num1 && struct_pf->num2 > -1 && struct_pf->minus && struct_pf->wildcard))
			ft_treat_X_return(va_arg(args, unsigned int), struct_pf);
		else
			ft_treat_X(va_arg(args, unsigned int), struct_pf);
	}
}
