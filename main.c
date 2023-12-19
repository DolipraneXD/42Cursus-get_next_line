/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:11:29 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/19 21:57:51 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

int	main(void)
{
	int fd = open("test.txt",  O_RDONLY);
	char *s = get_next_line(fd);
	while(s)
	{
		printf("%s", s);
		free(s);
		s = get_next_line(fd);
	}
	// printf("%s", s);
	// s = get_next_line(fd);
	// printf("%s", s);
	// s = get_next_line(fd);
	// printf("%s", s);
	free(s);
}