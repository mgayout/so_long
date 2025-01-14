/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:35:58 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/14 11:23:29 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	set_img_bonus(t_slg_b *game)
{
	player_path_bonus(game);
	others_path_bonus(game);
	xpm_to_player_image1_bonus(game);
	xpm_to_player_image2_bonus(game);
	xpm_to_others_image1_bonus(game);
	xpm_to_others_image2_bonus(game);
}

void	player_path_bonus(t_slg_b *game)
{
	game->img.path.player_down1 = "./texture/xpm/player/down1.xpm";
	game->img.path.player_down2 = "./texture/xpm/player/down2.xpm";
	game->img.path.player_down3 = "./texture/xpm/player/down3.xpm";
	game->img.path.player_down4 = "./texture/xpm/player/down4.xpm";
	game->img.path.player_left1 = "./texture/xpm/player/left1.xpm";
	game->img.path.player_left2 = "./texture/xpm/player/left2.xpm";
	game->img.path.player_left3 = "./texture/xpm/player/left3.xpm";
	game->img.path.player_left4 = "./texture/xpm/player/left4.xpm";
	game->img.path.player_right1 = "./texture/xpm/player/right1.xpm";
	game->img.path.player_right2 = "./texture/xpm/player/right2.xpm";
	game->img.path.player_right3 = "./texture/xpm/player/right3.xpm";
	game->img.path.player_right4 = "./texture/xpm/player/right4.xpm";
	game->img.path.player_up1 = "./texture/xpm/player/up1.xpm";
	game->img.path.player_up2 = "./texture/xpm/player/up2.xpm";
	game->img.path.player_up3 = "./texture/xpm/player/up3.xpm";
	game->img.path.player_up4 = "./texture/xpm/player/up4.xpm";
}

void	others_path_bonus(t_slg_b *game)
{
	game->img.path.wall = "./texture/xpm/wall/wall.xpm";
	game->img.path.lcwall = "./texture/xpm/wall/lcwall.xpm";
	game->img.path.rcwall = "./texture/xpm/wall/rcwall.xpm";
	game->img.path.leftwall = "./texture/xpm/wall/leftwall.xpm";
	game->img.path.rightwall = "./texture/xpm/wall/rightwall.xpm";
	game->img.path.space = "./texture/xpm/wall/space.xpm";
	game->img.path.coin1 = "./texture/xpm/coin/coin1.xpm";
	game->img.path.coin2 = "./texture/xpm/coin/coin2.xpm";
	game->img.path.coin3 = "./texture/xpm/coin/coin3.xpm";
	game->img.path.coin4 = "./texture/xpm/coin/coin4.xpm";
	game->img.path.coin5 = "./texture/xpm/coin/coin5.xpm";
	game->img.path.trap1 = "./texture/xpm/trap/trap1.xpm";
	game->img.path.trap2 = "./texture/xpm/trap/trap2.xpm";
	game->img.path.trap3 = "./texture/xpm/trap/trap3.xpm";
	game->img.path.exit1 = "./texture/xpm/exit/exit1.xpm";
	game->img.path.exit2 = "./texture/xpm/exit/exit2.xpm";
}

void	xpm_to_player_image1_bonus(t_slg_b *game)
{
	game->img.player_down1 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_down1, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_down2 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_down2, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_down3 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_down3, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_down4 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_down4, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_left1 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_left1, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_left2 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_left2, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_left3 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_left3, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_left4 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_left4, &(game->content.wdt),
			&(game->content.hgt));
}

void	xpm_to_player_image2_bonus(t_slg_b *game)
{
	game->img.player_right1 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_right1, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_right2 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_right2, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_right3 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_right3, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_right4 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_right4, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_up1 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_up1, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_up2 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_up2, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_up3 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_up3, &(game->content.wdt),
			&(game->content.hgt));
	game->img.player_up4 = mlx_xpm_file_to_image(game->mlx,
			game->img.path.player_up4, &(game->content.wdt),
			&(game->content.hgt));
}
