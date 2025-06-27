/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:26:12 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/21 20:26:14 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if ((!dest) && (!src))
		return (NULL);
	if (d < s || d >= s + n)
		ft_memcpy(d, s, n);
	else
	{
		d = d + n;
		s = s + n;
		while (n--)
		{
			*(--d) = *(--s);
		}
	}
	return (dest);
}
/*int	main(void)
{
	char	a[] = "ñañaññaañ";
	char	b[] = "kkekekeke";

	printf("%s", ft_memmove(a, b, 5));
	return (0);
}*/
