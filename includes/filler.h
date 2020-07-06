/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tima <tima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:55:55 by fallard           #+#    #+#             */
/*   Updated: 2020/07/06 20:39:09 by tima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_map
{
	char		**map;
	int			**arr;
	int			size_x;
	int			size_y;
	int			sum;
	int			fin_x;
	int			fin_y;
	int			fin_sh;
	int			me;
	int			enemy;
	char		*line;
}				t_map;

typedef struct	s_piece
{
	char		*piece;
	int			size_x;
	int			size_y;
	int			shift;
	int			**coords;
	int			size_c;
}				t_piece;

/*
** >--------------------------< GAME INFO >--------------------------<
*/
void			initialisation(t_map *map, t_piece *piece);
void			reinitialisation(t_map *map, t_piece *piece);
int				get_player(t_map *map);
int				get_play_board(t_map *map, t_piece *piece);
void			back_player(t_map *map);
int				go_playing(t_map *map, t_piece *piece);
int				is_player(int c);

/*
** >-----------------------------< MAP >-----------------------------<
*/
int				save_map_size(t_map *map);
int				save_map(t_map *map);
int				convert_map(t_map *map);
void			toupper_player(char *str, int c);

/*
** >----------------------------< PIECE >----------------------------<
*/
int				save_piece_size(t_map *map, t_piece *piece);
int				save_piece(t_map *map, t_piece *piece);
int				save_coords(t_piece *piece);
int				get_wildc_count(t_piece *piece);

/*
** >--------------------------< HEAT MAP >---------------------------<
*/
void			fill_heat_map(t_map *map, int a, int b);
void			init_heat_map(t_map *map, int i, int j, int b);
int				check_dot(t_map *map);
int				is_heating(int n);

/*
** >--------------------------< ALGORITHM >--------------------------<
*/
int				solve(t_map *map, t_piece *piece);
int				check_coords(t_map *map, t_piece *piece, int shift);
void			sum_piece(t_map *map, t_piece *piece, int shift);
int				is_one_contact(t_map *map, t_piece *piece, int shift);

/*
** >----------------------< MEMORY MANAGEMENT >----------------------<
*/
void			free_all_memory(t_map *map, t_piece *piece);
int				free_split(char ***str);
int				end_program(t_map *map, t_piece *piece);

// DELETE
void			print_map(t_map *map);
void			print_arr(t_map *map);
void			print_real_arr(t_map *map);
void			print_piece(t_piece	*piece);
void			print_coords(t_piece *piece);
void			set_piece(t_map *map, t_piece *piece, int shift);

#endif
