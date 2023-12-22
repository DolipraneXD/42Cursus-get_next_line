/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:11:29 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/22 16:22:58 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "get_next_line.h"

void	f(void)
{
	system("leaks a.out");
}
int	main(void)
{
	atexit(f);
	int fd = open("test.txt",  O_RDONLY);
	char *s;
	int i;
	i = 1;
	s = get_next_line(fd);
	while(s)
	{
		printf("%d:==> %s",i, s);
		free(s);
		i++;
		s = get_next_line(fd);
	}
	if (s)
		free(s);
	close(fd);
}