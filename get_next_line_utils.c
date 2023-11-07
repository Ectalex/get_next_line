/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:11:15 by albriffa          #+#    #+#             */
/*   Updated: 2023/11/07 11:59:42 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_realloc(char **str, size_t new_len, char *buf)
{
	char	*new_str;
	int	i;

	if (new_len == 0)
	{
		free(*str);
		return (NULL);
	}
	if (*str)
		i = ft_strlen(*str);
	else
		i = 0;
	new_str = malloc((i + new_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, *str, buf);
	free(*str);
	*str = new_str;
	return (str);
}

char	*ft_strcpy(char *dest, char *src, char *buf)
{
	int	i;
	int	j;

	i = 0;
	if (src)
	{
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
	}
	j = 0;
	if (buf)
	{
		while (j < BUFFER_SIZE)
		{
			dest[i] = buf[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
