/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 01:09:41 by pabalvar          #+#    #+#             */
/*   Updated: 2024/09/29 01:09:43 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*int	main(void)
{
	char	s[] = "olaola";

	ft_striteri(s, ft_chariterate);
	return (0);
}

static void	ft_chariterate(unsigned int i, char *c)
{
	if (i == 0)
		*c -= 32;
}*/
