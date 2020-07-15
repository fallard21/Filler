/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:31:49 by fallard           #+#    #+#             */
/*   Updated: 2020/07/12 20:31:50 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		solve(t_map *map, t_piece *piece)
{
	piece->shift = 0;
	while (piece->shift < map->size_x * map->size_y)
	{
		if (check_coords(map, piece, piece->shift))
		{
			if (is_one_contact(map, piece, piece->shift))
				sum_piece(map, piece, piece->shift);
		}
		piece->shift++;
	}
	ft_printf("%d %d\n", map->fin_y, map->fin_x);
	if (map->fin_sh == -1)
		return (1);
	return (0);
}

int		check_coords(t_map *map, t_piece *piece, int shift)
{
	int x;
	int y;
	int i;

	if (piece->size_x - 1 + shift % map->size_x >= map->size_x)
		return (0);
	if (piece->size_y - 1 + shift / map->size_x >= map->size_y)
		return (0);
	i = 0;
	while (i < piece->size_c)
	{
		x = piece->coords[i][0] + shift % map->size_x;
		y = piece->coords[i][1] + shift / map->size_x;
		if (x >= map->size_x)
			return (0);
		if (y >= map->size_y)
			return (0);
		i++;
	}
	return (1);
}

int		is_one_contact(t_map *map, t_piece *piece, int shift)
{
	int i;
	int count;
	int x;
	int y;

	count = 0;
	i = 0;
	while (i < piece->size_c)
	{
		x = piece->coords[i][0] + shift % map->size_x;
		y = piece->coords[i][1] + shift / map->size_x;
		if (map->arr[y][x] == is_player(map->me))
			count++;
		if (map->arr[y][x] == is_player(map->enemy))
			return (0);
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

void	sum_piece(t_map *map, t_piece *piece, int shift)
{
	int i;
	int sum;
	int x;
	int y;

	sum = 0;
	i = 0;
	while (i < piece->size_c)
	{
		x = piece->coords[i][0] + shift % map->size_x;
		y = piece->coords[i][1] + shift / map->size_x;
		if (map->arr[y][x] > 0)
			sum = sum + map->arr[y][x];
		i++;
	}
	if (sum < map->sum)
	{
		map->fin_x = shift % map->size_x;
		map->fin_y = shift / map->size_x;
		map->fin_sh = shift;
		map->sum = sum;
	}
}
