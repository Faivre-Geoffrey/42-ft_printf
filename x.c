/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:41:47 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/11 15:07:42 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		check_base_123(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_u(unsigned int nbr, char *base, t_struct *spf)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	if (check_base_123(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar_fd('-', 1);
		}
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			ft_put_char_count(base[nbr_final[i]], spf);
	}
}

void	ft_space_x_return(t_struct *spf)
{
	if (spf->point_2 > 0 || spf->zero > 0)
		ft_put_char_count('0', spf);
	else
		ft_put_char_count(' ', spf);
	spf->num2--;
}

void	ft_first_treat_x(unsigned int nb, t_struct *spf)
{
	if ((spf->num1 && spf->num2 && spf->minus)
	|| (spf->num1 && spf->num2 > -1 && spf->minus && spf->wildcard))
		ft_treat_x_return(nb, spf);
	else
		ft_treat_x(nb, spf);
}

void	ft_treat_x_return(unsigned int nb, t_struct *spf)
{
	spf->size = ft_len_base(nb, "0123456789abcdef");
	if (nb == 0)
		spf->size = 1;
	spf->m_m[1] = ft_max(spf->size, spf->num2);
	while (spf->num2 > spf->size)
		ft_space_x_return(spf);
	if (!((((spf->point_1 == 1 && spf->num1 < 0) || (spf->point_2 == 1
	&& spf->num2 < 0 && spf->wildcard == 0)) || (spf->point_2 && spf->wildcard
	&& spf->num2 == 0)) && nb == 0) || (spf->point_1 && spf->num1 < 0
	&& spf->num2 < 0 && spf->wildcard))
	{
		if (nb == 0)
			ft_put_char_count('0', spf);
		else
			ft_putnbr_base_u(nb, "0123456789abcdef", spf);
	}
	else if (!(spf->point_1 && nb == 0 && spf->num1 < 0))
		ft_put_char_count(' ', spf);
	while (spf->num1 > (spf->m_m[1]))
	{
		ft_put_char_count(' ', spf);
		spf->num1--;
	}
}

void	ft_treat_x(unsigned int nb, t_struct *spf)
{
	unsigned int	max_size_or_num2;

	spf->size = ft_len_base(nb, "0123456789abcdef");
	max_size_or_num2 = ft_max(spf->size, spf->num2);
	if (nb == 0)
		spf->size = 1;
	max_size_or_num2 = ft_max(spf->size, spf->num2);
	if (spf->nbisneg && spf->point_1 && spf->num2 == -1 && spf->printminus == 0)
	{
		ft_putchar_fd('-', 1);
		spf->print_count++;
		spf->printminus = 1;
		spf->num1++;
	}
	if ((spf->nbisneg && spf->point_1 && spf->zero == 0 && spf->printminus == 0)
	|| (spf->nbisneg && spf->point_2 == 0 && spf->zero && spf->printminus == 0))
	{
		ft_put_char_count('-', spf);
		spf->printminus = 1;
		spf->size++;
	}
	while (spf->num1 > (int)(max_size_or_num2 + spf->nbisneg))
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
	if (((spf->minus && spf->num1 > spf->size) && !(spf->point_2 == 1
	&& spf->num2 && nb == 0)) || (spf->wildcard && ((spf->point_1
	&& spf->num1 < 0) || (spf->point_2 && spf->num1 < 2)) && spf->num2 != 0
	&& nb == 0))
	{
		if (nb == 0)
			ft_put_char_count('0', spf);
		else
			ft_putnbr_base_u(nb, "0123456789abcdef", spf);
		spf->allprint = 1;
	}
	if (spf->nbisneg && spf->printminus == 0)
	{
		ft_putchar_fd('-', 1);
		spf->print_count++;
		spf->printminus = 1;
		max_size_or_num2--;
	}
	while (spf->num2 > spf->size)
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
	if (spf->point_1 == 1 && spf->num1 == -1 && nb == 0)
		return ;
	if (spf->point_2 == 1 && spf->num2 == -1 && nb == 0 && !spf->allprint)
	{
		ft_put_char_count(' ', spf);
		return ;
	}
	if (spf->allprint == 0 && !(nb == 0 && (spf->point_1 || spf->point_2)
	&& (spf->num2 == 0 || spf->num1 == 0)))
		if (nb == 0)
			ft_put_char_count('0', spf);
		else
			ft_putnbr_base_u(nb, "0123456789abcdef", spf);
	else if (nb == 0 && spf->point_2 && spf->num1 && !spf->allprint)
		ft_put_char_count(' ', spf);
}
