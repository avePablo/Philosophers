/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:59:25 by pabalvar          #+#    #+#             */
/*   Updated: 2025/11/11 12:59:16 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_handler(int err)
{
	if (err == 1)
		printf("invalid/wrong number of arguments\n");
	else if (err == 2)
		printf("un filosofo no puede comer 0 veces\n");
}

int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static long	handle_overflow(long result, int sign, char next_digit)
{
	if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && next_digit > '7'))
	{
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	result;
	long	overflow_check;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		overflow_check = handle_overflow(result, sign, str[i]);
		if (overflow_check)
			return (overflow_check);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}
