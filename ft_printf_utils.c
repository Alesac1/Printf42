/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <alesacchi1907@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:50:29 by asacchin          #+#    #+#             */
/*   Updated: 2023/02/04 16:12:47 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len += write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		len += putchar('-');
	}
	if (n > 9)
	{
		len += print_int(n / 10);
		len += print_int(n % 10);
	}
	else
		len += ft_printchar(n + 48);
	return (len);
}

int	ft_printhex(unsigned int n, const char ptr)
{
	unsigned int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_printhex(n / 16, ptr);
		len += ft_printhex(n % 16, ptr);
	}
	else
	{
		if (n < 10)
			len += ft_putchar(48 + n);
		else
		{
			if (ptr == 'x')
				len += ft_putchar('a' + n - 10);
			if (ptr == 'X')
				len += ft_putchar('A' + n - 10);
		}
	}
	return (len);
}

int	ft_printunsint(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_printunsint(n / 10);
	len += ft_putchar(n % 10 + 48);
	return (len);
}

int	ft_printp(uintptr_t n)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += print_p(n / 16);
		len += print_p(n % 16);
	}
	else
	{
		if (n < 10)
			len += ft_putchar(48 + n);
		else
			len += ft_putchar('a' + n - 10);
	}
	return (len);
}
