/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:58:58 by brolivei          #+#    #+#             */
/*   Updated: 2022/12/07 15:24:30 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*dst;

	total = size * nmemb;
	dst = malloc(total);
	if (!dst)
		return (0);
	ft_memset(dst, 0, total);
	return (dst);
}

char	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		((char *)s)[i] = c;
		i++;
		n--;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	total_size;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *)malloc(total_size + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}
