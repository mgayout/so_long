/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:27:19 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/20 14:14:25 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	player_to_window_bonus(t_slg_b *game, int i, int x, int y)
{
	game->pos.x = x;
	game->pos.y = y;
	if (game->ptrap == 1 && game->trap == 2 && game->content.count_c != 0)
	{
		ft_printf("You loose !\n", 1);
		free_all_bonus(game, 1);
	}
	if (i == 0)
		down_to_window_bonus(game, game->loop_count, x, y);
	else if (i == 1)
		left_to_window_bonus(game, game->loop_count, x, y);
	else if (i == 2)
		right_to_window_bonus(game, game->loop_count, x, y);
	else
		up_to_window_bonus(game, game->loop_count, x, y);
}

void	down_to_window_bonus(t_slg_b *game, int i, int x, int y)
{
	if (i >= 0 && i < 125)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_down1, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 125 && i < 250)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_down2, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 250 && i < 375)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_down3, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 375)
	{
		if (i >= 500)
		{
			game->loop_count = 0;
			game->trap += 1;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_down4, x * game->content.wdt,
			y * game->content.hgt);
	}
}

void	left_to_window_bonus(t_slg_b *game, int i, int x, int y)
{
	if (i >= 0 && i < 125)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_left1, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 125 && i < 250)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_left2, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 250 && i < 375)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_left3, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 375)
	{
		if (i >= 500)
		{
			game->loop_count = 0;
			game->trap += 1;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_left4, x * game->content.wdt,
			y * game->content.hgt);
	}
}

void	right_to_window_bonus(t_slg_b *game, int i, int x, int y)
{
	if (i >= 0 && i < 125)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_right1, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 125 && i < 250)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_right2, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 250 && i < 375)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_right3, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 375)
	{
		if (i >= 500)
		{
			game->loop_count = 0;
			game->trap += 1;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_right4, x * game->content.wdt,
			y * game->content.hgt);
	}
}

void	up_to_window_bonus(t_slg_b *game, int i, int x, int y)
{
	if (i >= 0 && i < 125)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_up1, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 125 && i < 250)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_up2, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 250 && i < 375)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_up3, x * game->content.wdt,
			y * game->content.hgt);
	if (i >= 375)
	{
		if (i >= 500)
		{
			game->loop_count = 0;
			game->trap += 1;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_up4, x * game->content.wdt,
			y * game->content.hgt);
	}
}
