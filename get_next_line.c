/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:15:24 by albriffa          #+#    #+#             */
/*   Updated: 2023/11/07 12:00:57 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_n(char *str, int b)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (b == 0)
				return (1);
			return (i++);
		}
		i++;
	}
	return (0);
}

void	*ft_new_line(int fd, char **nl)
{
	char	buf[BUFFER_SIZE];
	int	b;

	b = 0;
	while (b == 0)
	{
		if (read(fd, buf, BUFFER_SIZE) > 0)
		{
			if(!ft_realloc(nl, BUFFER_SIZE, buf))
				return (NULL);
			b = ft_find_n(buf, 0);
		}
		else
			return (NULL);
	}
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	*nl = NULL;
	char	*send;
	char	*swap;
	int	i;
	int	j;
	int	k;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &nl, 0) < 0)
		return (NULL);
	if (!ft_new_line(fd, &nl))
		return (NULL);
	if (!nl)
		return (NULL);
	i = ft_find_n(nl, 1);
	send = malloc((i + 1) * sizeof(char));
	if (!send)
		return (NULL);
	send[i] = '\0';
	j = 0;
	while (j <= i)
	{
		send[j] = nl[j];
		j++;
	}
	i = ft_strlen(nl);
	swap = malloc((i - j + 1)* sizeof(char));
	if(!swap)
		return (NULL);
	k = 0;
	while (j < i)
	{
		swap[k] = nl[j];
		k++;
		j++;
	}
	swap[k] = '\0';
	nl = swap;
	return (send);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	char	*str;

	i = 0;
	if (argc)
	{	
		fd = open(argv[1], O_RDONLY);
		while (i < 5)
		{
			str = get_next_line(fd);
			printf("%s", str);
			i++;
		}
		close(fd);
	}
}
