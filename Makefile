NAME = libftprintf.a

SRC = check_flags.c dispatch.c ft_putchar_len.c init_flags.c \
init_printf.c conv_s.c ft_printf.c launch_printf.c conv_c.c \
conv_di.c handle_di.c handle_o.c handle_u.c handle_x.c \
printf_func.c conv_o.c conv_u.c conv_x.c conv_p.c conv_csp.c \
ft_capitalize.c printf_func_2.c printf_func_3.c

all: $(NAME)

$(NAME):
	make -C libft
	cp libft/libft.a $(NAME)
	gcc -Wall -Wextra -Werror -c $(SRC) -I libft
	ar rc $(NAME) check_flags.o dispatch.o ft_putchar_len.o init_flags.o \
	init_printf.o conv_s.o ft_printf.o launch_printf.o conv_c.o conv_di.o \
	printf_func.o conv_o.o conv_u.o conv_x.o conv_p.o conv_csp.o \
	handle_di.o handle_o.o handle_u.o handle_x.o ft_capitalize.o printf_func_2.o \
	printf_func_3.o
	ranlib $(NAME)

clean:
	make -C libft clean
	/bin/rm -f check_flags.o dispatch.o ft_putchar_len.o init_flags.o \
	init_printf.o conv_s.o ft_printf.o launch_printf.o conv_c.o conv_di.o \
	printf_func.o conv_o.o conv_u.o conv_x.o conv_p.o conv_csp.o \
	handle_di.o handle_o.o handle_u.o handle_x.o ft_capitalize.o printf_func_2.o \
	printf_func_3.o

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all