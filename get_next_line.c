/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:15:24 by albriffa          #+#    #+#             */
/*   Updated: 2023/11/04 19:18:06 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	len;
	size_t	i;
	size_t	k;
	char	*buff;
	char	*str;

	i = 0;
	len = 0;
	str = malloc(36);
	buff = malloc(BUFFER_SIZE);
	while (i < 36)
	{
		k = 0;
		len += read(fd, buff, BUFFER_SIZE);
		printf ("\nvaleur : %d\n", len);
		while (i < len)
		{
			str[i] = buff[k];
			i++;
			k++;
		}
		printf("\nTEST : %s\n", str);
	}
	free(buff);
	return (str);
}

int	main()
{
	char	*str;
	int	fd;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("\nFINAL : %s", str);
	free(str);
}
