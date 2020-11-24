/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:34:56 by fallard           #+#    #+#             */
/*   Updated: 2020/11/24 17:27:26 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	sdl_prepare_map(t_sdl *draw, t_visu *visu)
{
	int i;

	i = 0;
	while (i < visu->map_y)
	{
		draw_line(draw, visu, i);
		draw->cube_rect.y += visu->diff_y;
		i++;
	}
	SDL_RenderPresent(draw->rend);
}

void	draw_line(t_sdl *draw, t_visu *visu, int i)
{
	int j;

	j = 0;
	draw->cube_rect.x = visu->start_x;
	while (j < visu->map_x)
	{
		if (visu->map[i][j] == '.')
			SDL_SetRenderDrawColor(draw->rend, 200, 200, 200, 255);
		else if (visu->map[i][j] == 'o')
			SDL_SetRenderDrawColor(draw->rend, 0, 27, 255, 255);
		else if (visu->map[i][j] == 'x')
			SDL_SetRenderDrawColor(draw->rend, 255, 190, 0, 255);
		else if (visu->map[i][j] == 'O')
			SDL_SetRenderDrawColor(draw->rend, 0, 70, 200, 255);
		else if (visu->map[i][j] == 'X')
			SDL_SetRenderDrawColor(draw->rend, 230, 120, 0, 255);
		SDL_RenderFillRect(draw->rend, &draw->cube_rect);
		SDL_SetRenderDrawColor(draw->rend, 0, 0, 0, 255);
		SDL_RenderDrawRect(draw->rend, &draw->cube_rect);
		j++;
		draw->cube_rect.x += visu->diff_x;
	}
}

void	draw_line_1(t_sdl *draw, t_visu *visu, int i)
{
	int j;

	j = 0;
	draw->cube_rect.x = visu->start_x;
	while (j < visu->map_x)
	{
		if (visu->map[i][j] == 'o')
			SDL_SetRenderDrawColor(draw->rend, 0, 27, 255, 1);
		else if (visu->map[i][j] == 'x')
			SDL_SetRenderDrawColor(draw->rend, 255, 190, 0, 1);
		else if (visu->map[i][j] == 'O')
			SDL_SetRenderDrawColor(draw->rend, 0, 70, 200, 1);
		else if (visu->map[i][j] == 'X')
			SDL_SetRenderDrawColor(draw->rend, 230, 120, 0, 1);
		if (visu->map[i][j] != '.')
		{
			SDL_RenderFillRect(draw->rend, &draw->cube_rect);
			SDL_SetRenderDrawColor(draw->rend, 0, 0, 0, 1);
			SDL_RenderDrawRect(draw->rend, &draw->cube_rect);
		}
		j++;
		draw->cube_rect.x += visu->diff_x;
	}
}
