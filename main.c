/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:43:46 by abarthel          #+#    #+#             */
/*   Updated: 2019/05/20 17:49:40 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"

//__attribute((destructor)) void	end(void);

int main(int argc, char **argv)
{
	int ret;
	int		fd;
	char	*ptr;
	(void)argc;

	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &ptr)) > 0)
		printf("%d,%s\n",ret, ptr);
	close(fd);
	return (0);
}

//void	end(void)
//{
//	while(1);
//}
