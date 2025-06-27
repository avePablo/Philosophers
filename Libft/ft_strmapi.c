/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:06:52 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/29 00:06:54 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	char	*s1;

	s1 = (char *)s;
	str = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = f(i, s1[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char const *s;
	s = "olaketal";
	printf("%s", ft_strmapi(s, ft_chariterate));
	return (0);
}
static char	ft_chariterate(unsigned int i, char c)
{
	return (c += i);
}*/