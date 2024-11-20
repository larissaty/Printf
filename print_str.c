/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:58:35 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/20 14:32:18 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return ;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	print_str(char *s)
{
	size_t	len;

	if (s == NULL)
	{
		len = ft_strlen("(null)");
		ft_putstr("(null)");
	}
	else
	{
		len = ft_strlen(s);
		ft_putstr(s);
	}
	return (len);
}
