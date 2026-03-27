/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:16:03 by massah            #+#    #+#             */
/*   Updated: 2025/11/25 13:25:35 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	print(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'd' || specifier == 'i')
		return (printnb(va_arg(ap, int)));
	else if (specifier == 'c')
		return (ft_putchar_fd((char)va_arg(ap, int), 1), 1);
	else if (specifier == 's')
		return (putstr_printf(va_arg(ap, char *)));
	else if (specifier == 'u')
		return (print_u(va_arg(ap, unsigned int)));
	else if (specifier == 'p')
		return (print_p(va_arg(ap, void *)));
	else if (specifier == 'x')
		return (print_hex(va_arg(ap, unsigned int), 0));
	else if (specifier == 'X')
		return (print_hex(va_arg(ap, unsigned int), 1));
	return (count);
}

int	detek_format(const char	*format, va_list ap)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'd' || format[i] == 'c' || format[i] == 'p'
				|| format[i] == 's' || format[i] == 'i' || format[i] == 'u'
				|| format[i] == 'x' || format[i] == 'X')
				count += print(format[i], ap);
			else
				count += write(1, &format[i], 1);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	if (!format)
		return (0);
	count = 0;
	va_start(ap, format);
	count = detek_format(format, ap);
	va_end(ap);
	return (count);
}

/*int	main(void)
{
	int	i;
	int	*I;

	i = 42;
	I = &i;
	ft_printf("%x %X %p %d %i %u %% \n", 1543, 1543, I, 425, 8, 425);
	printf("%x %X %p %d %i %u %% \n", 1543, 1543, I, 425, 8, 425);
	return (0);
}*/
