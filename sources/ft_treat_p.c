/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:43:22 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/15 07:50:04 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_countnbr_base_ull(unsigned long nb, char *base)
{
	unsigned long	result;
	unsigned long	diviseur;
	unsigned long	size_base;
	int				x;

	x = 0;
	size_base = ft_strlen(base);
	if (nb < 0)
	{
		x++;
		nb = -nb;
	}
	diviseur = 1;
	while ((nb / diviseur) >= size_base)
		diviseur = diviseur * size_base;
	while (diviseur > 0)
	{
		result = (nb / diviseur) % size_base;
		x++;
		diviseur = diviseur / size_base;
	}
	return (x);
}

void	ft_putnbr_base_ull(unsigned long nb, char *base)
{
	unsigned long	result;
	unsigned long	diviseur;
	unsigned long	size_base;

	size_base = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
	}
	diviseur = 1;
	while ((nb / diviseur) >= size_base)
		diviseur = diviseur * size_base;
	while (diviseur > 0)
	{
		result = (nb / diviseur) % size_base;
		ft_putchar_fd(base[result], 1);
		diviseur = diviseur / size_base;
	}
}

void	ft_first_treat_p(unsigned long nb, t_struct *spf)
{
	if (spf->num1 && spf->num2 && spf->minus)
		ft_treat_p_return(nb, spf);
	else
		ft_treat_p(nb, spf);
}

void	ft_treat_p_return(unsigned long nb, t_struct *spf)
{
	spf->size = ft_countnbr_base_ull(nb, "0123456789abcdef") + 2;
	if (nb == 0)
		spf->size = 3;
	spf->m_m[0] = ft_min(spf->size, spf->num2);
	spf->m_m[1] = ft_max(spf->size, spf->num2);
	if (spf->point_2 == 1 && spf->num2 < spf->num2 && spf->size != 0)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_ull(nb, "0123456789abcdef");
		spf->print_count += spf->size;
	}
	if ((!(spf->point_2 && spf->num1 >= 0)) && spf->size != 0)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_ull(nb, "0123456789abcdef");
		spf->print_count += spf->size;
	}
	while (spf->num1 > (spf->m_m[0]) && spf->point_2
	&& !(spf->point_1 && spf->size == 0))
		ft_space(spf);
	while (spf->num1 > (spf->m_m[1]) && !(spf->point_1 && spf->size == 0))
		ft_space(spf);
}

void	ft_treat_p(unsigned long nb, t_struct *spf)
{
	spf->size = ft_countnbr_base_ull(nb, "0123456789abcdef");
	if ((spf->point_1 || spf->point_2) && spf->num2 == -1)
		spf->size = 0;
	spf->m_m[1] = ft_max(spf->size + 2, spf->num2);
	while (spf->num1 > (spf->m_m[1]) && !(spf->point_1))
	{
		ft_put_char_count(' ', spf);
		spf->num1--;
	}
	ft_putstr_fd("0x", 1);
	spf->print_count += 2;
	while (spf->num2 > spf->size || (spf->num1 > spf->size && spf->point_1))
	{
		ft_put_char_count('0', spf);
		spf->num2--;
		spf->num1--;
	}
	if (!((void *)nb == NULL) || !(spf->point_1 || spf->point_2))
	{
		ft_putnbr_base_ull(nb, "0123456789abcdef");
		spf->print_count += spf->size;
	}
}
