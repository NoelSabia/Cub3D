/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsabia <nsabia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:00 by nsabia            #+#    #+#             */
/*   Updated: 2024/06/06 11:04:26 by nsabia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *src, int start, int end)
{
	char	*result;
	int		length;
	int		i;

	length = end - start + 1;
	result = ft_malloc(length);
	i = 0;
	while (start <= end)
	{
		result[i++] = src[start++];
	}
	result[i] = '\0';
	return (result);
}
