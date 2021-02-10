/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gefaivre <gefaivre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:17:21 by gefaivre          #+#    #+#             */
/*   Updated: 2021/02/10 14:28:38 by gefaivre         ###   ########.fr       */
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
	/*others*/
	int		nbisneg;
	int		allprint;
	int 	i;
	int		u;
	int 	nb;
	int 	size;
}					t_struct;

int		ft_strzero(char *str);
int		ft_printf(const char *input, ...);
void	ft_treat_str(char *str, va_list args, t_struct *spf);
int		ft_make_args(va_list args, char *str, t_struct *spf);
void	ft_makeflags1(va_list args, t_struct *spf,char c,int first_time[0]);
void	ft_makeflags2(va_list args, t_struct *spf,char c,int first_time[1]);

int		ft_istype(char c);
int		ft_isflags(char c);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_printfstr(char *str, int i, t_struct *spf);
void	ft_ifisneg(int *nb, t_struct *spf);
void	ft_ifisneg_u(unsigned int *nb, t_struct *spf);
char	*ft_itoa_u(unsigned int n);
int		check_base(char *base);
char	*ft_return_nbr_base(unsigned int nbr, char *base,char *str);
int		ft_len_base(unsigned int nbr, char *base);
void	ft_put_char_count(char c, t_struct *spf);
void	ft_space(t_struct *spf);

void	ft_redirect_to_args_type(va_list args, t_struct *spf);

void	ft_treat_i(int nb, t_struct *spf);
void	ft_treat_i_return(int nb, t_struct *spf);

void	ft_first_treat_u(unsigned int nb, t_struct *spf);
void	ft_treat_u(unsigned int nb, t_struct *spf);
void	ft_treat_u_return(unsigned int nb, t_struct *spf);

void	ft_treat_x(unsigned int nb, t_struct *spf);
void	ft_treat_x_return(unsigned int nb, t_struct *spf);

void	ft_treat_X(unsigned int nb, t_struct *spf);
void	ft_treat_X_return(unsigned int nb, t_struct *spf);

void	ft_first_treat_s(char *str, t_struct *spf);
void	ft_treat_s(char *str, t_struct *spf,int m_m[2], int size);
void	ft_treat_s_return(char *str, t_struct *spf,int m_m[2], int size);

void	ft_treat_per(t_struct *spf);
void	ft_treat_per_return(t_struct *spf);

void	ft_treat_p(unsigned long long ull, t_struct *spf);
void	ft_treat_p_return(unsigned long long ull, t_struct *spf);

void	ft_treat_c(char c, t_struct *spf);
void	ft_treat_c_return(char c, t_struct *sspf);

void	ft_space(t_struct *spf);


#endif
