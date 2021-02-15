/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:41:47 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/15 10:52:19 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_first_treat_u(unsigned int nb, t_struct *spf)
{
	char *str;

	str = ft_itoa_u(nb);
	spf->size = ft_strlen(str);
	spf->m_m[1] = ft_max(spf->size, spf->num2);
	if (nb < 0 && (spf->point_1 || spf->zero || spf->point_2 || spf->zero)
	&& !((spf->num1 && spf->num2 && spf->minus) || (spf->num1 && spf->num2 > -1
	&& spf->minus && spf->wildcard)))
		ft_ifisneg_u(&nb, spf);
	if ((spf->num1 && spf->num2 && spf->minus) || (spf->num1 && spf->num2 > -1
	&& spf->minus && spf->wildcard))
		ft_treat_i_return(nb, spf, str);
	else
		ft_treat_i(nb, spf, str);
}

void	ft_treat_u_return(unsigned int nb, t_struct *spf, char *str)
{
	while (spf->num2 > spf->size || (spf->point_1 && spf->num1 > spf->size))
		ft_space_u_return(spf);
	if (!((((spf->point_1 == 1 && spf->num1 < 0)
		|| (spf->point_2 == 1 && spf->num2 < 0 && spf->wildcard == 0))
		|| (spf->point_2 && spf->wildcard && spf->num2 == 0)) && nb == 0)
		|| (spf->point_1 && spf->num1 < 0 && spf->num2 < 0 && spf->wildcard))
		ft_printfstr(str, 0, spf);
	else if (!(spf->point_1 && nb == 0 && spf->num1 < 0))
	{
		ft_putchar_fd(' ', 1);
		spf->print_count++;
	}
	while (spf->num1 > (spf->m_m[1]))
	{
		ft_putchar_fd(' ', 1);
		spf->print_count++;
		spf->num1--;
	}
}

int		ft_u_if_1(t_struct *spf, unsigned int nb, int size)
{
	return (((spf->minus && spf->num1 > size)
	&& !(spf->point_2 == 1 && spf->num2
	&& nb == 0)) || (spf->wildcard && ((spf->point_1 && spf->num1 < 0)
	|| (spf->point_2 && spf->num1 < 2)) && spf->num2 != 0 && nb == 0));
}

void	ft_treat_u_2(unsigned int nb, t_struct *spf, char *str)
{
	if (spf->point_1 == 1 && spf->num1 == -1 && nb == 0)
		return ;
	if (spf->point_2 == 1 && spf->num2 == -1 && nb == 0 && !spf->allprint)
	{
		ft_put_char_count(' ', spf);
		return ;
	}
	if (spf->allprint == 0 && !(nb == 0 && (spf->point_1 || spf->point_2)
	&& (spf->num2 == 0 || spf->num1 == 0)))
		spf->i = ft_printfstr(str, spf->i, spf);
	else if (nb == 0 && spf->point_2 && spf->num1 && !spf->allprint)
		ft_put_char_count(' ', spf);
}

void	ft_treat_u(unsigned int nb, t_struct *spf, char *str)
{
	while (spf->num1 > (int)(spf->m_m[1] + spf->nbisneg))
		ft_space_u_1(spf, nb);
	if (ft_u_if_1(spf, nb, spf->size))
	{
		spf->i = ft_printfstr(str, spf->i, spf);
		spf->allprint = 1;
	}
	if (spf->nbisneg)
	{
		ft_put_char_count('-', spf);
		spf->m_m[1]--;
	}
	while (spf->num2 > spf->size)
		ft_space_u_2(spf, nb);
	ft_treat_u_2(nb, spf, str);
}
