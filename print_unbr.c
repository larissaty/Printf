/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:01:44 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/21 14:21:29 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	nbrlen_un(unsigned int n)
{
	size_t	len;	

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	putnbr_un(unsigned int n)
{
	char	nbr[10];
	int		i;

	i = 0;
	while (n >= 10)
	{
		nbr[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (n < 10)
		nbr[i] = n + '0';
	while (i >= 0)
		ft_putchar(nbr[i--]);
	return ;
}

int	print_unsigned(unsigned int n)
{
	putnbr_un (n);
	return (nbrlen_un(n));
}
