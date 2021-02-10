/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:43:22 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/10 08:55:42 by gefaivre         ###   ########.fr       */
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

void	ft_treat_p_return(unsigned long long ull, t_struct *spf)
{
	int	size;
	int	m_m[2];

	size = 0;
	size = ft_countnbr_base_ull(ull, "0123456789abcdef") + 2;
	if (ull == 0)
		size = 3;
	m_m[0] = ft_min(size, spf->num2);
	m_m[1] = ft_max(size, spf->num2);
	if (spf->point_2 == 1 && spf->num2 < spf->num2 && size != 0)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_ull(ull, "0123456789abcdef");
		spf->print_count += size;
	}
	if ((!(spf->point_2 && spf->num1 >= 0)) && size != 0)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_ull(ull, "0123456789abcdef");
		spf->print_count += size;
	}
	while (spf->num1 > (m_m[0]) && spf->point_2 && !(spf->point_1 && size == 0))
		ft_space(spf);
	while (spf->num1 > (m_m[1]) && !(spf->point_1 && size == 0))
		ft_space(spf);
}

void	ft_treat_p(unsigned long long ull, t_struct *spf)
{
	int size;
	int size_or_num2;

	size = ft_countnbr_base_ull(ull, "0123456789abcdef");
	if ((spf->point_1 || spf->point_2) && spf->num2 == -1)
		size = 0;
	size_or_num2 = ft_max(size + 2, spf->num2);
	while (spf->num1 > (size_or_num2) && !(spf->point_1))
	{
		ft_put_char_count(' ', spf);
		spf->num1--;
	}
	ft_putstr_fd("0x", 1);
	spf->print_count += 2;
	while (spf->num2 > size || (spf->num1 > size && spf->point_1))
	{
		ft_put_char_count('0', spf);
		spf->num2--;
		spf->num1--;
	}
	if (!((void *)ull == NULL) || !(spf->point_1 || spf->point_2))
	{
		ft_putnbr_base_ull(ull, "0123456789abcdef");
		spf->print_count += size;
	}
}
