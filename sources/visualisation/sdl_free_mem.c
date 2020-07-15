/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_free_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 20:10:03 by tima              #+#    #+#             */
/*   Updated: 2020/07/07 00:19:35 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	vis_free_split(char ***str)
{
	int i;

	i = 0;
	if (!(*str))
		return ;
	while ((*str)[i])
		ft_memdel((void**)&(*str)[i++]);
	ft_memdel((void**)&(*str));
}

int		vis_end(t_visu *visu)
{
	int i;

	i = 0;
	if (visu->map)
	{
		while (i < visu->map_y)
			ft_memdel((void**)&visu->map[i++]);
		ft_memdel((void**)&visu->map);
	}
	ft_memdel((void**)&visu->line);
	ft_memdel((void**)&visu->player1);
	ft_memdel((void**)&visu->player2);
	return (1);
}

int		ft_exit(t_sdl *draw, int status)
{
	if (status == 1)
		ft_printf("Error creating font\n");
	else if (status == 2)
		ft_printf("Error creating render text\n");
	else if (status == 3)
		ft_printf("Error creating TTF texrure\n");
	else if (status == 4)
		ft_printf("Error while memory allocation\n");
	else if (status == 5)
		ft_printf("Error creating window\n");
	else if (status == 6)
		ft_printf("Error creating render\n");
	else if (status == 7)
		ft_printf("Error creating IMG texture\n");
	SDL_DestroyTexture(draw->background);
	sdl_memdel(&draw->area, &draw->fontex);
	TTF_CloseFont(draw->font);
	SDL_DestroyRenderer(draw->rend);
	SDL_DestroyWindow(draw->window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	exit(EXIT_FAILURE);
}

void	sdl_quit(t_sdl *draw, t_visu *visu)
{
	SDL_DestroyTexture(draw->background);
	SDL_DestroyRenderer(draw->rend);
	SDL_DestroyWindow(draw->window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	vis_end(visu);
}

void	sdl_memdel(SDL_Surface **surf, SDL_Texture **text)
{
	SDL_FreeSurface(*surf);
	*surf = NULL;
	SDL_DestroyTexture(*text);
	*text = NULL;
}
