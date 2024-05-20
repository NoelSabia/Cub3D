/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:07:12 by noel              #+#    #+#             */
/*   Updated: 2023/11/14 17:49:48 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && ((i + 1) < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	m;
	size_t	n;

	i = 0;
	m = 0;
	n = 0;
	while (dst[i] != 0 && i < size)
		i++;
	while (src[m] != 0 && i + m + 1 < size)
	{
		dst[i + m] = src[m];
		m++;
	}
	if (i < size)
	{
		dst[i + m] = '\0';
	}
	while (*src++)
		n++;
	return (n + i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		total_len;
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	total_len = i + j + 1;
	joined = ft_malloc(total_len * sizeof(char));
	if (!joined)
		return (0);
	ft_strlcpy(joined, s1, total_len);
	ft_strlcat(joined, s2, total_len);
	return (joined);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	while (s[j])
		j++;
	if (start >= j)
		return (ft_strdup(""));
	if (len > j - start)
		len = j - start;
	sub = ft_malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	len = i;
	dup = ft_malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}
