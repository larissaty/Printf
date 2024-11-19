/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:22:58 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/19 20:32:36 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long nbr)
{
	char	*hex;
	char	buffer[16];
	int		i;
	int		len;

	hex = "0123456789abcdef";
	if (nbr == 0)
	{
		print_char('0');
		return (1);
	}
	i = 0;
	len = 0;
	while (nbr > 0)
	{
		buffer[i] = hex[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
		len += print_char(buffer[i]);
	return (len);
}

int	print_hex_upper(unsigned long nbr)
{
	char	*hex;
	char	buffer[16];
	int		i;
	int		len;

	hex = "0123456789ABCDEF";
	if (nbr == 0)
	{
		print_char('0');
		return (1);
	}
	i = 0;
	len = 0;
	while (nbr > 0)
	{
		buffer[i] = hex[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
		len += print_char(buffer[i]);
	return (len);
}
