/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:24:36 by tima              #+#    #+#             */
/*   Updated: 2020/07/07 00:26:16 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	sdl_main_loop(t_sdl *d, t_visu *visu)
{
	d->keyboard = SDL_GetKeyboardState(NULL);
	d->quit = 0;
	d->flag = 1;
	while (!d->quit)
	{
		while (SDL_PollEvent(&d->event))
		{
			if (d->event.type == SDL_QUIT || d->keyboard[SDL_SCANCODE_ESCAPE])
				d->quit = 1;
			if (d->keyboard[SDL_SCANCODE_RIGHT] && d->flag == 1)
				sdl_move_right(d, visu);
		}
	}
}

void	sdl_move_right(t_sdl *d, t_visu *visu)
{
	int i;

	i = 0;
	if (vis_skip_token(visu) == 1)
		d->flag = 0;
	if (d->flag)
		vis_read_map(visu);
	d->cube_rect.y = 150;
	while (i < visu->map_y)
	{
		draw_line_1(d, visu, i);
		d->cube_rect.y += visu->diff_y;
		i++;
	}
	if (!d->flag)
		draw_results(d, visu);
	SDL_RenderPresent(d->rend);
}

int		vis_skip_token(t_visu *visu)
{
	int ret;

	while (1)
	{
		if ((ret = get_next_line(0, &visu->line)) < 1)
			exit(1);
		if (ft_strstr(visu->line, "0123456789"))
			break ;
		if (ft_strstr(visu->line, "O fin"))
			visu->score1 = atoi(visu->line + 10);
		if (ft_strstr(visu->line, "X fin"))
		{
			visu->score2 = atoi(visu->line + 10);
			ft_memdel((void**)&visu->line);
			return (1);
		}
		ft_memdel((void**)&visu->line);
	}
	ft_memdel((void**)&visu->line);
	return (0);
}
