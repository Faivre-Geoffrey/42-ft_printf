/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:48:59 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/12 10:52:26 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			check_base(char *base)
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
		while (base[z++])
			if (base[i] == base[z])
				return (0);
		i++;
	}
	return (1);
}

void		ft_nbr_base_add(int *nbr_final, int *i,
				unsigned int *nbr, int size_base)
{
	int x;

	x = *i;
	nbr_final[x] = *nbr % size_base;
	x++;
	*nbr = *nbr / size_base;
	*i = x;
}

char		*ft_return_nbr_base(unsigned int nbr, char *base, char *str)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	int j;

	i = 0;
	j = 0;
	size_base = 0;
	if (check_base(base))
	{
		while (base[size_base])
			size_base++;
		while (nbr)
			ft_nbr_base_add(nbr_final, &i, &nbr, size_base);
		while (--i >= 0)
			str[j++] = (base[nbr_final[i]]);
		str[j] = '\0';
	}
	return (str);
}

int			ft_len_base(unsigned int nbr, char *base)
{
	int				size_base;
	int				nbr_final[100];
	int				i;
	unsigned int	x;

	i = 0;
	size_base = 0;
	x = 0;
	if (check_base(base))
	{
		while (base[size_base])
			size_base++;
		while (nbr)
			ft_nbr_base_add(nbr_final, &i, &nbr, size_base);
		while (--i >= 0)
			x++;
	}
	return (x);
}

void		ft_put_char_count(char c, t_struct *spf)
{
	ft_putchar_fd(c, 1);
	spf->print_count++;
}
