/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:36:54 by hyeykim           #+#    #+#             */
/*   Updated: 2022/02/14 01:56:35 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define OPEN_MAX 10240

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

long long		ft_atoi(const char *str);

void			ft_bzero(void *s, int n);

void			*ft_calloc(int count, int size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*ft_itoa(int n);

void			*ft_memccpy(void *dst, const void *src, int c, int n);

void			*ft_memchr(const void *s, int c, int n);

int				ft_memcmp(const void *s1, const void *s2, int n);

void			*ft_memcpy(void *dst, const void *src, int n);

void			*ft_memmove(void *dst, const void *src, int len);

void			*ft_memset(void *b, int c, int len);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr_fd(char *s, int fd);

char			**ft_split(char const *s, char c);

char			*ft_strchr(const char *s, int c);

char			*ft_strdup(const char *s1);

char			*ft_strndup(const char *s1, int size);

char			*ft_strjoin(char *s1, char *s2);

int				ft_strlcat(char *dst, const char *src, int size);

int				ft_strlcpy(char *dst, const char *src, int size);

int				ft_strlen(const char *s);

char			*ft_strmapi(char const *s, char (*f)(int, char));

int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strnstr(const char *c, const char *needle, int len);

char			*ft_strrchr(const char *s, int c);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_substr(char const *s, int start, int len);

int				ft_tolower(int c);

int				ft_toupper(int c);

t_list			*ft_lstnew(void *content);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_front(t_list **lst, t_list *new);

void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void *));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

void			init(int *i, int *j);

char			*ft_triple_strjoin(char *s1, char *s2, char *s3);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

int				get_next_line(int fd, char **line);

int				ft_wordcount(char const *s, char c);
#endif
