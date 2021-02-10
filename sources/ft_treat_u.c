/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:41:47 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/10 14:41:51 by gefaivre         ###   ########.fr       */
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



void	ft_first_treat_u(unsigned int nb, t_struct *spf)
{
	if ((spf->num1 && spf->num2 && spf->minus) || (spf->num1 && spf->num2 > -1
	&& spf->minus && spf->wildcard))
		ft_treat_i_return(nb, spf);
	else
		ft_treat_i(nb, spf);
}

void	ft_treat_u_return(unsigned int nb, t_struct *spf)
{
	char	*str;
	int		size;
	int		max_size_or_num2;

	str = ft_itoa_u(nb);
	size = ft_strlen(str);
	max_size_or_num2 = ft_max(size, spf->num2);
	while (spf->num2 > size || (spf->point_1 && spf->num1 > size))
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
	while (spf->num1 > (max_size_or_num2))
	{
		ft_putchar_fd(' ', 1);
		spf->print_count++;
		spf->num1--;
	}
}

void ft_space_u_1(t_struct *spf,unsigned int nb)
{
	if ((spf->zero == 1 && spf->num1 == 0 && nb == 0) || (spf->zero == 1
		&& spf->wildcard && spf->point_2 && spf->num1 > 0 && spf->num2 == -1))
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

void ft_space_u_2(t_struct *spf,unsigned int nb)
{
	if (spf->point_2 == 1 && spf->num2 == 0 && nb == 0)
		ft_put_char_count('0', spf);
	else if (spf->point_2 == 1 && spf->num2 == 0 && nb == 0)
		ft_put_char_count(' ', spf);
	else if (spf->point_2 || spf->zero)
		ft_put_char_count('0', spf);
	else
		ft_put_char_count(' ', spf);
	spf->num2--;
}

int ft_u_if_1(t_struct *spf, unsigned int nb, int size)
{
	return (((spf->minus && spf->num1 > size) && !(spf->point_2 == 1 && spf->num2
	&& nb == 0)) || (spf->wildcard && ((spf->point_1 && spf->num1 < 0)
	|| (spf->point_2 && spf->num1 < 2)) && spf->num2 != 0 && nb == 0));
}

void	ft_treat_u(unsigned int nb, t_struct *spf)
{
	char	*str;
	int		size;
	int		max_size_or_num2;
	int		printminus;

	size = 0;
	printminus = 0;
	if (nb < 0 && (spf->point_1 || spf->zero || spf->point_2 || spf->zero))
		ft_ifisneg_u(&nb, spf);
	str = ft_itoa_u(nb);
	size = ft_strlen(str);
	max_size_or_num2 = ft_max(size, spf->num2);
	while (spf->num1 > (int)(max_size_or_num2 + spf->nbisneg))
		ft_space_u_1(spf, nb);
	if (ft_u_if_1(spf, nb, size))
	{
		spf->i = ft_printfstr(str, spf->i, spf);
		spf->allprint = 1;
	}
	if (spf->nbisneg && printminus == 0)
	{
		ft_put_char_count('-', spf);
		printminus = 1;
		max_size_or_num2--;
	}
	while (spf->num2 > size)
		ft_space_u_2(spf, nb);
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
