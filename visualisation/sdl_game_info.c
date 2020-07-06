/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_game_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 01:04:14 by tima              #+#    #+#             */
/*   Updated: 2020/07/07 00:19:53 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		vis_game_info(t_visu *visu)
{
	int i;

	ft_memset(visu, 0, sizeof(t_visu));
	if (vis_getplayer(visu) == 1)
		return (1);
	if (vis_size_map(visu) == 1)
		return (1);
	if (!(visu->map = ft_memalloc(sizeof(int*) * visu->map_y)))
		return (1);
	i = 0;
	while (i < visu->map_y)
	{
		if (!(visu->map[i++] = ft_memalloc(sizeof(int) * visu->map_x)))
			return (1);
	}
	return (0);
}

int		vis_getplayer(t_visu *visu)
{
	int		i;
	int		ret;

	i = 0;
	while (i < 9)
	{
		if ((ret = get_next_line(0, &visu->line)) < 1)
			return (1);
		if (ft_strstr(visu->line, "exec p1"))
			visu->player1 = ft_strdup(ft_strrchr(visu->line, '/') + 1);
		if (ft_strstr(visu->line, "exec p2"))
			visu->player2 = ft_strdup(ft_strrchr(visu->line, '/') + 1);
		ft_memdel((void**)&visu->line);
		i++;
	}
	visu->player1 = vis_parse_player("player 1: ", visu->player1);
	visu->player2 = vis_parse_player("player 2: ", visu->player2);
	if (!visu->player1 || !visu->player2)
		return (1);
	return (0);
}

char	*vis_parse_player(const char *p, char *player)
{
	char	*res;
	char	*dot;
	int		len;
	int		k;

	if (!player)
		return (NULL);
	if (!(dot = ft_strchr(player, '.')))
		return (NULL);
	k = dot - player;
	player[k] = '\0';
	len = ft_strlen(player) + 10 + 1;
	if (!(res = ft_memalloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(res, p);
	ft_strcat(res, player);
	free(player);
	return (res);
}
