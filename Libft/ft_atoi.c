/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfuto <kfuto@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:14:33 by pabalvar          #+#    #+#             */
/*   Updated: 2025/02/24 16:42:27 by kfuto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signo;
	int	num;

	i = 0;
	signo = 1;
	num = 0;
	while (nptr[i] && ft_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signo = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * signo);
}

/*int	main(void)
{
	const char *a;

	a = "-47-5";

	printf("%d\n", ft_atoi(a));

	return (0);
}*/