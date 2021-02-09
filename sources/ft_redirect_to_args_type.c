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

void	ft_redirect_to_args_type(va_list args, t_struct *spf)
{
 	if (spf->type == 'p')
	{
		if (spf->num1 && spf->num2 && spf->minus)
			ft_treat_p_return(va_arg(args, unsigned long long), spf);
		else 
			ft_treat_p(va_arg(args, unsigned long long), spf);
	}
	if (spf->type == '%')
	{
		if (spf->num1 && spf->num2 && spf->minus)
			ft_treat_per_return(spf);
		else
			ft_treat_per(spf);
	}
	if (spf->type == 'c')
	{
		if (spf->num1 && spf->num2 && spf->minus)
			ft_treat_c_return(va_arg(args, int),spf);
		else
			ft_treat_c(va_arg(args, int), spf);
	}
	if (spf->type == 's')
	{

		if (spf->num1 && spf->num2 && spf->minus)
			ft_treat_s_return(va_arg(args, char*), spf);
		else 
			ft_treat_s(va_arg(args, char*), spf);
	}
	if (spf->type == 'i' || spf->type == 'd')
	{
		if ((spf->num1 && spf->num2 && spf->minus) || (spf->num1 && spf->num2 > -1 && spf->minus && spf->wildcard))
			ft_treat_i_return(va_arg(args, int), spf);
		else
			ft_treat_i(va_arg(args,int), spf);
	}
	if (spf->type == 'u')
	{
		if ((spf->num1 && spf->num2 && spf->minus) || (spf->num1 && spf->num2 > -1 && spf->minus && spf->wildcard))
			ft_treat_u_return(va_arg(args, unsigned int), spf);
		else
			ft_treat_u(va_arg(args, unsigned int), spf);
	}
	if (spf->type == 'x')
	{
		if ((spf->num1 && spf->num2 && spf->minus) || (spf->num1 && spf->num2 > -1 && spf->minus && spf->wildcard))
			ft_treat_x_return(va_arg(args, unsigned int), spf);
		else
			ft_treat_x(va_arg(args, unsigned int), spf);
	}
	if (spf->type == 'X')
	{
		if ((spf->num1 && spf->num2 && spf->minus) || (spf->num1 && spf->num2 > -1 && spf->minus && spf->wildcard))
			ft_treat_X_return(va_arg(args, unsigned int), spf);
		else
			ft_treat_X(va_arg(args, unsigned int), spf);
	}
}
