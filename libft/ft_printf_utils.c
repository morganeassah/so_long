/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:04:58 by massah            #+#    #+#             */
/*   Updated: 2025/11/25 11:13:19 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(unsigned int n, int upper)
{
	char	*base;
	int		count;

	count = 0;
	if (upper == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += print_hex(n / 16, upper);
	write(1, &base[n % 16], 1);
	return (count + 1);
}

int	print_p(void *ptr)
{
	unsigned long	addr;
	char			buf[16];
	char			*base;
	int				i;
	int				count;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	base = "0123456789abcdef";
	count = write(1, "0x", 2);
	i = 0;
	while (addr > 0)
	{
		buf[i++] = base[addr % 16];
		addr /= 16;
	}
	while (i--)
		count += write(1, &buf[i], 1);
	return (count);
}

int	print_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_u(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return (count + 1);
}

int	printnb(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += printnb(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
	return (count + 1);
}

int	putstr_printf(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
