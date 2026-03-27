/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:18:26 by massah            #+#    #+#             */
/*   Updated: 2025/12/11 15:22:05 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new_str(char *buf)
{
	char			*tmp;
	ssize_t			len;
	unsigned int	i;

	if (!buf)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	len = ft_strlen(buf) - (i + 1);
	if (len <= 0)
	{
		free(buf);
		return (NULL);
	}
	tmp = ft_substr(buf, (i + 1), len);
	free(buf);
	return (tmp);
}

char	*ft_get_line(char *buf)
{
	char	*line;
	int		i;

	if (!buf || buf[0] == '\0')
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = malloc (i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*join_free(char *buf, char *text)
{
	char	*tmp;

	tmp = ft_strjoin(buf, text);
	free(buf);
	return (tmp);
}

char	*ft_read(int fd, char *buf)
{
	char	*text;
	ssize_t	bytes;

	if (!buf)
		buf = ft_strdup("");
	text = malloc (BUFFER_SIZE + 1);
	if (!text)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buf, '\n') && bytes > 0)
	{
		bytes = read(fd, text, BUFFER_SIZE);
		if (bytes < 0)
			return (free(text), free(buf), NULL);
		text[bytes] = '\0';
		buf = join_free(buf, text);
		if (!buf)
			return (free(text), NULL);
	}
	free(text);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_get_line(buf);
	buf = new_str(buf);
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}*/
