/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:58:46 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/19 22:10:27 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;
	char	*ss;
	size_t	i;

	ss = (char *) s;
	d = (char) c;
	i = 0;
	while (ss[i])
	{
		if (ss[i] != d)
			i++;
		else
			return (&ss[i]);
	}
	if (d == '\0')
	{
		return (&ss[i]);
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
	{
		return (srclen);
	}
	else
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (srclen);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	tlen;
	char	*s;

	if (s1 == NULL)
		return (strdup(s2));
	if (s2 == NULL)
		return (strdup(s1));
	tlen = ft_strlen(s1) + ft_strlen(s2) +1;
	s = (char *) malloc (tlen);
	if (s == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ft_strlcpy(s, s1, tlen);
	ft_strlcpy(s + ft_strlen(s1), s2, tlen);
	free(s1);
	return (s);
}

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
