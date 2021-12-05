#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_list
{
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			dieze;
	int			star;
	int			width;
	int			prec;
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			len;
	char		*result;
	int			sprec;
	int			boucle;
	int			patch;
	char		sign;
	char		*fmt;
	int			percent;
	int			x;
	int			error;
	int			check;
	char		*tmp;
}				t_list;

void			handle_di(t_list *p);
void			handle_o(t_list *p);
void			handle_u(t_list *p);
void			handle_x(t_list *p);
void			conv_csp(t_list *p);
void			conv(t_list *p);
void			ft_capitalize(t_list *p);
char			*ft_itoa_base_ll(long long n, int b);
void			conv_u(t_list *p, va_list *arg);
char			*ft_itoa_long(uintmax_t n);
int				ft_strlenp(const char *s);
t_list			*init_printf(const char *format, t_list *p);
void			launch_printf(t_list *p, va_list *arg);
void			ft_putchar_len(char c, t_list *p);
void			ft_putstr_len(char *str, t_list *p);
void			init_flags(t_list *p);
void			check_flags(t_list *p);
void			dispatch(t_list *p, va_list *arg);
void			ft_putstr_len(char *str, t_list *p);
void			conv_di(t_list *p, va_list *arg);
void			conv_c(t_list *p, va_list *arg);
void			conv_p(t_list *p, va_list *arg);
void			conv_o(t_list *p, va_list *arg);
void			conv_u(t_list *p, va_list *arg);
void			conv_x(t_list *p, va_list *arg);
void			conv_str(t_list *p, va_list *arg);
void			conv_s(t_list *p);
int				ft_printf(const char *format, ...);
void			get_di_int(t_list *p, va_list *arg);
void			get_di_sign(t_list *p);
void			get_x(t_list *p, va_list *arg);
char			*handle_di_width_minus_2(t_list *p, char *new, int fill, int i);
char			*handle_di_width_zero_2(t_list *p, char *new, int fill, int i);
char			*handle_di_prec_2(t_list *p, char *s, int i, int stock);
char			*handle_di_width_2(t_list *p, char *new, int fill, int i);

#endif
