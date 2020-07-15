/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:38:28 by fallard           #+#    #+#             */
/*   Updated: 2020/07/12 19:38:32 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_players(t_sdl *draw, t_visu *visu)
{
	int len1;
	int len2;

	len1 = ft_strlen(visu->player1);
	len2 = ft_strlen(visu->player2);
	if (!(draw->font = TTF_OpenFont(PLAYERS, 200)))
		ft_exit(draw, 1);
	draw->font_rect.h = 45;
	draw->font_rect.y = DIS_H * 0.11;
	draw_fill(draw, visu, len1, len2);
	draw_curcuit(draw, visu, len1, len2);
	TTF_CloseFont(draw->font);
	draw->font = NULL;
}

void	draw_fill(t_sdl *d, t_visu *visu, int len1, int len2)
{
	d->font_rect.w = len1 * 15;
	d->font_rect.x = 50;
	d->color = (SDL_Color){0, 70, 200, 1};
	if (!(d->area = TTF_RenderText_Blended(d->font, visu->player1, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
	d->font_rect.w = len2 * 15;
	d->font_rect.x = DIS_W - 50 - d->font_rect.w;
	d->color = (SDL_Color){230, 120, 0, 1};
	if (!(d->area = TTF_RenderText_Blended(d->font, visu->player2, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
}

void	draw_curcuit(t_sdl *d, t_visu *visu, int len1, int len2)
{
	d->font_rect.w = len1 * 15;
	d->font_rect.x = 50;
	d->color = (SDL_Color){0, 0, 0, 1};
	TTF_SetFontOutline(d->font, 3);
	if (!(d->area = TTF_RenderText_Blended(d->font, visu->player1, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
	d->font_rect.w = len2 * 15;
	d->font_rect.x = DIS_W - 50 - d->font_rect.w;
	if (!(d->area = TTF_RenderText_Blended(d->font, visu->player2, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
}
