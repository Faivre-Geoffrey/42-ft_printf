/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_X1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:41:47 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/01 13:41:47 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void	ft_treat_X_return(unsigned int nb, t_struct *struct_pf)
{
	char *str;
	int size;
	int max_size_or_num2;
	int i;
	int printminus;

	if (!(str= malloc(sizeof(char) * ft_len_base(nb, "0123456789ABCDEF") + 1)))
        return ;
    str = ft_return_nbr_base(nb, "0123456789ABCDEF", str);
    if (nb == 0)
    {
        str[0] = '0';
        str[1] = '\0';

    }
	size = ft_strlen(str);
	max_size_or_num2 = ft_max(size, struct_pf->num2);
	i = 0;
	printminus = 0;
	max_size_or_num2 = ft_max(size, struct_pf->num2);
	
	while (struct_pf->num2 > size )
	{
		 if (struct_pf->point_2 > 0 || struct_pf->zero > 0)
			ft_putchar_fd('0',1);
		else
			ft_putchar_fd(' ',1);
		struct_pf->print_count++;
		struct_pf->num2--;
	}
	if (!((((struct_pf->point_1 == 1 && struct_pf->num1 < 0) || (struct_pf->point_2 == 1 && struct_pf->num2 < 0 && struct_pf->wildcard == 0) )
			|| (struct_pf->point_2 && struct_pf->wildcard && struct_pf->num2 == 0) ) && nb == 0)
			|| (struct_pf->point_1 && struct_pf->num1 < 0 && struct_pf->num2 < 0 && struct_pf->wildcard)
			)
	{
		i = ft_printfstr(str, i, struct_pf);
	}
	else if (!(struct_pf->point_1 && nb == 0 && struct_pf->num1 < 0))
	{
		ft_putchar_fd(' ',1);
		struct_pf->print_count++;	
	}
	while (struct_pf->num1 > (max_size_or_num2 ))
	{
		ft_putchar_fd(' ',1);
		struct_pf->print_count++;
		struct_pf->num1--;
	}
	
	
}

void	ft_treat_X(unsigned int nb, t_struct *struct_pf)
{
	char *str;
	int size;
	unsigned int max_size_or_num2;
	unsigned int i;
	int printminus;
	int allprint;

/* 	printf("\nstruct_pf->minus =	%i\n", struct_pf->minus);
	printf("struct_pf->zero =	%i\n", struct_pf->zero);
	printf("struct_pf->wildcard = 	%i\n", struct_pf->wildcard);
	printf("struct_pf->point_1 =	%i\n", struct_pf->point_1);
	printf("struct_pf->point_2 =	%i\n", struct_pf->point_2); 
	printf("struct_pf->num1 = 	%i\n", struct_pf->num1);
	printf("struct_pf->num2 = 	%i\n", struct_pf->num2);
	printf("struct_pf->type = 	%c\n", struct_pf->type); */
	size = 0;
	i = 0;
	printminus = 0;
	allprint = 0;
	if (!(str= malloc(sizeof(char) * ft_len_base(nb, "0123456789ABCDEF") + 1)))
        return ;
    str = ft_return_nbr_base(nb, "0123456789ABCDEF", str);
    if (nb == 0)
    {
        str[0] = '0';
        str[1] = '\0';

    }
	size = ft_strlen(str);
	max_size_or_num2 = ft_max(size, struct_pf->num2);
	
	if (struct_pf->nbisneg && struct_pf->point_1 && struct_pf->num2 == -1 && printminus == 0)
	{
		ft_putchar_fd('-', 1);
		struct_pf->print_count++;
		printminus = 1;
		struct_pf->num1++;
	}
	if ((struct_pf->nbisneg && struct_pf->point_1 && struct_pf->zero == 0 && printminus ==0) || (struct_pf->nbisneg && struct_pf->point_2 == 0&& struct_pf->zero && printminus ==0) )
	{
		ft_putchar_fd('-', 1);
		struct_pf->print_count++;
		printminus = 1;
		size++;
	}
	while (struct_pf->num1 > (int)(max_size_or_num2  + struct_pf->nbisneg))
	{
		if ((struct_pf->zero == 1 && struct_pf->num1 == 0  && nb == 0)
		|| (struct_pf->zero == 1 && struct_pf->wildcard && struct_pf->point_2 && struct_pf->num1 > 0 && struct_pf->num2 == -1))
			ft_putchar_fd('0',1);
		else if (struct_pf->point_1 == 1 && struct_pf->num1 == 0 && nb == 0)
			ft_putchar_fd(' ',1);
		else if (struct_pf->point_2 == 1 && struct_pf->zero)
			ft_putchar_fd(' ',1);
		else if (struct_pf->point_1 || struct_pf->zero)
			ft_putchar_fd('0',1);
		else 
			ft_putchar_fd(' ',1);
		struct_pf->print_count++;
		struct_pf->num1--;
	}
	if (((struct_pf->minus && struct_pf->num1 > size) && !(struct_pf->point_2 == 1 && struct_pf->num2 && nb == 0 ))
	|| (struct_pf->wildcard && ((struct_pf->point_1 && struct_pf->num1 <0) ||  (struct_pf->point_2 && struct_pf->num1 <2)) && struct_pf->num2 != 0&& nb == 0))
	{
		i = ft_printfstr(str, i, struct_pf);
		allprint = 1;
	}
	if (struct_pf->nbisneg &&  printminus == 0)
	{
		ft_putchar_fd('-', 1);
		struct_pf->print_count++;
		printminus = 1;
		max_size_or_num2--;
	}
	while (struct_pf->num2 > size )
	{
		if (struct_pf->point_2 == 1 && struct_pf->num2 == 0 && struct_pf && nb == 0)
			ft_putchar_fd('0',1);
		else if (struct_pf->point_2 == 1 && struct_pf->num2 == 0 && nb == 0)
			ft_putchar_fd(' ',1);
		else if (struct_pf->point_2 || struct_pf->zero)
			ft_putchar_fd('0',1);
		else
			ft_putchar_fd(' ',1);
		struct_pf->print_count++;
		struct_pf->num2--;
	}
	if (struct_pf->point_1 == 1 && struct_pf->num1 == -1 && nb == 0)
		return;
	if (struct_pf->point_2 == 1 && struct_pf->num2 == -1 && nb == 0&& !allprint)
	{
		ft_putchar_fd(' ',1);
		struct_pf->print_count++;
		return;
	}
	if (allprint == 0 && !(nb == 0 && (struct_pf->point_1 || struct_pf->point_2) && (struct_pf->num2 == 0 || struct_pf->num1 == 0)))
		i = ft_printfstr(str, i, struct_pf);
	else if (nb == 0 && struct_pf->point_2 && struct_pf->num1&& !allprint)
	{
		ft_putchar_fd(' ',1);
		struct_pf->print_count++;
	}
}