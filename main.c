/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:11:29 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/20 17:32:45 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

void	f(void)
{
	
}
int	main(void)
{
	int fd = open("test.txt",  O_RDONLY);
	char *s;
	// while(s)
	// {
	// 	printf("%s", s);
	// 	free(s);
	// 	s = get_next_line(fd);
	// }
	int i;
	i = 1;
	s = get_next_line(fd);
	while(s)
	{
		printf("%d:==> %s",i, s);
		// free(s);
		i++;
		s = get_next_line(fd);
	}
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	free(s);
	close(fd);
}