/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:15:59 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/12 13:45:06 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	draw_bonus(t_slg *game)
{
	int		width;
	int		height;

	game->loop_count += 1;
	height = 0;
	while (game->map[height] != NULL)
	{
		width = 0;
		while (game->map[height][width] != '\0')
		{
			draw2_bonus(game, height, width);
			print_screen(game);
			width++;
		}
		height++;
	}
	return (0);
}

void	draw2_bonus(t_slg *game, int height, int width)
{
	if (game->map[height][width] == game->content.wall)
		wall_to_window_bonus(game, width, height);
	if (game->map[height][width] == game->content.obj)
		coin_to_window_bonus(game, game->loop_count, width, height);
	if (game->map[height][width] == game->content.trap)
		trap_to_window_bonus(game, game->trap, width, height);
	if (game->map[height][width] == game->content.exit)
		exit_to_window_bonus(game, width, height);
	if (game->map[height][width] == game->content.player)
		player_to_window_bonus(game, game->player, width, height);
	if (game->map[height][width] == game->content.space)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img.space, width * game->content.wdt,
			height * game->content.hgt);
}

void	wall_to_window_bonus(t_slg *game, int x, int y)
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

void	exit_to_window_bonus(t_slg *game, int x, int y)
{
	if (game->content.count_c != 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.exit1,
			x * game->content.wdt, y * game->content.hgt);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.exit2,
			x * game->content.wdt, y * game->content.hgt);
}

void	print_screen(t_slg *game)
{
	char	*ptr;

	if (game->count < 2)
		mlx_string_put(game->mlx, game->mlx_win, 10,
			game->height * game->content.hgt, 0xff0000,
			"You mooved   time.");
	if (game->count >= 2 && game->count < 10)
		mlx_string_put(game->mlx, game->mlx_win, 10,
			game->height * game->content.hgt, 0xff0000,
			"You mooved    times.");
	if (game->count >= 10 && game->count < 100)
		mlx_string_put(game->mlx, game->mlx_win, 10,
			game->height * game->content.hgt, 0xff0000,
			"You mooved     times.");
	if (game->count >= 100)
		mlx_string_put(game->mlx, game->mlx_win, 10,
			game->height * game->content.hgt, 0xff0000,
			"You mooved     times.");
	ptr = ft_itoa(game->count);
	mlx_string_put(game->mlx, game->mlx_win, 77,
		game->height * game->content.hgt, 0xff0000, ptr);
	free(ptr);
}
