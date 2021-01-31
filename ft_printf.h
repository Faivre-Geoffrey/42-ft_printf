/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:17:21 by gefaivre          #+#    #+#             */
/*   Updated: 2021/01/14 11:26:41 by gefaivre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef	struct		s_struct
{
	/*type*/
	char	type;
	/*1_flags*/
	int		minus;
	int		zero;
	int		point_1;
	int		wildcard;
	/*2_flags*/
	int		point_2;
	/*count*/
	int		num1;
	int		num2;
	int		print_count;
	int		nbisneg;
}					t_struct;

int		ft_strzero(char *str);
int		ft_printf(const char *input, ...);
void	ft_treat_str(char *str, va_list args, t_struct *struct_pf);
int		ft_make_args(char *str, t_struct *struct_pf);
void	ft_makeflags1(t_struct *struct_pf,char c);
void	ft_makeflags2(t_struct *struct_pf,char c);

int		ft_istype(char c);
int		ft_isflags(char c);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_printfstr(char *str, int i, t_struct *struct_pf);
void	ft_ifisneg(int *nb, t_struct *struct_pf);
void	ft_ifisneg_u(unsigned int *nb, t_struct *struct_pf);
char	*ft_itoa_u(unsigned int n);
int		check_base(char *base);
char	*ft_return_nbr_base(unsigned int nbr, char *base,char *str);
int	ft_len_base(unsigned int nbr, char *base);

void	ft_redirect_to_args_type(va_list args, t_struct *struct_pf);

void 	ft_treat_i_wildcard(int arg2,int space,t_struct *struct_pf);
void	ft_treat_i(int nb, t_struct *struct_pf);
void	ft_treat_i_return(int nb, t_struct *struct_pf);

void 	ft_treat_u_wildcard(unsigned int arg2,unsigned int space,t_struct *struct_pf);
void	ft_treat_u(unsigned int nb, t_struct *struct_pf);
void	ft_treat_u_return(unsigned int nb, t_struct *struct_pf);

void 	ft_treat_x_wildcard(unsigned int arg2,unsigned int space,t_struct *struct_pf);
void	ft_treat_x(unsigned int nb, t_struct *struct_pf);
void	ft_treat_x_return(unsigned int nb, t_struct *struct_pf);

void 	ft_treat_X_wildcard(unsigned int arg2,unsigned int space,t_struct *struct_pf);
void	ft_treat_X(unsigned int nb, t_struct *struct_pf);
void	ft_treat_X_return(unsigned int nb, t_struct *struct_pf);

void	ft_treat_s(char *str, t_struct *struct_pf);
void	ft_treat_s_return(char *str, t_struct *struct_pf);

void ft_treat_per(t_struct *struct_pf);
void	ft_treat_per_return(t_struct *struct_pf);

void	ft_treat_p(unsigned long long ull, t_struct *struct_pf);
void	ft_treat_p_return(unsigned long long ull, t_struct *struct_pf);
void	ft_treat_p_wildcard(int space,unsigned long long ull,t_struct *struct_pf);

void ft_space(t_struct *struct_pf);

void ft_treat_c(char c, t_struct *struct_pf);
#endif
