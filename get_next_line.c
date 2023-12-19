/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:58:38 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/19 22:17:51 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char	*save = NULL;
    // char		buffer[BUFFER_SIZE + 1];
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
        line = strndup(save, newline_pos - save +1);
        temp = strdup(newline_pos + 1);
        free(save);
        save = temp;
		free(buffer);
        return line;
    }
    while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[count] = '\0';
        save = ft_strjoin(save, buffer);
        if ((newline_pos = strchr(save, '\n')))
        {
            line = strndup(save, newline_pos - save +1);
            temp = strdup(newline_pos + 1);
            free(save);
            save = temp;
			free(buffer);
            return line;
        }
    }

    if (save && *save)
    {
        line = strdup(save);
        free(save);
        save = NULL;
		free(buffer);
        return line;
    }

    return NULL;
}
