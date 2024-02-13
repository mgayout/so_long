/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:49:57 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/09 16:02:51 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	press_key(int key, t_slg *game)
{
	if (game->content.count_c != 0)
	{
		if (key == XK_Up || key == XK_W)
			move_up1(game);
		if (key == XK_Down || key == XK_S)
			move_down1(game);
		if (key == XK_Left || key == XK_A)
			move_left1(game);
		if (key == XK_Right || key == XK_D)
			move_right1(game);
	}
	else
	{
		if (key == XK_Up || key == XK_W)
			move_up2(game);
		if (key == XK_Down || key == XK_S)
			move_down2(game);
		if (key == XK_Left || key == XK_A)
			move_left2(game);
		if (key == XK_Right || key == XK_D)
			move_right2(game);
	}
	if (key == XK_Escape)
		free_all(game, 1);
	return (0);
}

void	move_up1(t_slg *game)
{
	if (game->map[game->pos.y - 1][game->pos.x] != game->content.wall
		&& game->map[game->pos.y - 1][game->pos.x] != game->content.exit)
	{
		game->map[game->pos.y][game->pos.x] = game->content.space;
		game->pos.y -= 1;
		game->count += 1;
		if (game->count < 2)
			ft_printf("You moved %d time.\n", game->count);
		else
			ft_printf("You moved %d times.\n", game->count);
		if (game->map[game->pos.y][game->pos.x] == game->content.obj)
			game->content.count_c -= 1;
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 3;
	}
}

void	move_down1(t_slg *game)
{
	if (game->map[game->pos.y + 1][game->pos.x] != game->content.wall
		&& game->map[game->pos.y + 1][game->pos.x] != game->content.exit)
	{
		game->map[game->pos.y][game->pos.x] = game->content.space;
		game->pos.y += 1;
		game->count += 1;
		if (game->count < 2)
			ft_printf("You moved %d time.\n", game->count);
		else
			ft_printf("You moved %d times.\n", game->count);
		if (game->map[game->pos.y][game->pos.x] == game->content.obj)
			game->content.count_c -= 1;
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 0;
	}
}

void	move_left1(t_slg *game)
{
	if (game->map[game->pos.y][game->pos.x - 1] != game->content.wall
		&& game->map[game->pos.y][game->pos.x - 1] != game->content.exit)
	{
		game->map[game->pos.y][game->pos.x] = game->content.space;
		game->pos.x -= 1;
		game->count += 1;
		if (game->count < 2)
			ft_printf("You moved %d time.\n", game->count);
		else
			ft_printf("You moved %d times.\n", game->count);
		if (game->map[game->pos.y][game->pos.x] == game->content.obj)
			game->content.count_c -= 1;
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 1;
	}
}

void	move_right1(t_slg *game)
{
	if (game->map[game->pos.y][game->pos.x + 1] != game->content.wall
		&& game->map[game->pos.y][game->pos.x + 1] != game->content.exit)
	{
		game->map[game->pos.y][game->pos.x] = game->content.space;
		game->pos.x += 1;
		game->count += 1;
		if (game->count < 2)
			ft_printf("You moved %d time.\n", game->count);
		else
			ft_printf("You moved %d times.\n", game->count);
		if (game->map[game->pos.y][game->pos.x] == game->content.obj)
			game->content.count_c -= 1;
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 2;
	}
}
