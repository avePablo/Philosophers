/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:27:24 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/21 21:27:26 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*si;

	si = (char *)s;
	i = 0;
	while (i < n)
	{
		if (si[i] == (char)c)
		{
			return (&si[i]);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char *a;

	a = "sicansios";
	printf("%s", ft_memchr(a, 'c', 5));
	return (0);
}*/