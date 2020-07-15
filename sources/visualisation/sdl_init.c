/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:27:49 by fallard           #+#    #+#             */
/*   Updated: 2020/07/12 21:08:50 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	sdl_init(t_sdl *draw)
{
	int status;

	memset(draw, 0, sizeof(t_sdl));
	status = SDL_Init(SDL_INIT_EVERYTHING);
	if (status)
	{
		ft_printf("Error initialising SDL2\n");
		exit(EXIT_FAILURE);
	}
	status = TTF_Init();
	if (status)
	{
		ft_printf("Error initialising TTF\n");
		exit(EXIT_FAILURE);
	}
	draw->window = SDL_CreateWindow("Project Filler", \
	DIS_X, DIS_Y, DIS_W, DIS_H, SDL_WINDOW_SHOWN);
	if (!draw->window)
		ft_exit(draw, 5);
	draw->rend = SDL_CreateRenderer(draw->window, -1, SDL_RENDERER_ACCELERATED);
	if (!draw->rend)
		ft_exit(draw, 6);
}

void	sdl_init_cube(t_sdl *draw, t_visu *visu)
{
	if (visu->map_y == 15)
	{
		draw->cube_rect.w = 35;
		draw->cube_rect.h = 35;
	}
	else if (visu->map_y == 24)
	{
		draw->cube_rect.w = 20;
		draw->cube_rect.h = 20;
	}
	else if (visu->map_y == 100)
	{
		draw->cube_rect.w = 8;
		draw->cube_rect.h = 7;
	}
	visu->diff_x = draw->cube_rect.w - 1;
	visu->diff_y = draw->cube_rect.h - 1;
	visu->start_x = (DIS_W - (visu->diff_x * visu->map_x)) / 2;
	draw->cube_rect.x = visu->start_x;
	draw->cube_rect.y = 150;
}

void	sdl_background(t_sdl *draw)
{
	draw->background = IMG_LoadTexture(draw->rend, BACKGROUND);
	if (!draw->background)
		ft_exit(draw, 7);
	draw->back_rect.x = 0;
	draw->back_rect.y = 0;
	draw->back_rect.h = DIS_H;
	draw->back_rect.w = DIS_W;
	SDL_RenderCopy(draw->rend, draw->background, NULL, &draw->back_rect);
	SDL_RenderPresent(draw->rend);
}

void	sdl_title(t_sdl *d)
{
	if (!(d->font = TTF_OpenFont(TITLE, 200)))
		ft_exit(d, 1);
	d->color = (SDL_Color){0, 220, 20, 1};
	if (!(d->area = TTF_RenderText_Blended(d->font, "Filler", d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	d->font_rect.w = 6 * 40;
	d->font_rect.h = 100;
	d->font_rect.x = (DIS_W / 2) - (d->font_rect.w / 2);
	d->font_rect.y = DIS_H * 0.01;
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
	TTF_CloseFont(d->font);
	d->font = NULL;
}
