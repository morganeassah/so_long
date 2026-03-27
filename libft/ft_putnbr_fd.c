/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:47:52 by massah            #+#    #+#             */
/*   Updated: 2025/11/13 17:06:49 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar('-', fd);
		n = -n;
	}
	if (n >= 0 && n <= 9)
		ft_putchar((n + '0'), fd);
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar((n % 10 + '0'), fd);
	}
}

/*int	main(void)
{
	ft_putnbr_fd(2147483647, 1);
	return (0);
}*/
