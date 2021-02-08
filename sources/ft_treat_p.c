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

int    ft_countnbr_base_ull(unsigned long nb, char *base)
{
  unsigned long   result;
  unsigned long   diviseur;
  unsigned long   size_base;
  int x;

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
      result = (nb /diviseur) % size_base;
      x++;
      diviseur = diviseur / size_base;
    }
	return(x);
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

void	ft_treat_p_return(unsigned long long ull, t_struct *struct_pf)
{
	int size;
	int max_size_or_num2;
	int min_size_or_num2;

	size = 0;
	size = ft_countnbr_base_ull(ull, "0123456789abcdef") + 2;
	if (ull == 0)
	size = 3; 
	max_size_or_num2 = ft_max(size, struct_pf->num2);
	min_size_or_num2 = ft_min(size, struct_pf->num2);
	if(struct_pf->point_2 == 1 && struct_pf->num2 < struct_pf->num2 && size != 0)
	{
		ft_putstr_fd("0x",1);
		ft_putnbr_base_ull(ull, "0123456789abcdef");
		struct_pf->print_count +=  size;
	} 
	if ((!(struct_pf->point_2 && struct_pf->num1 >= 0)) && size != 0)
	{
		ft_putstr_fd("0x",1);
		ft_putnbr_base_ull(ull, "0123456789abcdef");
		struct_pf->print_count +=  size;
	}
	while (struct_pf->num1 > (min_size_or_num2 ) && struct_pf->point_2  && !(struct_pf->point_1 && size == 0) )
		ft_space(struct_pf);
	while (struct_pf->num1 > (max_size_or_num2 ) &&  !(struct_pf->point_1 && size == 0))
		ft_space(struct_pf);
}
void	ft_treat_p(unsigned long long ull, t_struct *struct_pf)
{
	int size;
	int size_or_num2[2];

	size = 0;
	size = ft_countnbr_base_ull(ull, "0123456789abcdef");
	if ((struct_pf->point_1 || struct_pf->point_2)&& struct_pf->num2 == -1)
	size = 0;
	size_or_num2[1] = ft_max(size + 2, struct_pf->num2);
	while (struct_pf->num1 > (size_or_num2[1]) && !(struct_pf->point_1 ))
	{
		ft_putchar_fd(' ', 1);
		struct_pf->num1--;
		struct_pf->print_count++;
	}
	ft_putstr_fd("0x",1);
	struct_pf->print_count +=  2;
	while (struct_pf->num2 > size || (struct_pf->num1 > size && struct_pf->point_1))
	{
		ft_putchar_fd('0', 1);
		struct_pf->num2--;
		struct_pf->num1--;
		struct_pf->print_count++;
	} 
	if(!((void *)ull == NULL) || !(struct_pf->point_1 || struct_pf->point_2))
	{
		ft_putnbr_base_ull(ull, "0123456789abcdef");
		struct_pf->print_count +=  size;
	}
}