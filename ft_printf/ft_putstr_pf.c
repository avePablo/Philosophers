/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:19:14 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/11 19:19:16 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *std, size_t *cter)
{
	int		i;

	i = 0;
	if (!std)
		std = "(null)";
	while (std[i] != '\0')
	{
		ft_putchar_pf(std[i], cter);
		i++;
	}
}
