/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:43:40 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/16 14:43:42 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr_pf(unsigned int n, size_t *cter)
{
	if (n == 0)
		ft_putchar_pf('0', cter);
	else
		ft_puthex_pf(n, "0123456789", cter, 0);
}
