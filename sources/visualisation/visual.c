/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:31:03 by fallard           #+#    #+#             */
/*   Updated: 2020/07/12 20:31:05 by fallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		main(void)
{
	t_visu	visu;
	t_sdl	draw;

	if (vis_game_info(&visu) == 1)
		return (vis_end(&visu));
	if (vis_read_map(&visu))
		return (vis_end(&visu));
	sdl_init(&draw);
	sdl_init_cube(&draw, &visu);
	sdl_background(&draw);
	sdl_title(&draw);
	draw_players(&draw, &visu);
	sdl_prepare_map(&draw, &visu);
	sdl_main_loop(&draw, &visu);
	sdl_quit(&draw, &visu);
	return (0);
}
