/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:16:50 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/16 14:45:13 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_option(va_list va, char *std, size_t *cter)
{
	if (*std == 'c')
		ft_putchar_pf(va_arg(va, int), cter);
	else if (*std == 's')
		ft_putstr_pf(va_arg(va, char *), cter);
	else if (*std == 'p')
	{
		ft_puthex_pf(va_arg(va, size_t), "0123456789abcdef", cter, 1);
	}
	else if (*std == 'd' || *std == 'i')
		ft_putnbr_pf(va_arg(va, int), cter);
	else if (*std == 'u')
		ft_putunbr_pf(va_arg(va, unsigned int), cter);
	else if (*std == 'x' || *std == 'X')
	{
		if (*std == 'x')
			ft_puthex_pf(va_arg(va, unsigned int), "0123456789abcdef", cter,
				0);
		else
			ft_puthex_pf(va_arg(va, unsigned int), "0123456789ABCDEF", cter,
				0);
	}
	else if (*std == '%')
		ft_putchar_pf(*std, cter);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	char	*std;
	va_list	va;
	size_t	cter;

	std = (char *)str;
	i = 0;
	if (!std)
		return (0);
	cter = 0;
	va_start(va, str);
	while (std[i] != '\0')
	{
		if (std[i] == '%')
		{
			i++;
			ft_option(va, &std[i], &cter);
		}
		else
			ft_putchar_pf(std[i], &cter);
		i++;
	}
	va_end(va);
	return (cter);
}

// int main()
// {
//     ft_printf();
// 	ft_printf("%d\n", ft_printf());
// 	printf();
// 	printf("%d\n", printf());
// 	return (0);
// }
