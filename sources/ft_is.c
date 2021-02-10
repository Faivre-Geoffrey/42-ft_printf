/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:29:28 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/10 14:39:04 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_istype(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
	c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int		ft_isflags(char c)
{
	return (c == '-' || c == '0' || c == '.' || c == '*');
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	int x;

	if (a < b)
		x = a;
	else
		x = b;
	if (x < 0)
		x = 0;
	return (x);
}

void	ft_ifisneg(int *nb, t_struct *spf)
{
	*nb *= -1;
	spf->nbisneg = 1;
}

void	ft_ifisneg_u(unsigned int *nb, t_struct *spf)
{
	*nb *= -1;
	spf->nbisneg = 1;
}

int			ft_printfstr(char *str, int i, t_struct *spf)
{
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		spf->print_count++;
		i++;
	}
	return (i);
}

static int		ft_estim(unsigned int n)
{
	size_t			estim;
	int				isneg;
	unsigned int	x;

	estim = 0;
	isneg = 0;
	x = n;
	if (n < 0)
		n = 4294967295 + x;
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char		*ft_gen(char *rtn, unsigned int nbr, int len, int isneg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		rtn[0] = '-';
	else
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char			*ft_itoa_u(unsigned int n)
{
	int				len;
	char			*rtn;
	unsigned int	nbr;
	int				isneg;

	nbr = n;
	len = ft_estim(nbr);
	rtn = 0;
	isneg = 0;
	if (!(rtn = ft_gen(rtn, nbr, len, isneg)))
		return (0);
	return (rtn);
}

int		check_base(char *base)
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

void	ft_nbr_base_add(int *nbr_final, int *i,
				unsigned int *nbr, int size_base)
{
	int x;

	x = *i;
	nbr_final[x] = *nbr % size_base;
	x++;
	*nbr = *nbr / size_base;
	*i = x;
}

char	*ft_return_nbr_base(unsigned int nbr, char *base, char *str)
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
		if (nbr < 0)
		{
			nbr = -nbr;
			str[j] = '-';
		}
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

int	ft_len_base(unsigned int nbr, char *base)
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
		if (nbr < 0)
		{
			nbr = -nbr;
			x++;
		}
		while (base[size_base])
			size_base++;
		while (nbr)
			ft_nbr_base_add(nbr_final, &i, &nbr, size_base);
		while (--i >= 0)
			x++;
	}
	return (x);
}

void	ft_put_char_count(char c, t_struct *spf)
{
	ft_putchar_fd(c, 1);
	spf->print_count++;
}
void ft_space(t_struct *spf)
{
		if ((spf->point_1 || spf->zero) && !(spf->zero == 1 && spf->minus == 1))
			ft_putchar_fd('0',1);
		else
			ft_putchar_fd(' ',1);
		spf->print_count++;
		spf->num1--;

}
