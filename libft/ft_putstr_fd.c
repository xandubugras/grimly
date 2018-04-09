/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:01:24 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/20 15:11:30 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char const *s, int fd)
{
	if (fd < 1)
		ft_putstr_fd("wrong fd\n", 1);
	if (!s)
		ft_putstr_fd("(null)", fd);
	while (s && *s)
		ft_putchar_fd(*s++, fd);
}
