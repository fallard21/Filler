/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:53:11 by tima              #+#    #+#             */
/*   Updated: 2020/07/07 00:24:57 by tima             ###   ########.fr       */
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
