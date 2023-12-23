/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:58:38 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/23 19:41:15 by moel-fat         ###   ########.fr       */
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

char	*checknewline(char **save, char *buffer, char *newline_pos)
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
	if (count < 0)
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
	static char	*save;
	char		*buffer;
	char		*newline_pos;
	char		*line;
	ssize_t		count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(save), save = NULL, NULL);
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(save), save = NULL, NULL);
	newline_pos = NULL;
	line = NULL;
	if (save && (newline_pos = strchr(save, '\n')))
		return (line = checknewline(&save, buffer, newline_pos));
	while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[count] = '\0';
		save = ft_strjoin(save, buffer);
		if (!save)
			return (free(buffer), save = NULL, NULL);
		if ((newline_pos = ft_strchr(save, '\n')))
			return (line = checknewline(&save, buffer, newline_pos));
	}
	return (ft_return(&count, &save, &line, &buffer));
}
