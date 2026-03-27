/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:06 by massah            #+#    #+#             */
/*   Updated: 2025/11/11 12:47:10 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (s);
	s = ft_memset(s, 0, size * nmemb);
	return (s);
}

/*#include <stdio.h>
int	main(void)
{
	char	*res;

	res = ft_calloc(5, 8);
	printf("%s\n", (char *)ft_calloc(5, 8));
	free(res);
	return (0);
}*/
