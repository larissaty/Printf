/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:30 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/19 20:16:25 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long long ptr)
{
	char	*hex;
	char	buffer[16];
	int		i;
	int		len;

	hex = "0123456789abcdef";
	if (ptr == 0)
	{
		print_str("(nil)");
		return (5);
	}
	i = 0;
	while (ptr > 0)
	{
		buffer[i] = hex[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	print_str("0x");
	while (i >= 0)
	{
		len = len + print_char(buffer[i]);
		i--;
	}
	return (len + 2);
}
