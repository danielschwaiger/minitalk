/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:13:37 by dapanciu          #+#    #+#             */
/*   Updated: 2022/05/25 13:15:14 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_isalpha(int c);
int		ft_isdigit(int d);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_itoa(int n);
#endif