/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 08:22:10 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/14 11:25:51 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_set_struct(t_struct *struct_pf)
{
	struct_pf->type = 'a';
	struct_pf->minus = 0;
	struct_pf->zero = 0;
	struct_pf->point_1 = 0;
	struct_pf->point_2 = 0;
	struct_pf->wildcard = 0;
	struct_pf->num1 = -1;
	struct_pf->num2 = -1;
	struct_pf->nbisneg = 0;

}

void ft_makeflags1(t_struct *struct_pf,char c)
{
	if (c == '-')
		struct_pf->minus = 1;
	if (c == '0')
		struct_pf->zero = 1;
	if (c == '.')
		struct_pf->point_1 = 1;
	if (c == '*')
		struct_pf->wildcard = 1;
}
void ft_makeflags2(t_struct *struct_pf,char c)
{
	if (c == '-')
		struct_pf->minus = 1;
	if (c == '0')
		struct_pf->zero = 1;
	if (c == '.')
		struct_pf->point_2 = 1;
	if (c == '*')
		struct_pf->wildcard = 1;
}
int ft_strzero(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[0] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int ft_make_args(char *str, t_struct *struct_pf)
{
	int i;
	int j;
	int g;
	char num_save1[15];
	char num_save2[15];

	i = 1;
	j = 0;
	g = 0;
	ft_memset(num_save1,'\0',14);
	ft_memset(num_save2,'\0',14);
	if (!(ft_isdigit(str[i])) && !(ft_isflags(str[i])) && !(ft_istype(str[i])))
		return (1);
	while ((ft_isflags(str[i]) && !(str[i] == '0' && str[i - 1] == '.')))
	{
		ft_makeflags1(struct_pf,str[i]);
		i++;
	}
	while (ft_isdigit(str[i])/* && !(str[i] == '0' && str[i - 1] == '.') */)
	{
		num_save1[g] = str[i];
		i++;
		g++;
		num_save1[g] = '\0';
		
	}
	while ((ft_isflags(str[i]) && !(str[i] == '0' && str[i - 1] == '.')))
	{
		ft_makeflags2(struct_pf,str[i]);
		i++;
	}
	if (!(ft_isdigit(str[i])) && !(ft_istype(str[i])))
	{
		return (1);
	}
	while (ft_isdigit(str[i]))
	{
		num_save2[j] = str[i];
		i++;
		j++;
		num_save2[j] = '\0';
	}
	if (!(ft_istype(str[i])))
		return (1);
	struct_pf->type = str[i];
	if (ft_strzero(num_save1))
		struct_pf->num1 = ft_atoi(num_save1);
	if (ft_strzero(num_save2))
	struct_pf->num2 = ft_atoi(num_save2);
	i++;
	/* printf("\nstruct_pf->minus =	%i\n", struct_pf->minus);
	printf("struct_pf->zero =	%i\n", struct_pf->zero);
	printf("struct_pf->point1 =	%i\n", struct_pf->point_1);
	printf("struct_pf->point2 =	%i\n", struct_pf->point_2);
	printf("struct_pf->wildcard = 	%i\n", struct_pf->wildcard);
	printf("struct_pf->num1 = 	%i\n", struct_pf->num1);
	printf("struct_pf->num2 = 	%i\n", struct_pf->num2);
	printf("struct_pf->type = 	%c\n", struct_pf->type);  */
	return (i);
}

void ft_treat_str(char *str, va_list args, t_struct *struct_pf)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && (i += ft_make_args(str + i, struct_pf)))
		{
			ft_redirect_to_args_type(args, struct_pf);
			ft_set_struct(struct_pf);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			struct_pf->print_count++;
			i++;
		}
	}

}

int ft_printf(const char *input, ...)
{
	t_struct struct_pf;
	char	*str;
	va_list		args;

	ft_set_struct(&struct_pf);
	struct_pf.print_count = 0;
	str = ft_strdup(input);
	va_start(args, input);
	ft_treat_str(str ,args ,&struct_pf);
	va_end(args);
	free((char *)str);
	return (struct_pf.print_count);
}

