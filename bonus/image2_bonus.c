/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:32:05 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/12 11:32:05 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	coin_to_window_bonus(t_slg_b *game, int i, int x, int y)
{
	if (i >= 0 && i < 100)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.coin1,
			x * game->content.wdt, y * game->content.hgt);
	if (i >= 100 && i < 200)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.coin2,
			x * game->content.wdt, y * game->content.hgt);
	if (i >= 200 && i < 300)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.coin3,
			x * game->content.wdt, y * game->content.hgt);
	if (i >= 300 && i < 400)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.coin4,
			x * game->content.wdt, y * game->content.hgt);
	if (i >= 400)
	{
		if (i > 500)
		{
			game->loop_count = 0;
			game->trap += 1;
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.coin5,
			x * game->content.wdt, y * game->content.hgt);
	}
}

void	trap_to_window_bonus(t_slg_b *game, int i, int x, int y)
{
	if (i == 0 || game->content.count_c == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.trap1,
			x * game->content.wdt, y * game->content.hgt);
	}
	else if (i == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.trap2,
			x * game->content.wdt, y * game->content.hgt);
	else
	{
		if (i >= 3)
			game->trap = 0;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.trap3,
			x * game->content.wdt, y * game->content.hgt);
	}
}
