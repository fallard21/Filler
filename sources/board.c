/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 23:46:15 by tima              #+#    #+#             */
/*   Updated: 2020/06/20 01:59:57 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(t_map *map)
{
	char	*player;
	int		ret;

    player = NULL;
	if ((ret = get_next_line(0, &player)) < 1)
	{
		ft_memdel((void**)&player);
		return (1);
	}
	if (ft_strstr(player, "p1"))
	{
		map->me = 'O'; // -2
		map->enemy = 'X'; // -1
	}
	else if (ft_strstr(player, "p2"))
	{
		map->me = 'X'; // -1
		map->enemy = 'O'; // -2
	}
	ft_memdel((void**)&player);
	if (!map->me || !map->enemy)
		return (1);
	return (0);
}

int		get_play_board(t_map *map, t_piece *piece)
{
	if (save_map_size(map) == 1)
		return (end_program(map, piece));
	if (save_map(map) == 1)
		return (end_program(map, piece));
	if (save_piece_size(map, piece) == 1)
		return (end_program(map, piece));
	if (save_piece(map, piece) == 1)
		return (end_program(map, piece));
	return (0);
}

int		go_playing(t_map *map, t_piece* piece)
{
	if (convert_map(map) == 1)
		return (end_program(map, piece));
		//print_arr(map);
	fill_heat_map(map, is_player(map->enemy), 2);
		//print_arr(map);
	back_player(map);
		//print_arr(map);
	if (save_coords(piece) == 1)
		return (end_program(map, piece));
	if (solve(map, piece) == 1)
		return (1);
	return (0);
}

void	back_player(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			if (map->map[i][j] == map->me)
				map->arr[i][j] = is_player(map->me);
			j++;
		}
		i++;
	}
}

int		is_player(int c)
{
	if (c == 'X')
		return (-1);
	else if (c == 'O')
		return (-2);
	else
		return (0);
}
