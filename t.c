#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
# define BUFFER_SIZE 5
char    *ft_strjoin(char *s1, char *s2)
{
    size_t    s1len;
    size_t    s2len;
    char    *s;
    if (s1 == NULL && s2 == NULL)
        return (NULL);
    if (s1 == NULL)
        return (strdup(s2));
    if (s2 == NULL)
        return (strdup(s1));
    s1len = strlen(s1);
    s2len = strlen(s2);
    s = (char *)malloc((s1len + s2len + 1) * (sizeof(char)));
    if (s == NULL)
        return (NULL);
    strcpy(s, s1);
    strcpy(s + s1len, s2);
    return (s);
}
char    *get_next_line(int fd)
{
    char    *res;
    char    *line = NULL;
    char    buffer[BUFFER_SIZE + 1];
    char    *tmp;
    static char    *saved = NULL;
    char    *newline_pos;
    if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
        return (NULL);
    if (saved != NULL)
    {
        res = strchr(saved, '\n');
        if (res && *(res + 1) != '\0')
        {
            size_t j = res - saved + 1;
            char *s = malloc(strlen(saved) - j + 1);
            if (s == NULL)
                return (NULL);
            size_t    i = 0;
            while (saved[i] != '\n')
            {
                s[i] = saved[i];
                i++;
            }
            s[i] = '\n';
            line = ft_strjoin(line, s);
            saved = res + 1;
            return (line);
        }
        else
        {
            line = ft_strjoin(line, saved);
            saved = NULL;
        }
    }
    tmp = malloc(BUFFER_SIZE + 1);
    if (!tmp)
        return (NULL);
    while (ssize_t count = read(fd, buffer, BUFFER_SIZE) > 0)
    {
        buffer[count] = '\0';
        newline_pos = strchr(buffer, '\n');
        if (!newline_pos)
        {
            strcpy(tmp, buffer);
            line = ft_strjoin(line, tmp);
        }
        else
        {
            strncpy(tmp, buffer, newline_pos - buffer + 1);
            tmp[newline_pos - buffer + 1] = '\0';
            if (*(newline_pos + 1) != '\0')
                saved = strdup(newline_pos + 1);
            else
                saved = NULL;
            line = ft_strjoin(line, tmp);
        }
        if (strchr(buffer, '\n'))
            break ;
    }
    return (line);
}
