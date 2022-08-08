/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:03:47 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/29 23:50:54 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// start printf

typedef struct s_format
{
	const char		*format;
	va_list			ap;
	size_t			i;
	size_t			length;
	unsigned char	fill_str;
	char			*str;
	size_t			str_i;
	size_t			size_str;
}	t_format;

typedef struct s_holder
{
	unsigned char	flag_minus;
	unsigned char	flag_plus;
	unsigned char	flag_space;
	unsigned char	flag_numbersign;
	unsigned char	flag_zero;
	unsigned char	subspec_width;
	unsigned int	width;
	unsigned char	subspec_precision;
	unsigned int	precision;
	size_t			length;
}	t_holder;

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);
int			ft_sprintf(char *str, size_t size,	const char *format, ...);
int			ft_writestr(t_format *fmt, int fd, const void *buf, size_t count);

t_format	*ft_initialize_format(const char *format, va_list ap);
t_holder	*ft_initialize_holder(void);

void		ft_placeholder(t_format *fmt);
void		ft_placeholder_subspec(t_format *fmt, t_holder *hdr);
void		ft_placeholder_subspec_width(t_format *fmt, t_holder *hdr);
void		ft_placeholder_subspec_precision(t_format *fmt, t_holder *hdr);

void		ft_specifier_c(t_format *fmt, t_holder *hdr);
void		ft_specifier_s(t_format *fmt, t_holder *hdr);
void		ft_specifier_p(t_format *fmt, t_holder *hdr);
void		ft_specifier_d_i(t_format *fmt, t_holder *hdr);
void		ft_specifier_ui(t_format *fmt, t_holder *hdr, char *pre, char *b);
void		ft_specifier_pct(t_format *fmt);

void		ft_subspec_justify(char **str, t_holder *hdr);
void		ft_subspec_minimum_number(char **str, size_t size);

// end printf

// start get_next_line

typedef struct s_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char		*get_next_line(int fd);

// end get_next_line

// Part 1
// #include <ctype.h>
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

// #include <string.h>
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char	*big, const char *little, size_t len);
char		*ft_strdup(const char *s);

// #include <bsd/string.h>
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);

// #include <stdlib.h>
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nelem, size_t elsize);

// Part 2
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);

// Extras
char		*ft_ulltoa_base(unsigned long long nbr, char *base);
char		*ft_uitoa_base(unsigned int nbr, char *base);
void		ft_strupd(char **str, char *newstr);
size_t		ft_split_count(char const *s, char c);
int			ft_isspace(int c);
int			ft_validate_base(char *base);
int			ft_atoi_base(char *str, char *base);
void		ft_toupper_str(char **str);
void		ft_tolower_str(char **str);

#endif