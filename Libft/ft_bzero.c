/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:21:03 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/21 19:21:08 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*pt;

	pt = (char *)s;
	pt = ft_memset(s, '\0', n);
	return (pt);
}

/*int	main(void)
{
	char a[] = "pepep";
	int b;

	printf("%s", ft_bzero(a, 5));

	return (0);
}*/