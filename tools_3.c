/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagudelo <dagudelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:30:03 by dagudelo          #+#    #+#             */
/*   Updated: 2024/04/12 12:51:24 by dagudelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	check_total_coins(t_data *data)
{
	if (data->total_coins == 0)
	{
		end_process_check(data, "There is no coins in the map\n");
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}

size_t	malloc_size(void *ptr)
{
	size_t	*size_ptr;

	if (!ptr)
		return (0);
	size_ptr = (size_t *)((char *)ptr - sizeof(size_t));
	return (*size_ptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	size_t	old_size;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(size));
	old_size = malloc_size(ptr);
	if (size <= old_size)
		return (ptr);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

void	check_game_setup(t_data *data)
{
	check_rows_symetrie(data);
	check_closed_map(data);
	total_coins_count(data);
}
