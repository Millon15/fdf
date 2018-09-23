/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:15:12 by vbrazas           #+#    #+#             */
/*   Updated: 2018/09/23 05:17:05 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>

/*
** A little binary print macro
** #define BTB_PTN "%c%c%c%c%c%c%c%c"
** #define BTB(byte)  \
** 	(byte & 0x80 ? '1' : '0'), \
** 	(byte & 0x40 ? '1' : '0'), \
** 	(byte & 0x20 ? '1' : '0'), \
** 	(byte & 0x10 ? '1' : '0'), \
** 	(byte & 0x08 ? '1' : '0'), \
** 	(byte & 0x04 ? '1' : '0'), \
** 	(byte & 0x02 ? '1' : '0'), \
** 	(byte & 0x01 ? '1' : '0')
*/

/*
*****************************************************************************
**************************************GNL************************************
*****************************************************************************
*/

# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

typedef	struct		s_gnl
{
	char			*arr;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

/*
*****************************************************************************
*************************************LIBFT***********************************
*****************************************************************************
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle\
	, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, size_t start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
ssize_t				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
ssize_t				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_lstdelcont(void *content, size_t content_size);
void				ft_swap(int *a, int *b);
int					*ft_range(int min, int max);
void				ft_foreach(int *tab, int width, void (*f)(int));
int					ft_atoi_base(const char *s, int base);
unsigned long		ft_atou_base(const char *s, int base);
char				*ft_utoa_base(size_t value, const int base,
	const bool is_upperсase);
char				*ft_itoa_base(int value, int base);
ssize_t				ft_pow(ssize_t n, int pw);
int					ft_root(int n, int rt);
int					ft_fcd(int a, int b);
int					ft_isprint(int c);
int					ft_iswhitespace(int c);
char				*ft_strnjoin(char const *s1, char const *s2, \
	size_t l1, size_t l2);
ssize_t				ft_putnstr(char const *s, size_t len);
ssize_t				ft_putnstr_fd(char const *s, int fd, size_t len);
ssize_t				ft_putnendl(char const *s, size_t len);
ssize_t				ft_putnendl_fd(char const *s, int fd, size_t len);
int					ft_intlen(int d);
ssize_t				ft_abs(ssize_t x);
ssize_t				ft_min(ssize_t i, ssize_t j);
ssize_t				ft_max(ssize_t i, ssize_t j);
char				*checkintstr(char *str);
int					ft_islowercase(const int c);
int					ft_isuppercase(const int c);
char				ft_itoc(const unsigned char value, \
	const bool is_upperсase);

#endif
