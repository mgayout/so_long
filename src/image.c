/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:31:14 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/12 11:31:16 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	draw(t_slg *game)
{
	int	width;
	int	height;

	height = 0;
	while (game->map[height] != NULL)
	{
		width = 0;
		while (game->map[height][width] != '\0')
		{
			draw2(game, height, width);
			width++;
		}
		height++;
	}
	return (0);
}

void	draw2(t_slg *game, int height, int width)
{
	if (game->map[height][width] == game->content.wall)
		wall_to_window(game, width, height);
	if (game->map[height][width] == game->content.obj)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.coin1,
			width * game->content.wdt, height * game->content.hgt);
	if (game->map[height][width] == game->content.exit)
		exit_to_window(game, width, height);
	if (game->map[height][width] == game->content.player)
		player_to_window(game, game->player, width, height);
	if (game->map[height][width] == game->content.space)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.space, width * game->content.wdt,
			height * game->content.hgt);
}

void	wall_to_window(t_slg *game, int x, int y)
{
	if (x == 0 && y == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.lcwall,
			x * game->content.wdt, y * game->content.hgt);
	else if (x == game->width - 1 && y == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.rcwall,
			x * game->content.wdt, y * game->content.hgt);
	else if (x == 0 && (y >= 1 && y <= game->height - 2))
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.leftwall,
			x * game->content.wdt, y * game->content.hgt);
	else if (x == (game->width - 1) && y >= 1 && y <= game->height - 2)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.rightwall,
			x * game->content.wdt, y * game->content.hgt);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.wall,
			x * game->content.wdt, y * game->content.hgt);
}

void	player_to_window(t_slg *game, int i, int x, int y)
{
	game->pos.x = x;
	game->pos.y = y;
	if (i == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_down1, x * game->content.wdt,
			y * game->content.hgt);
	else if (i == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_left1, x * game->content.wdt,
			y * game->content.hgt);
	else if (i == 2)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_right1, x * game->content.wdt,
			y * game->content.hgt);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.player_up1, x * game->content.wdt,
			y * game->content.hgt);
}

void	exit_to_window(t_slg *game, int x, int y)
{
	if (game->content.count_c != 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.exit1,
			x * game->content.wdt, y * game->content.hgt);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.exit2,
			x * game->content.wdt, y * game->content.hgt);
}
