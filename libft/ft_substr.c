/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:51:28 by massah            #+#    #+#             */
/*   Updated: 2025/11/11 19:19:15 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*d;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = (char)s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*#include <stdio.h>
int	main(void)
{
	char	*s = "Hello";
	unsigned int	start = 2;
	size_t	len = 3;

	printf("%s\n", ft_substr(s, start, len));
	return (0);
}*/
