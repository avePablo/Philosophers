/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:58:26 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/11 18:58:28 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);
void	ft_putchar_pf(char c, size_t *cter);
void	ft_putnbr_pf(int n, size_t *cter);
void	ft_putstr_pf(char *std, size_t *cter);
void	ft_putunbr_pf(unsigned int n, size_t *cter);
void	ft_puthex_pf(size_t nbr, char *base, size_t *cter, int x);

#endif
