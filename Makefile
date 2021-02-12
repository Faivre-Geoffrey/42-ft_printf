LIBFT = libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
			sources/utils_1.c \
			sources/utils_2.c \
			sources/utils_3.c \
			sources/utils_4.c \
			sources/ft_redirect_to_args_type.c \
			sources/ft_treat_c.c \
			sources/ft_treat_i.c \
			sources/ft_treat_i_2.c \
			sources/ft_treat_s.c \
			sources/ft_treat_u.c \
			sources/ft_treat_u_2.c \
			sources/ft_treat_x.c \
			sources/ft_treat_X1.c \
			sources/ft_treat_per.c \
			sources/ft_treat_p.c \


SURPL_O = 	ft_printf.o \
			utils_1.o \
			utils_2.o \
			utils_3.o \
			utils_4.o \
			ft_redirect_to_args_type.o \
			ft_treat_c.o \
			ft_treat_i.o \
			ft_treat_i_2.o \
			ft_treat_s.o \
			ft_treat_u.o \
			ft_treat_u_2.o \
			ft_treat_x.o \
			ft_treat_X1.o \
			ft_treat_per.o \
			ft_treat_p.o \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = ft_printf.h

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)


fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY:		all clean fclean re
