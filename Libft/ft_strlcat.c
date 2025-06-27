/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:16:42 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/17 18:16:51 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dest[j + i] = src[j];
		j++;
	}
	if (i < size)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*int	main(void)
{
	char dst[] = "hola";
	char src[] = "quetal";

	printf("%zu", ft_strlcat(dst, src, 11));
	return (0);
}*/