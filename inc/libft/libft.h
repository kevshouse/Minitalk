/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keanders <keanders@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:50:25 by keanders          #+#    #+#             */
/*   Updated: 2024/12/04 14:55:05 by keanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// memset;
// bzero;
// memcpy;
// memmove;
// strlcpy;
// strlcat;
// toupper;
// tolower;
// strchr;
// strrchr;
// strncmp;
// memchr;
// memcmp;
// strnstr;
// atoi;
// In order to implement the two following functions, you will use malloc():
// calloc;
// strdup;
//

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

// Typedefs and prototypes

int		ft_isalpha(int i);
int		ft_isprint(int i);

/* FUNCTIONS */
int			ft_isalpha(int i);
int			ft_isdigit(int i);
int			isalnum(int c);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	ft_tolower(char c);
char	ft_toupper(char c);
void	*ft_memset(void *b, int c, size_t len);

#endif
