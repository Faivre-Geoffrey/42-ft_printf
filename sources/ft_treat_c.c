/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:44:41 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/01 13:44:41 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"




void	ft_treat_c_return(char c, t_struct *struct_pf)
{
	int size;
	int max_size_or_num2;
	int i;
	int allprint = 0;

	if (struct_pf->num2 == 0 && struct_pf->num1 != 0)
	{
		struct_pf->num2 = struct_pf->num1;
		struct_pf->num1 = 0;
	}
	size = 1;
	i = 0;
	max_size_or_num2 = ft_max(size, struct_pf->num2);
	while (struct_pf->num2 > size )
	{
		 ft_space(struct_pf);
	}
	if (!(struct_pf->point_2 == 1 && struct_pf->num2 == -1 ))
	{
		ft_putchar_fd(c,1);
		struct_pf->print_count++;
		allprint = 1;
	}
	else
	{
		ft_putchar_fd(' ',1);
		struct_pf->print_count++;	
	}
	
	if (struct_pf->minus && struct_pf->num2 > size)
	{
		ft_putchar_fd(c,1);
		struct_pf->print_count++;
		allprint = 1;
	}
	while (struct_pf->num1 > (max_size_or_num2  + struct_pf->nbisneg))
	{
		ft_putchar_fd(' ',1);
		struct_pf->print_count++;
		struct_pf->num1--;
	}
	
	
}



void	ft_treat_c(char c, t_struct *struct_pf)
{
	int size;
	int max_size_or_num2;
	int i;
	int allprint;

/* 	printf("\nstruct_pf->minus =	%i\n", struct_pf->minus);
	printf("struct_pf->zero =	%i\n", struct_pf->zero);
	printf("struct_pf->wildcard = 	%i\n", struct_pf->wildcard);
	printf("struct_pf->point_1 =	%i\n", struct_pf->point_1);
	printf("struct_pf->point_2 =	%i\n", struct_pf->point_2); 
	printf("struct_pf->num1 = 	%i\n", struct_pf->num1);
	printf("struct_pf->num2 = 	%i\n", struct_pf->num2);
	printf("struct_pf->type = 	%c\n", struct_pf->type); */
	size = 1;
	i = 0;
	allprint = 0;
	max_size_or_num2 = ft_max(size, struct_pf->num2);

	
	while (struct_pf->num1 > (max_size_or_num2  + struct_pf->nbisneg))
	{
		ft_space(struct_pf);
	}
	if ((struct_pf->minus && struct_pf->num1 > size) && !(struct_pf->point_2 == 1 && struct_pf->num2))
	{
		ft_putchar_fd(c,1);
		struct_pf->print_count++;
		allprint = 1;
	}
	while (struct_pf->num2 > size )
	{
		ft_space(struct_pf);
	}
	if (struct_pf->point_1 == 1 && struct_pf->num1 == -1)
		return;
	if (struct_pf->point_2 == 1 && struct_pf->num2 == -1)
	{
		ft_putchar_fd(' ',1);
		struct_pf->print_count++;
		return;
	}
	if (allprint == 0 && !((struct_pf->point_1 || struct_pf->point_2) && (struct_pf->num2 == 0 || struct_pf->num1 == 0)))
	{
		ft_putchar_fd(c,1);
		struct_pf->print_count++;
	}
	else if (struct_pf->point_2 && struct_pf->num1)
	{
		ft_putchar_fd(' ',1);
		struct_pf->print_count++;
	}
}
