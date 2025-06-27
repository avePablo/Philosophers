/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:27:45 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/23 12:27:50 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*pt;
	char	*s1;

	s1 = (char *)s;
	len = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	pt = (char *)malloc(sizeof(char) * len + 1);
	if (!pt)
	{
		return (NULL);
	}
	len = 0;
	while (s1[len] != '\0')
	{
		pt[len] = s1[len];
		len++;
	}
	pt[len] = '\0';
	return (pt);
}
