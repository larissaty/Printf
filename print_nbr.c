/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:21:42 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/19 19:09:25 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int	nbrlen(int n)
{
	int	len;	

	len = 1;
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
	int	len;

	len = nbrlen(n);
	ft_putnbr (n);
	return (len);
}

int	print_unsigned(int n)
{
	int	len;

	if (n < 0)
		n = n * (-1);
	len = nbrlen(n);
	ft_putnbr (n);
	return (len);
}
