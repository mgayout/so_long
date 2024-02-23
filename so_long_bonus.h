/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:09:00 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/23 12:46:23 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <fcntl.h>
# include <stdlib.h>

# define TRUE 0
# define FALSE 1
# define ERROR 1

typedef struct s_pos
{
	int					x;
	int					y;
}						t_posslg_b;

typedef struct s_content
{
	int					wdt;
	int					hgt;
	char				player;
	char				wall;
	char				space;
	char				obj;
	char				trap;
	char				exit;
	int					count_e;
	int					count_c;
	int					count_p;
}						t_contslg_b;

typedef struct s_path
{
	char				*player_up1;
	char				*player_up2;
	char				*player_up3;
	char				*player_up4;
	char				*player_left1;
	char				*player_left2;
	char				*player_left3;
	char				*player_left4;
	char				*player_right1;
	char				*player_right2;
	char				*player_right3;
	char				*player_right4;
	char				*player_down1;
	char				*player_down2;
	char				*player_down3;
	char				*player_down4;
	char				*wall;
	char				*lcwall;
	char				*rcwall;
	char				*leftwall;
	char				*rightwall;
	char				*coin1;
	char				*coin2;
	char				*coin3;
	char				*coin4;
	char				*coin5;
	char				*space;
	char				*trap1;
	char				*trap2;
	char				*trap3;
	char				*exit1;
	char				*exit2;
}						t_path_b;

typedef struct s_image
{
	t_path_b			path;
	void				*player_up1;
	void				*player_up2;
	void				*player_up3;
	void				*player_up4;
	void				*player_left1;
	void				*player_left2;
	void				*player_left3;
	void				*player_left4;
	void				*player_right1;
	void				*player_right2;
	void				*player_right3;
	void				*player_right4;
	void				*player_down1;
	void				*player_down2;
	void				*player_down3;
	void				*player_down4;
	void				*wall;
	void				*lcwall;
	void				*rcwall;
	void				*leftwall;
	void				*rightwall;
	void				*coin1;
	void				*coin2;
	void				*coin3;
	void				*coin4;
	void				*coin5;
	void				*space;
	void				*trap1;
	void				*trap2;
	void				*trap3;
	void				*exit1;
	void				*exit2;
}						t_imgslg_b;

typedef struct s_mappath
{
	int					ptrap;
	int					count_c;
	int					start;
}				t_mappath_b;

typedef struct s_game
{
	void				*mlx;
	void				*mlx_win;
	int					height;
	int					width;
	char				**map;
	t_contslg_b			content;
	t_imgslg_b			img;
	t_posslg_b			pos;
	int					count;
	int					loop_count;
	int					player;
	int					trap;
	int					ptrap;
	t_mappath_b			path;
}						t_slg_b;

//MAIN

void		set_content_bonus(t_contslg_b *content);
void		init_game_bonus(t_slg_b *game);
int			free_all_bonus(t_slg_b *game, int type);
void		free_img_bonus(t_slg_b *game);

//SET1

void		set_img_bonus(t_slg_b *game);
void		player_path_bonus(t_slg_b *game);
void		others_path_bonus(t_slg_b *game);
void		xpm_to_player_image1_bonus(t_slg_b *game);
void		xpm_to_player_image2_bonus(t_slg_b *game);

//SET2

void		xpm_to_others_image1_bonus(t_slg_b *game);
void		xpm_to_others_image2_bonus(t_slg_b *game);

//MAP1

char		**set_map_bonus(char *map);
char		*set_map2_bonus(int fd, int i);
int			map_check_bonus(t_slg_b *game, char **map, char *arg);
int			map_check2_bonus(t_slg_b *game, char **map, char *arg);
void		free_map_bonus(char **map);

//MAP2

int			rectangle_map_bonus(t_slg_b *game, char **map);
int			wall_map_bonus(t_slg_b *game, char **map);
int			wall_ud_bonus(t_slg_b *game, char **map);
int			wall_lr_bonus(t_slg_b *game, char **map);
int			char_check_bonus(char **map);

//MAP3

int			check_1ecp_bonus(t_slg_b *game, char **map);
int			valid_path_bonus(t_slg_b *game, char *arg);
int			valid_path2_bonus(t_slg_b *game, char **copy, int h, char *arg);
int			path_bonus(t_slg_b *game, char **map, int height, int width);
int			check_ber_bonus(char *map);

//IMAGE1

int			draw_bonus(t_slg_b *game);
void		draw2_bonus(t_slg_b *game, int height, int width);
void		wall_to_window_bonus(t_slg_b *game, int x, int y);
void		exit_to_window_bonus(t_slg_b *game, int x, int y);
void		print_screen(t_slg_b *game);

//IMAGE2

void		coin_to_window_bonus(t_slg_b *game, int i, int x, int y);
void		trap_to_window_bonus(t_slg_b *game, int i, int x, int y);

//PLAYER

void		player_to_window_bonus(t_slg_b *game, int i, int x, int y);
void		down_to_window_bonus(t_slg_b *game, int i, int x, int y);
void		left_to_window_bonus(t_slg_b *game, int i, int x, int y);
void		right_to_window_bonus(t_slg_b *game, int i, int x, int y);
void		up_to_window_bonus(t_slg_b *game, int i, int x, int y);

//MOVEMENT1

int			press_key_bonus(int key, t_slg_b *game);
void		move_up1_bonus(t_slg_b *game);
void		move_down1_bonus(t_slg_b *game);
void		move_left1_bonus(t_slg_b *game);
void		move_right1_bonus(t_slg_b *game);

//MOVEMENT2

void		move_up2_bonus(t_slg_b *game);
void		move_down2_bonus(t_slg_b *game);
void		move_left2_bonus(t_slg_b *game);
void		move_right2_bonus(t_slg_b *game);

#endif