/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_x_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:03:06 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/15 09:09:52 by gefaivre         ###   ########.fr       */
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

void	ft_space_x_1(t_struct *spf, unsigned int nb)
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

void	ft_space_x_2(t_struct *spf, unsigned int nb)
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
