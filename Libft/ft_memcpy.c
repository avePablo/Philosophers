/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:35:15 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/21 19:35:17 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*buff;
	size_t	i;
	char	*pt;

	pt = (char *)src;
	i = 0;
	buff = dest;
	if (!pt && !buff)
	{
		return (0);
	}
	while (i < n)
	{
		buff[i] = pt[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	a[] = "ñañaññaañ";
	char	b[] = "kkekekeke";

	printf("%s", ft_memcpy(a, b, 5));
	return (0);
}*/
