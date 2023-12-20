/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:58:38 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/20 18:50:38 by moel-fat         ###   ########.fr       */
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

char *get_next_line(int fd)
{
    static char	*save = NULL;
	char		*buffer;
    char		*newline_pos;
	char		*temp;
	char		*line;
    ssize_t		count;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return NULL;
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return NULL;
	newline_pos = NULL;
	temp = NULL;
	line = NULL;
	count = 0;
	
    if (save && (newline_pos = strchr(save, '\n')))
    {
        line = ft_strndup(save, newline_pos - save + 1);
        temp = ft_strdup(newline_pos + 1);
        free(save);
        save = temp;
		free(buffer);
        return (line);
    }
    while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[count] = '\0';
        save = ft_strjoin(save, buffer);
        if ((newline_pos = ft_strchr(save, '\n')))
        {
            line = ft_strndup(save, newline_pos - save + 1);
            temp = ft_strdup(newline_pos + 1);
            free(save);
            save = temp;
			free(buffer);
            return (line);
        }
    }
    if (save && *save)
    {
        line = ft_strdup(save);
        free(save);
        save = NULL;
		free(buffer);
        return (line);
    }
	free(buffer);
    return (NULL);
}
