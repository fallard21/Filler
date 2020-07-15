/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:32:58 by fallard           #+#    #+#             */
/*   Updated: 2020/07/12 20:33:05 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		save_piece_size(t_map *map, t_piece *piece)
{
	char	**str;
	int		i;
	int		ret;

	if ((ret = get_next_line(0, &map->line)) < 1)
		return (1);
	if (ft_strncmp("Piece", map->line, 5) != 0)
		return (1);
	if (!(str = ft_strsplit(map->line, ' ')))
		return (1);
	ft_memdel((void**)&map->line);
	i = 0;
	while (str[i])
		i++;
	if (i < 3)
		return (free_split(&str));
	piece->size_y = ft_atoi(str[1]);
	piece->size_x = ft_atoi(str[2]);
	free_split(&str);
	return (0);
}

int		save_piece(t_map *map, t_piece *piece)
{
	char	*tmp;
	int		i;
	int		ret;

	i = 0;
	tmp = NULL;
	if (!(piece->piece = ft_strnew(0)))
		return (1);
	while (i++ < piece->size_y)
	{
		if ((ret = get_next_line(0, &map->line)) < 1)
			return (1);
		tmp = piece->piece;
		if (!(piece->piece = ft_strjoin(piece->piece, map->line)))
			return (1);
		ft_memdel((void**)&tmp);
		ft_memdel((void**)&map->line);
	}
	return (0);
}

int		get_wildc_count(t_piece *piece)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (piece->piece[i])
	{
		if (piece->piece[i] == '*')
			count++;
		i++;
	}
	return (count);
}

int		save_coords(t_piece *piece)
{
	int i;
	int j;

	i = 0;
	piece->size_c = get_wildc_count(piece);
	if (!(piece->coords = ft_memalloc(sizeof(int*) * piece->size_c)))
		return (1);
	while (i < piece->size_c)
	{
		if (!(piece->coords[i++] = ft_memalloc(sizeof(int) * 2)))
			return (1);
	}
	i = 0;
	j = 0;
	while (piece->piece[i])
	{
		if (piece->piece[i] == '*')
		{
			piece->coords[j][0] = i % piece->size_x;
			piece->coords[j][1] = i / piece->size_x;
			j++;
		}
		i++;
	}
	return (0);
}
