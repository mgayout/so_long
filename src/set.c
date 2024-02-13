/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:35:58 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/09 14:02:05 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_img(t_slg *game)
{
	img_path(game);
	xpm_to_image1(game);
	xpm_to_image2(game);
}

void	img_path(t_slg *game)
{
	game->img.path.player_down1 = "./texture/xpm/player/down1.xpm";
	game->img.path.player_left1 = "./texture/xpm/player/left1.xpm";
	game->img.path.player_right1 = "./texture/xpm/player/right1.xpm";
	game->img.path.player_up1 = "./texture/xpm/player/up1.xpm";
	game->img.path.wall = "./texture/xpm/wall/wall.xpm";
	game->img.path.lcwall = "./texture/xpm/wall/lcwall.xpm";
	game->img.path.rcwall = "./texture/xpm/wall/rcwall.xpm";
	game->img.path.leftwall = "./texture/xpm/wall/leftwall.xpm";
	game->img.path.rightwall = "./texture/xpm/wall/rightwall.xpm";
	game->img.path.space = "./texture/xpm/wall/space.xpm";
	game->img.path.coin1 = "./texture/xpm/coin/coin1.xpm";
	game->img.path.exit1 = "./texture/xpm/exit/exit1.xpm";
	game->img.path.exit2 = "./texture/xpm/exit/exit2.xpm";
}

void	xpm_to_image1(t_slg *game)
{
	game->img.player_down1 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_down1, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_left1 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_left1, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_right1 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_right1, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_up1 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_up1, &(game->content.wdt),
			&(game->content.hgt));
}

void	xpm_to_image2(t_slg *game)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, game->img.path.wall,
			&(game->content.wdt), &(game->content.hgt));
	game->img.lcwall = mlx_xpm_file_to_image(game->mlx, game->img.path.lcwall,
			&(game->content.wdt), &(game->content.hgt));
	game->img.rcwall = mlx_xpm_file_to_image(game->mlx, game->img.path.rcwall,
			&(game->content.wdt), &(game->content.hgt));
	game->img.leftwall = mlx_xpm_file_to_image(game->mlx,
			game->img.path.leftwall, &(game->content.wdt),
			&(game->content.hgt));
	game->img.rightwall = mlx_xpm_file_to_image(game->mlx,
			game->img.path.rightwall, &(game->content.wdt),
			&(game->content.hgt));
	game->img.space = mlx_xpm_file_to_image(game->mlx, game->img.path.space,
			&(game->content.wdt), &(game->content.hgt));
	game->img.coin1 = mlx_xpm_file_to_image(game->mlx, game->img.path.coin1,
			&(game->content.wdt), &(game->content.hgt));
	game->img.exit1 = mlx_xpm_file_to_image(game->mlx, game->img.path.exit1,
			&(game->content.wdt), &(game->content.hgt));
	game->img.exit2 = mlx_xpm_file_to_image(game->mlx, game->img.path.exit2,
			&(game->content.wdt), &(game->content.hgt));
}
