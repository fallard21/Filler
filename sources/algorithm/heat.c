/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:32:19 by fallard           #+#    #+#             */
/*   Updated: 2020/07/12 20:32:20 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_heat_map(t_map *map, int a, int b)
{
	int i;
	int j;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			if (map->arr[i][j] == a)
				init_heat_map(map, i, j, b);
			j++;
		}
		i++;
	}
	if (check_dot(map) == 1)
		return ;
	if (a == is_player(map->enemy))
		a = 1;
	return (fill_heat_map(map, a + 1, b + 1));
}

void	init_heat_map(t_map *map, int i, int j, int b)
{
	int **tmp;

	tmp = map->arr;
	if (j > 0 && is_heating(tmp[i][j - 1]))
		tmp[i][j - 1] = b;
	if (j < map->size_x - 1 && is_heating(tmp[i][j + 1]))
		tmp[i][j + 1] = b;
	if (i < map->size_y - 1 && is_heating(tmp[i + 1][j]))
		tmp[i + 1][j] = b;
	if (i > 0 && is_heating(tmp[i - 1][j]))
		tmp[i - 1][j] = b;
	if (i < map->size_y - 1 && j < map->size_x - 1
		&& is_heating(tmp[i + 1][j + 1]))
		tmp[i + 1][j + 1] = b;
	if (i > 0 && j > 0 && is_heating(tmp[i - 1][j - 1]))
		tmp[i - 1][j - 1] = b;
	if (i < map->size_y - 1 && j > 0 && is_heating(tmp[i + 1][j - 1]))
		tmp[i + 1][j - 1] = b;
	if (i > 0 && j < map->size_x - 1 && is_heating(tmp[i - 1][j + 1]))
		tmp[i - 1][j + 1] = b;
}

int		check_dot(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			if (map->arr[i][j] == -5)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		is_heating(int n)
{
	if (n == -1 || n == -2)
		return (0);
	if (n > 0)
		return (0);
	return (1);
}
