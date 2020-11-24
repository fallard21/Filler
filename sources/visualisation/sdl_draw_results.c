/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_draw_results.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:27:13 by fallard           #+#    #+#             */
/*   Updated: 2020/11/24 17:28:13 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	draw_results(t_sdl *draw, t_visu *visu)
{
	char	*win;
	int		len;

	if (visu->score1 > visu->score2)
		win = ft_strjoin(visu->player1, " won!");
	else if (visu->score1 < visu->score2)
		win = ft_strjoin(visu->player2, " won!");
	else
		win = ft_strdup("Draw!");
	if (win == NULL)
		ft_exit(draw, 3);
	len = ft_strlen(win);
	if (!(draw->font = TTF_OpenFont(RESULTS, 200)))
		ft_exit(draw, 1);
	draw_winner(draw, win, len);
	draw_scores(draw, visu);
	free(win);
	TTF_CloseFont(draw->font);
	draw->font = NULL;
}

void	draw_winner(t_sdl *d, char *win, int len)
{
	d->font_rect.w = len * 20;
	d->font_rect.h = 40;
	d->font_rect.x = (DIS_W / 2) - (d->font_rect.w / 2);
	d->font_rect.y = DIS_H * 0.93;
	d->color = (SDL_Color){0, 0, 0, 255};
	if (!(d->area = TTF_RenderText_Blended(d->font, win, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
	TTF_SetFontOutline(d->font, 4);
	d->color = (SDL_Color){255, 255, 0, 255};
	if (!(d->area = TTF_RenderText_Blended(d->font, win, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
}

void	draw_scores(t_sdl *d, t_visu *visu)
{
	char	*sc1;
	char	*sc2;

	sc1 = ft_itoa(visu->score1);
	sc2 = ft_itoa(visu->score2);
	sc1 = ft_strjoin_free("p1 = ", sc1, 2);
	sc2 = ft_strjoin_free("p2 = ", sc2, 2);
	if (!sc1 || !sc2)
		ft_exit(d, 4);
	d->font_rect.h = 40;
	d->font_rect.y = DIS_H / 2;
	d->color = (SDL_Color){255, 255, 0, 255};
	draw_scores_2(d, sc1, sc2);
	free(sc1);
	free(sc2);
}

void	draw_scores_2(t_sdl *d, char *s1, char *s2)
{
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	d->font_rect.w = len1 * 20;
	d->font_rect.x = 70;
	if (!(d->area = TTF_RenderText_Blended(d->font, s1, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
	d->font_rect.w = len2 * 20;
	d->font_rect.x = DIS_W - 70 - d->font_rect.w;
	if (!(d->area = TTF_RenderText_Blended(d->font, s2, d->color)))
		ft_exit(d, 2);
	if (!(d->fontex = SDL_CreateTextureFromSurface(d->rend, d->area)))
		ft_exit(d, 3);
	SDL_RenderCopy(d->rend, d->fontex, NULL, &d->font_rect);
	sdl_memdel(&d->area, &d->fontex);
}
