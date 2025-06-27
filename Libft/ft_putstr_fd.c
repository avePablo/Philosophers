/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:45:32 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/03 17:30:30 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*int main ()
{
   int fd = open ("text.txt",1);

	ft_putstr_fd("ka casa",fd);
	ft_putstr_fd("ka casa",fd);
	ft_putstr_fd("ka casa",fd);
return (0);
}*/
