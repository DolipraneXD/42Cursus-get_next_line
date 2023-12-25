/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 14:45:33 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/25 17:39:12 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*checknl(char **save, char *buffer, char *newline_pos)
{
	char	*temp;
	char	*line;

	temp = NULL;
	line = NULL;
	line = ft_strndup(*save, newline_pos - *save + 1);
	if (!line)
		return (free(buffer), free(*save), *save = NULL, NULL);
	temp = ft_strdup(newline_pos + 1);
	if (!temp)
		return (free(buffer), free(line), free(*save), *save = NULL, NULL);
	free(*save);
	*save = temp;
	free(buffer);
	return (line);
}

char	*ft_return(ssize_t *count, char **save, char **line, char **buffer)
{
	if (*count < 0)
		return (free(*buffer), free(*save), *save = NULL, NULL);
	if (*save && **save)
	{
		*line = ft_strdup(*save);
		if (!*line)
			return (free(*buffer), free(*save), *save = NULL, NULL);
		return (free(*save), *save = NULL, free(*buffer), *line);
	}
	if (!*line && *count == 0)
		return (free(*save), free(*buffer), *save = NULL, *save);
	return (free(*buffer), NULL);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buffer;
	char		*line;
	ssize_t		count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(save[fd]), save[fd] = NULL, NULL);
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(save[fd]), save[fd] = NULL, NULL);
	line = NULL;
	count = 1;
	if (save[fd] && strchr(save[fd], '\n'))
		return (line = checknl(&save[fd], buffer, strchr(save[fd], '\n')));
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
		save[fd] = ft_strjoin(save[fd], buffer);
		if (!save[fd])
			return (free(buffer), save[fd] = NULL, NULL);
		if (ft_strchr(save[fd], '\n'))
			return (line = checknl(&save[fd], buffer, strchr(save[fd], '\n')));
	}
	return (ft_return(&count, &save[fd], &line, &buffer));
}
