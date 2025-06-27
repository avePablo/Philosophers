/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:17:25 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/17 18:17:27 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		if (c1[i] == '\0' || c2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char *a;
	char *b;

	a = "2154547";
	b = "2222224";
	ft_strncmp(b, a, 2);
	printf("%d", ft_strncmp(b, a, 5));
	return (0);
}*/