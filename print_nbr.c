/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:21:42 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/21 14:15:02 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

size_t	nbrlen(int n)
{
	size_t	len;	

	len = 1;
	if (n == INT_MIN)
		return (ft_strlen("-2147483648"));
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_putnbr(int n)
{
	char	nbr[10];
	int		i;

	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = (n * -1);
	}
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

int	print_nbr(int n)
{
	ft_putnbr (n);
	return (nbrlen(n));
}
