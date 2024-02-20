/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:44:18 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/20 16:13:36 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
}						t_posslg;

typedef struct s_content
{
	int					wdt;
	int					hgt;
	char				player;
	char				wall;
	char				space;
	char				obj;
	char				exit;
	int					count_e;
	int					count_c;
	int					count_p;
}						t_contslg;

typedef struct s_path
{
	char				*player_up1;
	char				*player_left1;
	char				*player_right1;
	char				*player_down1;
	char				*wall;
	char				*lcwall;
	char				*rcwall;
	char				*leftwall;
	char				*rightwall;
	char				*coin1;
	char				*space;
	char				*exit1;
	char				*exit2;
}						t_path;

typedef struct s_image
{
	t_path				path;
	void				*player_up1;
	void				*player_left1;
	void				*player_right1;
	void				*player_down1;
	void				*wall;
	void				*lcwall;
	void				*rcwall;
	void				*leftwall;
	void				*rightwall;
	void				*coin1;
	void				*space;
	void				*exit1;
	void				*exit2;
}						t_imgslg;

typedef struct s_mappath
{
	int					count_c;
}				t_mappath;

typedef struct s_game
{
	void				*mlx;
	void				*mlx_win;
	int					height;
	int					width;
	char				**map;
	t_contslg			content;
	t_imgslg			img;
	t_posslg			pos;
	int					count;
	int					player;
	t_mappath			path;
}						t_slg;

//MAIN

void			set_content(t_contslg *content);
void			init_game(t_slg *game);
int				free_all(t_slg *game, int type);

//SET

void			set_img(t_slg *game);
void			img_path(t_slg *game);
void			xpm_to_image1(t_slg *game);
void			xpm_to_image2(t_slg *game);

//MAP1

char			**set_map(char *map);
char			*set_map2(int fd, int i);
int				map_check(t_slg *game, char **map, char *arg);
int				map_check2(t_slg *game, char **map, char *arg);
void			free_map(char **map);

//MAP2

int				rectangle_map(t_slg *game, char **map);
int				wall_map(t_slg *game, char **map);
int				wall_map2(t_slg *game, char **map, int height, int width);
int				char_check(char **map);

//MAP3

int				check_1ecp(t_slg *game, char **map);
int				valid_path(t_slg *game, char *arg);
int				valid_path2(t_slg *game, char **copy, int height, char *arg);
int				path(t_slg *game, char **map, int height, int width);
int				check_ber(char *map);

//IMAGE

int				draw(t_slg *game);
void			draw2(t_slg *game, int height, int width);
void			wall_to_window(t_slg *game, int x, int y);
void			exit_to_window(t_slg *game, int x, int y);
void			player_to_window(t_slg *game, int i, int x, int y);

//MOVEMENT1

int				press_key(int key, t_slg *game);
void			move_up1(t_slg *game);
void			move_down1(t_slg *game);
void			move_left1(t_slg *game);
void			move_right1(t_slg *game);

//MOVEMENT2

void			move_up2(t_slg *game);
void			move_down2(t_slg *game);
void			move_left2(t_slg *game);
void			move_right2(t_slg *game);

#endif