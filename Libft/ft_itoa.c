/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:14:56 by pabalvar          #+#    #+#             */
/*   Updated: 2025/03/21 16:48:16 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	i;

	if (n <= 0)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr_stock(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_putnbr_stock(n / 10, str, i);
	}
	str[(*i)++] = (n % 10) + '0';
}

static char	*ft_malloc(long nbr, char *str)
{
	if (nbr == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * (ft_nbrlen(nbr) + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	str = "";
	i = 0;
	nbr = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_malloc(nbr, str);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr = -nbr;
	}
	ft_putnbr_stock(nbr, str, &i);
	str[i] = '\0';
	return (str);
}
