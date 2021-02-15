/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_xup_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:25:48 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/15 10:32:48 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_space_xup_return(t_struct *spf)
{
	if (spf->point_2 > 0 || spf->zero > 0)
		ft_put_char_count('0', spf);
	else
		ft_put_char_count(' ', spf);
	spf->num2--;
}

void	ft_space_xup_1(t_struct *spf, unsigned int nb)
{
	if ((spf->zero == 1 && spf->num1 == 0 && nb == 0)
	|| (spf->zero == 1 && spf->wildcard && spf->point_2 && spf->num1 > 0
	&& spf->num2 == -1))
		ft_put_char_count('0', spf);
	else if (spf->point_1 == 1 && spf->num1 == 0 && nb == 0)
		ft_put_char_count(' ', spf);
	else if (spf->point_2 == 1 && spf->zero)
		ft_put_char_count(' ', spf);
	else if (spf->point_1 || spf->zero)
		ft_put_char_count('0', spf);
	else
		ft_put_char_count(' ', spf);
	spf->num1--;
}

void	ft_space_xup_2(t_struct *spf, unsigned int nb)
{
	if (spf->point_2 == 1 && spf->num2 == 0 && spf && nb == 0)
		ft_put_char_count('0', spf);
	else if (spf->point_2 == 1 && spf->num2 == 0 && nb == 0)
		ft_put_char_count(' ', spf);
	else if (spf->point_2 || spf->zero)
		ft_put_char_count('0', spf);
	else
		ft_put_char_count(' ', spf);
	spf->num2--;
}
