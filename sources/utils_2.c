/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:48:28 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/12 10:51:54 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_ifisneg_u(unsigned int *nb, t_struct *spf)
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

static int	ft_estim(unsigned int n)
{
	size_t			estim;

	estim = 0;
	while (n >= 1)
	{
		estim++;
		n /= 10;
	}
	return (estim);
}

static char	*ft_gen(char *rtn, unsigned int nbr, int len, int isneg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	isneg = 0;
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

char		*ft_itoa_u(unsigned int n)
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
