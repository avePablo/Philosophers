/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:28:51 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/20 16:28:53 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	if ((char)c == 0)
		return (&str[i]);
	return (NULL);
}

/*int	main(void)
{
	char *a;

	a = "sicansios";
	printf("%s", ft_strchr(a, 'c' + 256));
	return (0);
}*/