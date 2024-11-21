/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltayra-y <ltayra-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:36:10 by ltayra-y          #+#    #+#             */
/*   Updated: 2024/11/21 15:55:22 by ltayra-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		str_len;
	int			i;

	va_start (args, str);
	str_len = 0;
	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				str_len += str_format(args, str[i]);
			else
				break ;
		}
		else
			str_len += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (str_len);
}

int	str_format(va_list args, const char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len = len + print_char(va_arg(args, int));
	if (format == 's')
		len = len + print_str(va_arg(args, char *));
	if (format == 'p')
		len = len + print_ptr(va_arg(args, unsigned long));
	if (format == 'd' || format == 'i')
		len = len + print_nbr(va_arg(args, int));
	if (format == 'u')
		len = len + print_unsigned(va_arg(args, unsigned int));
	if (format == 'x')
		len = len + print_hex(va_arg(args, unsigned int));
	if (format == 'X')
		len = len + print_hex_upper(va_arg(args, unsigned int));
	else if (format == '%')
	{
		print_char('%');
		len = len + 1;
	}
	return (len);
}

// #include <stdio.h>

// int    main(void)
// {
//     int        ft_ret, orig_ret;
//     char    c = 'A';
//     char    *str = "Hello, world!";
//     int        decimal = -42;
//     unsigned int uint = 42;
//     void    *ptr = &decimal;

//     // Teste para caractere (%c)
//     printf("\n--- Teste de %%c ---\n");
//     ft_ret = ft_printf("ft_printf: [%c]\n", c);
//     orig_ret = printf("printf   : [%c]\n", c);
//     printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

//     // Teste para string (%s)
//     printf("\n--- Teste de %%s ---\n");
//     ft_ret = ft_printf("ft_printf: [%s]\n", str);
//     orig_ret = printf("printf   : [%s]\n", str);
//     printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

//     // Teste para decimal/sinalizado (%d e %i)
//     printf("\n--- Teste de %%d / %%i ---\n");
//     ft_ret = ft_printf("ft_printf: [%d] [%i]\n", decimal, decimal);
//     orig_ret = printf("printf   : [%d] [%i]\n", decimal, decimal);
//     printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

// 	// Teste para unsigned decimal (%u)
//     printf("\n--- Teste de %%u ---\n");
//     ft_ret = ft_printf("ft_printf: [%u]\n", uint);
//     orig_ret = printf("printf   : [%u]\n", uint);
//     printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

//     // Teste para hexadecimal minúsculo (%x)
//     printf("\n--- Teste de %%x ---\n");
//     ft_ret = ft_printf("ft_printf: [%x]\n", uint);
//     orig_ret = printf("printf   : [%x]\n", uint);
//     printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

//     // Teste para hexadecimal maiúsculo (%X)
//     printf("\n--- Teste de %%X ---\n");
//     ft_ret = ft_printf("ft_printf: [%X]\n", uint);
//     orig_ret = printf("printf   : [%X]\n", uint);
//     printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

//     // Teste para ponteiro (%p)
//     printf("\n--- Teste de %%p ---\n");
//     ft_ret = ft_printf("ft_printf: [%p]\n", ptr);
//     orig_ret = printf("printf   : [%p]\n", ptr);
//     printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

//     // Teste para literal de porcentagem (%%)
//     printf("\n--- Teste de %%%% ---\n");
//     ft_ret = ft_printf("ft_printf: [%%%%]\n");
//     orig_ret = printf("printf   : [%%%%]\n");
//     printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

//     // Teste para string NULL (%s com NULL)
//     printf("\n--- Teste de %%s com NULL ---\n");
//     ft_ret = ft_printf("ft_printf: [%s]\n", NULL);
//     orig_ret = printf("printf   : [%s]\n", (char *)NULL);
//     printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

//     return (0);
// }