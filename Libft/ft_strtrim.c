/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:05:13 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/03 17:33:47 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chr(char const *str, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while ((set[j] != '\0') && (set[j] != '\0'))
	{
		j = 0;
		while (set[j] != str[i] && set[j] != '\0')
			j++;
		i++;
	}
	return (i);
}

static int	ft_rchr(char const *str, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while ((set[j] != '\0') && (i != 0))
	{
		j = 0;
		while (set[j] != str[i - 1] && set[j] != '\0')
			j++;
		if (set[j] != '\0')
			i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	start;
	size_t			len;

	len = 0;
	str = (char *)s1;
	start = ft_chr(s1, set);
	len = ft_rchr(s1, set);
	if ((start <= len) && (start != 0))
		str = ft_substr(s1, (start - 1), (len - start + 1));
	else if (*set == '\0')
		return (ft_strdup(s1));
	else
		str = ft_calloc(1, sizeof(char));
	return (str);
}
