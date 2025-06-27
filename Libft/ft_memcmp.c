/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:39:33 by pabalvar          #+#    #+#             */
/*   Updated: 2025/01/21 13:50:09 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1a[i] != s2a[i])
			return ((int)(s1a[i] - s2a[i]));
		++i;
	}
	return (0);
}

/*int	main(void)
{
	char *a;
	char *b;

	a = "holahola";
	b = "holnhold";
	printf("%d", ft_memcmp(b, a, 5));
	return (0);
}*/