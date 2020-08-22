/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:01:08 by tima              #+#    #+#             */
/*   Updated: 2020/08/22 21:17:55 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(t_map *map)
{
	int		i;
	int		j;
	int		size;
	char	**str;
	int		width;

	width = 2;
	i = 0;
	j = 0;
	size = map->size_x;
	str = map->map;
	ft_printf("Plateau: %d %d:\n", map->size_y, map->size_x);
	// PRINT COORDINATES X
	ft_printf("    ");
	while (size)
	{
		ft_printf("{3}%*d{0}", width, j);
		j++;
		if (j == 10)
			j = 0;
		size--;
	}
	ft_putchar('\n');
	// PRINT MAP
	i = 0;
	while (str[i])
	{
		j = 0;
		ft_printf("{3}%03d{0} ", i);
		while (str[i][j])
		{
			if (str[i][j] == 'O')
				ft_printf("{2}%*c{0}", width, str[i][j]);
			else if (str[i][j] == 'X')
				ft_printf("{6}%*c{0}", width, str[i][j]);
			else
				ft_printf("%*c", width, str[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	print_real_arr(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		ft_printf("%03d ", i);
		while (j < map->size_x)
		{
			if (map->arr[i][j] == -1)
				ft_printf("{6}%3d{0}", map->arr[i][j]);
			else if (map->arr[i][j] == -2)
				ft_printf("{2}%3d{0}", map->arr[i][j]);
			else if (map->arr[i][j] == -5)
				ft_printf("%3d", map->arr[i][j]);
			else
				ft_printf("%3d", map->arr[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

void	print_arr(t_map *map)
{
	int i;
	int j;
	int size;
	int **str;
	int width;

	width = 3;
	i = 0;
	j = 0;
	size = map->size_x;
	str = map->arr;
	ft_printf("<< ITS ARR >>\n");
	ft_printf("Plateau: %d %d:\n", map->size_y, map->size_x);
	// PRINT COORDINATES X
	ft_printf("    ");
	while (size)
	{
		ft_printf("{3}%*d{0}", width, j);
		j++;
		if (j == 10)
			j = 0;
		size--;
	}
	ft_putchar('\n');
	// PRINT MAP
	i = 0;
	while (i < map->size_y)
	{
		j = 0;
		ft_printf("{3}%03d{0} ", i);
		while (j < map->size_x)
		{
			if (str[i][j] == -1)
				ft_printf("{6}%*c{0}", width, 'X');
			else if (str[i][j] == -2)
				ft_printf("{2}%*c{0}", width, 'O');
			else if (str[i][j] == -5)
				ft_printf("%*c", width, '.');
			else if (str[i][j] == -10)
				ft_printf("{1}%*c{0}", width, '*');
			else
				ft_printf("%*d", width, str[i][j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	print_piece(t_piece *piece)
{
	int		i;
	char	*str;

	i = 0;
	str = piece->piece;
	ft_printf("Piece %d %d:\n", piece->size_y, piece->size_x);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		if (i % piece->size_x == 0)
			ft_putchar('\n');
	}
	ft_putchar('\n');
}

void	print_coords(t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->size_c)
	{
		ft_printf("%d: x: %d, y: %d\n", i + 1, piece->coords[i][0], piece->coords[i][1]);
		i++;
	}
}
