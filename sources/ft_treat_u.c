/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:41:47 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/01 13:41:47 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void ft_space_u_return(t_struct *spf)
{
		 if (spf->point_2 > 0 || spf->zero > 0 || spf->point_1 > 0 )
			ft_putchar_fd('0',1);
		else
			ft_putchar_fd(' ',1);
		spf->print_count++;
		if (spf->point_1)
			spf->num1--;
		else
			spf->num2--;

}


void	ft_treat_u_return(unsigned int nb, t_struct *spf)
{
	char *str;
	int size;
	int max_size_or_num2;

	/* printf("\nspf->num1 = %i\n", spf->num1);
	printf("spf->num2 = %i\n", spf->num2);
	printf("spf->point_1 = %i\n", spf->point_1);
	printf("spf->point_2 = %i\n", spf->point_2);
	printf("spf->nbisneg = %i\n", spf->nbisneg);
	printf("spf->wilcard = %i\n", spf->wildcard);
	printf("spf->zero = %i\n", spf->zero);
	printf("spf->type = %c\n", spf->type); */

	str= ft_itoa_u(nb);
	size = ft_strlen(str);
	max_size_or_num2 = ft_max(size, spf->num2);
	while (spf->num2 > size || (spf->point_1 && spf->num1 > size))
		 ft_space_u_return(spf);
	if (!((((spf->point_1 == 1 && spf->num1 < 0) || (spf->point_2 == 1 && spf->num2 < 0 && spf->wildcard == 0) )
		|| (spf->point_2 && spf->wildcard && spf->num2 == 0) ) && nb == 0)
		|| (spf->point_1 && spf->num1 < 0 && spf->num2 < 0 && spf->wildcard))
		ft_printfstr(str, 0, spf);
	else if (!(spf->point_1 && nb == 0 && spf->num1 < 0))
	{
		ft_putchar_fd(' ',1);
		spf->print_count++;	
	}
	while (spf->num1 > (max_size_or_num2 ))
	{
		ft_putchar_fd(' ',1);
		spf->print_count++;
		spf->num1--;
	}
	
	
} 

void	ft_treat_u(unsigned int nb, t_struct *spf)
{
	char *str;
	int size;
	unsigned int max_size_or_num2;
	unsigned int i;
	int printminus;
	int allprint;

	size = 0;
	i = 0;
	printminus = 0;
	allprint = 0;
	if (nb < 0 && (spf->point_1 || spf->zero || spf->point_2 || spf->zero ))
		ft_ifisneg_u(&nb, spf);
	str= ft_itoa_u(nb);
	size = ft_strlen(str);
	max_size_or_num2 = ft_max(size, spf->num2);
	
	while (spf->num1 > (int)(max_size_or_num2  + spf->nbisneg))
	{
		if ((spf->zero == 1 && spf->num1 == 0  && nb == 0)
		|| (spf->zero == 1 && spf->wildcard && spf->point_2 && spf->num1 > 0 && spf->num2 == -1))
			ft_putchar_fd('0',1);
		else if (spf->point_1 == 1 && spf->num1 == 0 && nb == 0)
			ft_putchar_fd(' ',1);
		else if (spf->point_2 == 1 && spf->zero)
			ft_putchar_fd(' ',1);
		else if (spf->point_1 || spf->zero )
			ft_putchar_fd('0',1);
		else 
			ft_putchar_fd(' ',1);
		spf->print_count++;
		spf->num1--;
	}
	if (((spf->minus && spf->num1 > size) && !(spf->point_2 == 1 && spf->num2 && nb == 0))
	|| (spf->wildcard && ((spf->point_1 && spf->num1 <0) ||  (spf->point_2 && spf->num1 <2))  && spf->num2 != 0 && nb == 0))
	{
		i = ft_printfstr(str, i, spf);
		allprint = 1;
	}
	if (spf->nbisneg &&  printminus == 0)
	{
		ft_putchar_fd('-', 1);
		spf->print_count++;
		printminus = 1;
		max_size_or_num2--;
	}
	while (spf->num2 > size )
	{
		if (spf->point_2 == 1 && spf->num2 == 0  && nb == 0)
			ft_putchar_fd('0',1);
		else if (spf->point_2 == 1 && spf->num2 == 0 && nb == 0)
			ft_putchar_fd(' ',1);
		else if (spf->point_2 || spf->zero)
			ft_putchar_fd('0',1);
		else
			ft_putchar_fd(' ',1);
		spf->print_count++;
		spf->num2--;
	}
	if (spf->point_1 == 1 && spf->num1 == -1 && nb == 0)
		return;
	if (spf->point_2 == 1 && spf->num2 == -1 && nb == 0&& !allprint)
	{
		ft_putchar_fd(' ',1);
		spf->print_count++;
		return;
	}
	if (allprint == 0 && !(nb == 0 && (spf->point_1 || spf->point_2) && (spf->num2 == 0 || spf->num1 == 0)))
		i = ft_printfstr(str, i, spf);
	else if (nb == 0 && spf->point_2 && spf->num1&& !allprint)
	{
		ft_putchar_fd(' ',1);
		spf->print_count++;
	}
}


/* if (( spf->point_1
		|| spf->zero  )
		&& !((spf->point_2 == 1 && spf->zero) ||(spf->point_1 == 1 && spf->num1 == 0 && nb == 0)))
			ft_putchar_fd('0',1);
		else 
			ft_putchar_fd(' ',1);
		spf->print_count++;
		spf->num1--; */