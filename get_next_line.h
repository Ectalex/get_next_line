/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albriffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:01:43 by albriffa          #+#    #+#             */
/*   Updated: 2023/11/07 11:53:56 by albriffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int	ft_find_n(char *str, int b);
void	*ft_new_line(int fd, char **nl);
int	ft_strlen(char *str);
void	*ft_realloc(char **str, size_t new_len, char *buf);
char	*ft_strcpy(char *dest,char *src, char *buf);

#endif
