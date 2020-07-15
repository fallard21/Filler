/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:31:21 by fallard           #+#    #+#             */
/*   Updated: 2020/07/12 20:41:17 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int	vis_size_map(t_visu *visu)
{
	char	**str;
	int		ret;

	if ((ret = get_next_line(0, &visu->line)) < 1)
		return (1);
	if (ft_strncmp(visu->line, "Plateau", 7) != 0)
		return (1);
	if (!(str = ft_strsplit(visu->line, ' ')))
		return (1);
	ft_memdel((void**)&visu->line);
	if ((ret = get_next_line(0, &visu->line)) < 1)
	{
		vis_free_split(&str);
		return (1);
	}
	ft_memdel((void**)&visu->line);
	visu->map_x = ft_atoi(str[2]);
	visu->map_y = ft_atoi(str[1]);
	vis_free_split(&str);
	return (0);
}

int	vis_read_map(t_visu *visu)
{
	int		ret;
	int		i;

	i = 0;
	visu->line = NULL;
	while (i < visu->map_y)
	{
		if ((ret = get_next_line(0, &visu->line)) < 1)
			return (1);
		if (save_line(visu, visu->line, i))
			return (1);
		ft_memdel((void **)&visu->line);
		i++;
	}
	return (0);
}

int	save_line(t_visu *visu, char *line, int i)
{
	int	j;
	int	len;

	if (!line)
		return (1);
	len = ft_strlen(line);
	if (len != visu->map_x + 4)
		return (1);
	line = line + 4;
	j = 0;
	while (j < visu->map_x)
	{
		visu->map[i][j] = line[j];
		j++;
	}
	return (0);
}
