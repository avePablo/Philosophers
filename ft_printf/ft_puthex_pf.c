/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:18:06 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/11 19:18:08 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_puthex_pf(size_t nbr, char *base, size_t *cter, int x)
{
	size_t	len;

	len = ft_strlen(base);
	if (x == 1 && nbr != 0)
		ft_putstr_pf("0x", cter);
	if (nbr == 0 && x == 1)
		ft_putstr_pf("(nil)", cter);
	if ((nbr >= len))
	{
		ft_puthex_pf(nbr / len, base, cter, 0);
	}
	if (!(x == 1 && nbr == 0))
		ft_putchar_pf(base[nbr % len], cter);
}
