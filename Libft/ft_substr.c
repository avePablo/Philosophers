/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:34:39 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/23 16:34:41 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*d_less_len(char *dest, const char *s, unsigned int start,
		size_t len)
{
	size_t	d;

	d = 0;
	while (d < len)
	{
		dest[d] = s[start + d];
		d++;
	}
	dest[d] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = malloc(1 * sizeof(char));
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	d_less_len(dest, s, start, len);
	return (dest);
}

/*int	main(void)
{
	const char *s;
	unsigned int start;
	size_t len;

	start = 1;
	len = 1;
	s = "";
	printf("%s", ft_substr(s, start, len));
	return (0);
}*/