/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:43:22 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/01 13:43:22 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void ft_space(t_struct *spf)
{
		if ((spf->point_1 || spf->zero) && !(spf->zero == 1 && spf->minus == 1))
			ft_putchar_fd('0',1);
		else 
			ft_putchar_fd(' ',1);
		spf->print_count++;
		spf->num1--;

}

void	ft_treat_s_return(char *str, t_struct *spf)
{
	int size;
	int size_or_num2[2];
	int i;

	if (!str)
		str = "(null)";
	i = 0;
	size = ft_strlen(str);
	size_or_num2[0] = ft_min(size, spf->num2);
	size_or_num2[1] = ft_max(size, spf->num2);
	while ( size != 0 && str[i] &&
		((spf->point_2 && ((spf->num2 && i < spf->num2)))
		|| (spf->point_2 && spf->wildcard && spf->num2 < 0 && spf->num1)))
	{
		ft_putchar_fd(str[i], 1);
		i++;
		spf->print_count++;
	}
	if (((!(spf->point_2 && spf->num1 >= 0))  &&size != 0)
	&& !(spf->wildcard && spf->num1 == -1 && (spf->num2 ==  0 || i <= spf->num2)))
		i = ft_printfstr(str, i, spf);
	while ((spf->num1 > (size_or_num2[0] ) && spf->point_2  && !(spf->point_1 && size == 0))
	&&  !(spf->wildcard && spf->num1 && spf->num2 < 0)  && !((spf->point_1 == 1 && spf->minus)))
		ft_space(spf);
	while (spf->num1 > (size_or_num2[1] ) && !(spf->point_1 && size == 0)&& !((spf->point_1 == 1 && spf->minus)))
		ft_space(spf);
}







void	ft_treat_s(char *str, t_struct *spf)
{
	int size;
	int size_or_num2[2];
	int i;
	int allprint;
	int u;

	size = 0;
	i = 0;
	u = 0;
	allprint = 0;
	if (!str)
		str = "(null)";
	if (spf->point_1 && spf->num1 == 0)
		return ;
	size = ft_strlen(str);
	size_or_num2[0] = ft_min(size, spf->num2);
	size_or_num2[1] = ft_max(size, spf->num2);
	if (spf->point_1 == 1 && spf->num1 == -1 && !spf->wildcard)
		allprint = 1;
	while (spf->point_1 && spf->num1 > 0 && str[i] && allprint == 0)
	{
		ft_putchar_fd(str[i], 1);
		spf->print_count++;
		if (spf->point_1 && spf->num1 > 0)
			spf->num1--;
		i++;
		if (!(str[i]) || spf->num1 == 0)
			allprint = 1;
	}
	while ((spf->num1 > size_or_num2[0]) && spf->point_2 && !(spf->wildcard  && u == 0 && spf->num2 == -1) )
	{
		ft_space(spf);
		u++;
	}
	while (spf->num1 > (size_or_num2[1] ) &&  !(spf->point_1 ))
		ft_space(spf);
	while (spf->point_2  && ((spf->wildcard && spf->num2 == -1 ) || i < spf->num2)  && allprint == 0 && size != 0)
	{
		ft_putchar_fd(str[i], 1);
		spf->print_count++;
		if (spf->point_1 && spf->num1 > 0)
			spf->num1--;
		i++;
		if (!(str[i]) || i == spf->num2)
			allprint = 1;
	}
	if ((allprint == 0 && !(spf->point_2 && spf->num1 >= 0 )) && !(spf->wildcard && spf->num1 == -1 && (spf->num2 ==  0 || spf->num2 == 1)) && size != 0)
		i = ft_printfstr(str, i, spf);
	else if (spf->wildcard && spf->num1 == -1 && (spf->num2 ==  0)) 
	{
	ft_putchar_fd(' ', 1);
	spf->print_count++;
	}
}
