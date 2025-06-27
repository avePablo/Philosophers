/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:18:34 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/11 19:18:37 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, size_t *cter)
{
	if (n == -2147483648)
	{
		ft_putnbr_pf((n / 10), cter);
		ft_putchar_pf('8', cter);
	}
	else if (n < 0)
	{
		ft_putchar_pf('-', cter);
		ft_putnbr_pf(-n, cter);
	}
	else
	{
		if (n > 9)
			ft_putnbr_pf((n / 10), cter);
		ft_putchar_pf(('0' + n % 10), cter);
	}
}
