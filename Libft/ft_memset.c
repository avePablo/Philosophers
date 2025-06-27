/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:34:29 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/21 18:34:31 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*pt;
	size_t	i;

	pt = (char *)s;
	i = 0;
	if (n == 0)
	{
		return (pt);
	}
	while (i < n)
	{
		pt[i] = c;
		i++;
	}
	return (pt);
}

/*int	main(void)
{
	char a[] = "pepep";
	int b;
	b = 'z';

	printf("%s", ft_memset(a, b, 5));

	return (0);
}*/