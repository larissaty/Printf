/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:16:30 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/19 17:50:04 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t	ptr)
{
	char	*hex;
	char	buffer[16];
	int		i;

	hex = "0123456789abcdef";
	if (ptr == 0)
	{
		print_char('0');
		return ;
	}
	i = 0;
	while (ptr > 0)
	{
		buffer[i] = hex[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i >= 0)
	{
		print_char(buffer[i]);
		i--;
	}
	return ;
}

int	print_ptr(unsigned long long ptr)
{
	int		len;

	len = 0;
	len = len + print_str("0x");
	if (ptr == 0)
		len = len + print_char('0');
	else
	{
		ft_put_ptr(ptr);
		len = len + ptr_len(ptr);
	}
	return (len);
}
