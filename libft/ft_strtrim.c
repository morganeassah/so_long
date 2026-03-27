/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:19:54 by massah            #+#    #+#             */
/*   Updated: 2025/11/12 18:37:49 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	is_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*t;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (is_set(set, s1[start]) && s1[start])
		start++;
	while (is_set(set, s1[end]) && end >= start)
		end--;
	t = malloc(sizeof(char) * (end - start + 2));
	if (!t)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		t[i] = s1[start];
		start++;
		i++;
	}
	t[i] = '\0';
	return (t);
}

/*#include <stdio.h>
int	main(void)
{
	char	*s1 = "AAAAAAAAAHello worldEEEEEEEEEEEEEEEEEEEEE";
	char	*set = "AE";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
