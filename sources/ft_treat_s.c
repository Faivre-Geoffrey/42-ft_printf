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

void	ft_treat_s_return(char *str, t_struct *struct_pf)
{
	int size;
	int max_size_or_num2;
	int min_size_or_num2;
	int i;
	int printminus;
	int allprint;

	if (!str)
		str = "(null)";
	size = 0;
	i = 0;
	printminus = 0;
	allprint = 0;
	size = ft_strlen(str);
	max_size_or_num2 = ft_max(size, struct_pf->num2);
	min_size_or_num2 = ft_min(size, struct_pf->num2);

	
	/* printf("\nstruct_pf->minus =	%i\n", struct_pf->minus);
	printf("struct_pf->zero =	%i\n", struct_pf->zero);
	printf("struct_pf->wildcard = 	%i\n", struct_pf->wildcard);
	printf("struct_pf->point_1 =	%i\n", struct_pf->point_1);
	printf("struct_pf->point_2 =	%i\n", struct_pf->point_2); 
	printf("struct_pf->num1 = 	%i\n", struct_pf->num1);
	printf("struct_pf->num2 = 	%i\n", struct_pf->num2);
	printf("struct_pf->type = 	%c\n", struct_pf->type);
	printf("max_size_or_num2 = 	%i\n", max_size_or_num2);
	printf("min_size_or_num2 = 	%i\n", min_size_or_num2); */


	while ( size != 0 && str[i]&&
		((struct_pf->point_2 && ((struct_pf->num2 && i < struct_pf->num2)))
		|| (struct_pf->point_2 && struct_pf->wildcard && struct_pf->num2 < 0 && struct_pf->num1)))
	{
		ft_putchar_fd(str[i], 1);
		i++;
		struct_pf->print_count++;
		
	}
	if (((allprint == 0 && !(struct_pf->point_2 && struct_pf->num1 >= 0))  &&size != 0)
	&& !(struct_pf->wildcard && struct_pf->num1 == -1 && (struct_pf->num2 ==  0 || i <= struct_pf->num2)))
	{
		i = ft_printfstr(str, i, struct_pf);
		
	}

	if ((struct_pf->point_1 == 1 && struct_pf->minus))
		allprint = 1;
		
	while ((struct_pf->num1 > (min_size_or_num2 ) && allprint == 0 && struct_pf->point_2  && !(struct_pf->point_1 && size == 0))
	&&  !(struct_pf->wildcard && struct_pf->num1 && struct_pf->num2 < 0)  )
	{
		
		if (struct_pf->zero == 1 && struct_pf->num1 == 0 )
			ft_putchar_fd('0',1);
		else if (struct_pf->point_1 == 1 && struct_pf->num1 == 0 )
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

	while (struct_pf->num1 > (max_size_or_num2 ) && allprint == 0 && !(struct_pf->point_1 && size == 0))
	{
		if (struct_pf->zero == 1)
			ft_putchar_fd(' ',1);
		else if (struct_pf->zero == 1 && struct_pf->num1 == 0 )
			ft_putchar_fd('0',1);
		else if (struct_pf->point_1 == 1 && struct_pf->num1 == 0 && size == 0)
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
	
	
	
}




void ft_space(t_struct *struct_pf)
{
		if (struct_pf->point_1 || struct_pf->zero)
			ft_putchar_fd('0',1);
		else 
			ft_putchar_fd(' ',1);
		struct_pf->print_count++;
		struct_pf->num1--;
}


void	ft_treat_s(char *str, t_struct *struct_pf)
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
	if (struct_pf->point_1 && struct_pf->num1 == 0)
		return ;
	size = ft_strlen(str);
	size_or_num2[0] = ft_min(size, struct_pf->num2);
	size_or_num2[1] = ft_max(size, struct_pf->num2);
	if (struct_pf->point_1 == 1 && struct_pf->num1 == -1 && !struct_pf->wildcard)
		allprint = 1;


	/* printf("\nstruct_pf->minus =	%i\n", struct_pf->minus);
	printf("struct_pf->zero =	%i\n", struct_pf->zero);
	printf("struct_pf->wildcard = 	%i\n", struct_pf->wildcard);
	printf("struct_pf->point_1 =	%i\n", struct_pf->point_1);
	printf("struct_pf->point_2 =	%i\n", struct_pf->point_2); 
	printf("struct_pf->num1 = 	%i\n", struct_pf->num1);
	printf("struct_pf->num2 = 	%i\n", struct_pf->num2);
	printf("struct_pf->type = 	%c\n", struct_pf->type); */

	while (struct_pf->point_1 && struct_pf->num1 > 0 && str[i] && allprint == 0)
	{
		ft_putchar_fd(str[i], 1);
		struct_pf->print_count++;
		if (struct_pf->point_1 && struct_pf->num1 > 0)
			struct_pf->num1--;
		i++;
		if (!(str[i]) || struct_pf->num1 == 0)
			allprint = 1;
		
	}
	while ((struct_pf->num1 > size_or_num2[0]) && struct_pf->point_2 && !(struct_pf->wildcard  && u == 0 && struct_pf->num2 == -1) )
	{
		ft_space(struct_pf);
		u++;
	}
	while (struct_pf->num1 > (size_or_num2[1] ) &&  !(struct_pf->point_1 ))
		ft_space(struct_pf);
	while (struct_pf->point_2  && ((struct_pf->wildcard && struct_pf->num2 == -1 ) || i < struct_pf->num2)  && allprint == 0 && size != 0)
	{
		ft_putchar_fd(str[i], 1);
		struct_pf->print_count++;
		if (struct_pf->point_1 && struct_pf->num1 > 0)
			struct_pf->num1--;
		i++;
		if (!(str[i]) /* || struct_pf->num1 == 0 */ || i == struct_pf->num2)
			allprint = 1;
	}
	if ((allprint == 0 && !(struct_pf->point_2 && struct_pf->num1 >= 0 )) && !(struct_pf->wildcard && struct_pf->num1 == -1 && (struct_pf->num2 ==  0 || struct_pf->num2 == 1)) && size != 0)
	{
		i = ft_printfstr(str, i, struct_pf);
	}
	else if (struct_pf->wildcard && struct_pf->num1 == -1 && (struct_pf->num2 ==  0)) 
	{
	ft_putchar_fd(' ', 1);
	struct_pf->print_count++;
	}
}


	/* printf("\nstruct_pf->minus =	%i\n", struct_pf->minus);
	printf("struct_pf->zero =	%i\n", struct_pf->zero);
	printf("struct_pf->wildcard = 	%i\n", struct_pf->wildcard);
	printf("struct_pf->point_1 =	%i\n", struct_pf->point_1);
	printf("struct_pf->point_2 =	%i\n", struct_pf->point_2); 
	printf("struct_pf->num1 = 	%i\n", struct_pf->num1);
	printf("struct_pf->num2 = 	%i\n", struct_pf->num2);
	printf("struct_pf->type = 	%c\n", struct_pf->type);
	printf("max_size_or_num2 = 	%i\n", max_size_or_num2);
	printf("min_size_or_num2 = 	%i\n", min_size_or_num2); */