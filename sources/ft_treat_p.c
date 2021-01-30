/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:43:22 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/01 13:43:22 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../ft_printf.h"
/*
void	ft_treat_p_return(char *str, t_struct *struct_pf)
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

	
	printf("\nstruct_pf->minus =	%i\n", struct_pf->minus);
	printf("struct_pf->zero =	%i\n", struct_pf->zero);
	printf("struct_pf->wildcard = 	%i\n", struct_pf->wildcard);
	printf("struct_pf->point_1 =	%i\n", struct_pf->point_1);
	printf("struct_pf->point_2 =	%i\n", struct_pf->point_2); 
	printf("struct_pf->num1 = 	%i\n", struct_pf->num1);
	printf("struct_pf->num2 = 	%i\n", struct_pf->num2);
	printf("struct_pf->type = 	%c\n", struct_pf->type);
	printf("max_size_or_num2 = 	%i\n", max_size_or_num2);
	printf("min_size_or_num2 = 	%i\n", min_size_or_num2);

	 while (struct_pf->point_2 == 1 && struct_pf->num2 && i < struct_pf->num2 && allprint == 0 && size != 0 && str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
		struct_pf->print_count++;
	} 
	if ((allprint == 0 && !(struct_pf->point_2 && struct_pf->num1 >= 0)) && size != 0)
		i = ft_printfstr(str, i, struct_pf);

	if ((struct_pf->point_1 == 1 && struct_pf->minus))
		allprint = 1;
		
	while (struct_pf->num1 > (min_size_or_num2 ) && allprint == 0 && struct_pf->point_2  && !(struct_pf->point_1 && size == 0) )
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




void ft_space(t_struct *struct_pf, int size, char *str)
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


*/
/**********************************************************************************************************/
int	ft_len_base_ull(unsigned int nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	unsigned int x;

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
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			x++;
	}
	return (x);
}
void    ft_putnbr_base_ull(unsigned long nb, char *base)
{
  unsigned long   result;
  unsigned long   diviseur;
  unsigned long   size_base;

  size_base = ft_strlen(base);
  if (nb < 0)
    {
      ft_putchar_fd('-',1);
      nb = -nb;
    }
  diviseur = 1;
  while ((nb / diviseur) >= size_base)
    diviseur = diviseur * size_base;
  while (diviseur > 0)
    {
      result = (nb /diviseur) % size_base;
      ft_putchar_fd(base[result],1);
      diviseur = diviseur / size_base;
    }
}
/**************************************************************************/



void	ft_treat_p(unsigned long long ull, t_struct *struct_pf)
{
	int size;
	int max_size_or_num2;
	int min_size_or_num2;
	int i;
	int allprint;

	size = 0;
	i = 0;
	allprint = 0;
	if (struct_pf->point_1 && ull == 0)
	{
		ft_printfstr("0x", i, struct_pf);
		return;
	}
	
	size = ft_len_base_ull(ull, "0123456789abcdef");
	max_size_or_num2 = ft_max(size, struct_pf->num2);
	min_size_or_num2 = ft_min(size, struct_pf->num2);

/* 	printf("\nstruct_pf->minus =	%i\n", struct_pf->minus);
	printf("struct_pf->zero =	%i\n", struct_pf->zero);
	printf("struct_pf->wildcard = 	%i\n", struct_pf->wildcard);
	printf("struct_pf->point_1 =	%i\n", struct_pf->point_1);
	printf("struct_pf->point_2 =	%i\n", struct_pf->point_2); 
	printf("struct_pf->num1 = 	%i\n", struct_pf->num1);
	printf("struct_pf->num2 = 	%i\n", struct_pf->num2);
	printf("struct_pf->type = 	%c\n", struct_pf->type);
	printf("max_size_or_num2 = 	%i\n", max_size_or_num2);
	printf("min_size_or_num2 = 	%i\n", min_size_or_num2);  */
	



	ft_putnbr_base_ull(ull, "0123456789abcdef");
	printf("\n");
	if (struct_pf->point_1 == 1 && struct_pf->num1 == -1)
		allprint = 1;
	while (struct_pf->point_1 && struct_pf->num1 > 0 && allprint == 0)
	{
		/* ft_putchar_fd(str[i], 1);
		struct_pf->print_count++;
		struct_pf->num1--;
		i++;
		if (!(str[i]) || struct_pf->num1 == 0)
			allprint = 1; */
		ft_putnbr_base_ull(ull, "0123456789abcdef");
	}
	
	while (struct_pf->num1 > (min_size_or_num2 ) && allprint == 0 && struct_pf->point_2  && !(struct_pf->point_1 && size == 0) )
	{
        ft_space(struct_pf);
	}
	
	while (struct_pf->num1 > (max_size_or_num2 ) && allprint == 0 && !(struct_pf->point_1 && size == 0))
	{
		ft_space(struct_pf);
	} 
	
	 while (struct_pf->num2 > size && i < size && i < struct_pf->num2 && allprint == 0)
	{
	/* 	ft_putchar_fd(str[i], 1);
		i++;
		struct_pf->print_count++;
		if (!(str[i]) || struct_pf->num1 == 0)
			allprint = 1;
 */
		ft_putnbr_base_ull(ull, "0123456789abcdef");
	} 
	
	if (struct_pf->point_1 == 1 && struct_pf->num1 == -1)
		return;
	while (struct_pf->point_2 == 1 && struct_pf->num2 && i < struct_pf->num2 && allprint == 0 && size != 0)
	{
		/* ft_putchar_fd(str[i], 1);
		i++;
		struct_pf->print_count++;
		if (!(str[i]) || struct_pf->num2 == 0|| i == struct_pf->num2)
			allprint = 1; */
			ft_putnbr_base_ull(ull, "0123456789abcdef");
	}
	if ((allprint == 0 && !(struct_pf->point_2 && struct_pf->num1 >= 0)) && size != 0)
		ft_putnbr_base_ull(ull, "0123456789abcdef");
	
}