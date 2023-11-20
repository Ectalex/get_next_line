/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:26:25 by albriffa          #+#    #+#             */
/*   Updated: 2023/11/20 17:22:29 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	buff_erase(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buff[i] != '\n')
		i++;
	i++;
	while (j < ft_strlen(buff, 0) - i)
	{
		buff[j] = buff[i + j];
		j++;
	}
	buff[j] = '\0';
}

int	dest_free(ssize_t byte, char *dest)
{
	if (byte == -1)
	{
		free(dest);
		return (-43);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buff[128][BUFFER_SIZE + 1];
	int			byte;
	char		*dest;

	dest = NULL;
	byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 128)
		return (NULL);
	if (ft_strchr(buff[fd]) == 1)
	{
		buff_erase(buff[fd]);
		dest = ft_strjoin(dest, buff[fd]);
	}
	while (byte > 0 && ft_strchr(dest) == 0)
	{
		byte = read(fd, buff[fd], BUFFER_SIZE);
		if (byte == 0)
			return (dest);
		if (dest_free(byte, dest) == -43)
			return (0);
		buff[fd][byte] = '\0';
		dest = ft_strjoin(dest, buff[fd]);
	}
	return (dest);
}
/*
int	main(int argc, char **argv)
{
	int	fd;
	int	i = 0;

	fd = open(argv[1], O_RDONLY);
	if (argc)
	{
		while (i++ < 5)
		{
			printf("%s", get_next_line(fd));
		}
		close(fd);
	}
}*/
