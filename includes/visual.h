/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:49:18 by tima              #+#    #+#             */
/*   Updated: 2020/06/20 02:08:31 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include "libft.h"

# define DIS_W 1300
# define DIS_H 820
# define DIS_X 40
# define DIS_Y 40

typedef struct s_visu
{
	int				**map;
	int				map_x;
	int				map_y;
	int				diff_x;
	int				diff_y;
	char			*piece;
	int				piece_x;
	int				piece_y;
	int				x;
	int				y;
	char			*line;
	char			*player1;
	char			*player2;
	int				score1;
	int				score2;
}					t_visu;

typedef struct s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*rend;

	SDL_Texture		*background;
	SDL_Rect		back_rect;

	SDL_Texture		*cube;
	SDL_Rect		cube_rect;

	TTF_Font		*font;
	SDL_Surface		*area;
	SDL_Texture		*fontex;
	SDL_Color		color;
	SDL_Rect		font_rect;

	SDL_Event		event;
	const Uint8		*keyboard;
	int				quit;
	int				flag;
}					t_sdl;

/*
** >----------------------------< GAME INFO >----------------------------<
*/
int					vis_game_info(t_visu *visu);
int					vis_getplayer(t_visu *visu);
int					vis_size_map(t_visu *visu);
char				*vis_parse_player(const char *p, char *player);
int					vis_read_map(t_visu *visu);
int					save_line(t_visu *visu, char *line, int i);

/*
** >-----------------------------< SDL INIT >----------------------------<
*/
void				sdl_init(t_sdl *draw);
void				sdl_init_cube(t_sdl *draw, t_visu *visu);
void				sdl_background(t_sdl *draw);
void				sdl_title(t_sdl *d);

/*
** >--------------------------< DRAW PLAYERS >---------------------------<
*/
void				draw_players(t_sdl *draw, t_visu *visu);
void				draw_fill(t_sdl *d, t_visu *visu, int len1, int len2);
void				draw_curcuit(t_sdl *d, t_visu *visu, int len1, int len2);

/*
** >----------------------------< DRAW MAP >-----------------------------<
*/
void				sdl_prepare_map(t_sdl *draw, t_visu *visu);
void				draw_line(t_sdl *draw, t_visu *visu, int i);
void				draw_line_1(t_sdl *draw, t_visu *visu, int i);

/*
** >----------------------------< MAIN LOOP >----------------------------<
*/
void				sdl_main_loop(t_sdl *d, t_visu *visu);
void				sdl_move_right(t_sdl *d, t_visu *visu);
int					vis_skip_token(t_visu *visu);

/*
** >---------------------------< DRAW RESULTS >--------------------------<
*/
void				draw_results(t_sdl *draw, t_visu *visu);
void				draw_winner(t_sdl *d, char *win, int len);
void				draw_scores(t_sdl *d, t_visu *visu);
void				draw_scores_2(t_sdl *d, char *s1, char *s2);

/*
** >------------------------< MEMORY MANAGEMENT >------------------------<
*/
void				vis_free_split(char ***str);
int					vis_end(t_visu *visu);
void				sdl_quit(t_sdl *draw, t_visu *visu);
int					ft_exit(t_sdl *draw, int status);
void				sdl_memdel(SDL_Surface **surf, SDL_Texture **text);

#endif