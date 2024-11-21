/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:30 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/21 14:10:49 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long ptr)
{
	char	*hex;
	char	buffer[16];
	size_t	len;
	int		i;

	hex = "0123456789abcdef";
	if (ptr == 0)
		return (print_str("(nil)"));
	i = 0;
	while (ptr > 0)
	{
		buffer[i++] = hex[ptr % 16];
		ptr = ptr / 16;
	}
	print_str("0x");
	len = 2;
	while (--i >= 0)
		len += print_char(buffer[i]);
	return (len);
}
