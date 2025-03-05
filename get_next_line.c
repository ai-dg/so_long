/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:11:41 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/04 15:19:47 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*str;

	if (fd == -1 || BUFFER_SIZE <= 0 || fd >= 10)
		return (NULL);
	tmp = ft_read(fd, tmp);
	if (!tmp)
		return (NULL);
	str = ft_line(tmp);
	tmp = ft_tmp(tmp);
	return (str);
}

char	*ft_read(int fd, char *tmp)
{
	char	*buffer;
	int		read_nbr;

	read_nbr = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(buffer);
		free(tmp);
		return (NULL);
	}
	while (!ft_strchr_gnl(tmp, '\n') && read_nbr != 0)
	{
		read_nbr = read(fd, buffer, BUFFER_SIZE);
		if (read_nbr == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_nbr] = '\0';
		tmp = ft_strjoin_gnl(tmp, buffer);
	}
	free(buffer);
	return (tmp);
}

char	*ft_line(char *tmp)
{
	int		i;
	char	*str;
	int		j;

	i = 0;
	if (!tmp || !*tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		str = (char *)malloc(sizeof(char) * (i + 2));
	else
		str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = tmp[j];
		j++;
	}
	if (tmp[i] == '\n')
		str[j++] = '\n';
	str[j] = '\0';
	return (str);
}

char	*ft_tmp(char *tmp)
{
	int		len;
	char	*str;
	int		x;
	int		y;

	len = 0;
	if (!tmp)
		return (NULL);
	while (tmp[len] && tmp[len] != '\n')
		len++;
	if (!tmp[len])
	{
		free(tmp);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(tmp) - len));
	if (!str)
		return (NULL);
	x = len + 1;
	y = 0;
	while (tmp[x])
		str[y++] = tmp[x++];
	str[y] = '\0';
	free(tmp);
	return (str);
}
