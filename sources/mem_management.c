/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 04:48:50 by tima              #+#    #+#             */
/*   Updated: 2020/06/12 15:12:12 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		end_program(t_map *map, t_piece *piece)
{
	free_all_memory(map, piece);
	return (1);
}

void	free_all_memory(t_map *map, t_piece *piece)
{
	int i;

	if (map->map)
		free_split(&map->map);
	i = 0;
	if (map->arr)
	{
		while (i < map->size_y)
			ft_memdel((void **)&map->arr[i++]);
		ft_memdel((void **)&map->arr);
	}
	i = 0;
	if (piece->coords)
	{
		while (i < piece->size_c)
			ft_memdel((void **)&piece->coords[i++]);
		ft_memdel((void **)&piece->coords);
	}
	ft_memdel((void **)&piece->piece);
	ft_memdel((void**)&map->line);
}

int		free_split(char ***str)
{
	int i;

	i = 0;
	if (*str == (void*)0)
		return (1);
	while ((*str)[i])
	{
		ft_memdel((void**)&(*str)[i]);
		i++;
	}
	ft_memdel((void**)&(*str));
	return (1);
}
