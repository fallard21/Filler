/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:30:24 by fallard           #+#    #+#             */
/*   Updated: 2020/07/12 16:30:28 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	initialisation(t_map *map, t_piece *piece)
{
	map->map = NULL;
	map->arr = NULL;
	map->size_x = 0;
	map->size_y = 0;
	map->sum = 100000;
	map->fin_x = 0;
	map->fin_y = 0;
	map->fin_sh = -1;
	map->line = NULL;
	map->me = 0;
	map->enemy = 0;
	piece->piece = NULL;
	piece->size_x = 0;
	piece->size_y = 0;
	piece->coords = NULL;
	piece->size_c = 0;
	piece->shift = 0;
}

void	reinitialisation(t_map *map, t_piece *piece)
{
	map->map = NULL;
	map->arr = NULL;
	map->size_x = 0;
	map->size_y = 0;
	map->sum = 100000;
	map->fin_x = 0;
	map->fin_y = 0;
	map->fin_sh = -1;
	map->line = NULL;
	piece->piece = NULL;
	piece->size_x = 0;
	piece->size_y = 0;
	piece->coords = NULL;
	piece->size_c = 0;
	piece->shift = 0;
}

int		main(void)
{
	t_map	map;
	t_piece	piece;

	initialisation(&map, &piece);
	if (get_player(&map) == 1)
		return (1);
	while (1)
	{
		reinitialisation(&map, &piece);
		if (get_play_board(&map, &piece) == 1)
			break ;
		if (go_playing(&map, &piece) == 1)
			break ;
		free_all_memory(&map, &piece);
	}
	free_all_memory(&map, &piece);
	return (0);
}
