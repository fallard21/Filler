/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 15:57:48 by tima              #+#    #+#             */
/*   Updated: 2020/06/20 02:01:00 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		save_map(t_map *map)
{
	int	i;
	int ret;

	if ((ret = get_next_line(0, &map->line)) < 1)
		return (1);
	ft_memdel((void**)&map->line);
	if (!(map->map = ft_memalloc(sizeof(char*) * (map->size_y + 1))))
		return (1);
	i = 0;
	while (i < map->size_y)
	{
		if ((ret = get_next_line(0, &map->line)) < 1)
			return (1);
		if (ft_strlen(map->line) < 5)
			return (1);
		toupper_player(map->line + 4, map->enemy);
		map->map[i] = ft_strdup(map->line + 4);
		i++;
		ft_memdel((void**)&map->line);
	}
	return (0);
}

int		save_map_size(t_map *map)
{
	char	**str;
	int		i;
	int		ret;
	
	i = 0;
	ret = get_next_line(0, &map->line);
	if (ret <= 0)
		return (1);
	if (ft_strncmp("Plateau", map->line, 7) != 0)
		return (1);
	if (!(str = ft_strsplit(map->line, ' ')))
		return (1);
	ft_memdel((void**)&map->line);
	while (str[i])
		i++;
	if (i < 3)
		return (free_split(&str));
	map->size_y = ft_atoi(str[1]);
	map->size_x = ft_atoi(str[2]);
	free_split(&str);
	return (0);
}

int		convert_map(t_map *map)
{
	int i;
	int j;

	if (!(map->arr = ft_memalloc(sizeof(int*) * map->size_y)))
		return (1);
	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		if (!(map->arr[i] = ft_memalloc(sizeof(int) * map->size_x)))
			return (1);
		while (j < map->size_x)
		{
			if (map->map[i][j] == 'X')
				map->arr[i][j] = (map->me == 'O') ? -1 : -5;
			if (map->map[i][j] == 'O')
				map->arr[i][j] = (map->me == 'X') ? -2 : -5;
			if (map->map[i][j] == '.')
				map->arr[i][j] = -5;
			j++;
		}
		i++;
	}
	return (0);
}

void	toupper_player(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ft_tolower(c))
			str[i] = ft_toupper(str[i]);
		i++;
	}
}
