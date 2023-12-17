/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:15:11 by moel-fat          #+#    #+#             */
/*   Updated: 2023/12/16 15:36:40 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
int	main(void)
{
	char s[10];
	
	int fd = open("test.txt",  O_RDWR | O_CREAT);
	size_t i = read(fd,s,10);
	ft_strchr(s,"\n");
	printf("%s",s);
}
