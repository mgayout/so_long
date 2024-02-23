/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:49:57 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/23 13:29:53 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	press_key_bonus(int key, t_slg_b *game)
{
	if (game->content.count_c != 0)
	{
		if (key == XK_Up || key == XK_W)
			move_up1_bonus(game);
		if (key == XK_Down || key == XK_S)
			move_down1_bonus(game);
		if (key == XK_Left || key == XK_A)
			move_left1_bonus(game);
		if (key == XK_Right || key == XK_D)
			move_right1_bonus(game);
	}
	else
	{
		if (key == XK_Up || key == XK_W)
			move_up2_bonus(game);
		if (key == XK_Down || key == XK_S)
			move_down2_bonus(game);
		if (key == XK_Left || key == XK_A)
			move_left2_bonus(game);
		if (key == XK_Right || key == XK_D)
			move_right2_bonus(game);
	}
	if (key == XK_Escape)
		free_all_bonus(game, 1);
	return (0);
}

void	move_up1_bonus(t_slg_b *game)
{
	if (game->map[game->pos.y - 1][game->pos.x] != game->content.wall
		&& game->map[game->pos.y - 1][game->pos.x] != game->content.exit)
	{
		if (game->ptrap == 0)
			game->map[game->pos.y][game->pos.x] = game->content.space;
		else
			game->map[game->pos.y][game->pos.x] = game->content.trap;
		game->ptrap = 0;
		game->pos.y -= 1;
		game->count += 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.obj)
			game->content.count_c -= 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.trap)
		{
			if (game->trap >= 2)
			{
				ft_printf("You lost !\n");
				free_all_bonus(game, 1);
			}
			game->ptrap = 1;
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 3;
	}
}

void	move_down1_bonus(t_slg_b *game)
{
	if (game->map[game->pos.y + 1][game->pos.x] != game->content.wall
		&& game->map[game->pos.y + 1][game->pos.x] != game->content.exit)
	{
		if (game->ptrap == 0)
			game->map[game->pos.y][game->pos.x] = game->content.space;
		else
			game->map[game->pos.y][game->pos.x] = game->content.trap;
		game->ptrap = 0;
		game->pos.y += 1;
		game->count += 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.obj)
			game->content.count_c -= 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.trap)
		{
			if (game->trap >= 2)
			{
				ft_printf("You lost !\n");
				free_all_bonus(game, 1);
			}
			game->ptrap = 1;
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 0;
	}
}

void	move_left1_bonus(t_slg_b *game)
{
	if (game->map[game->pos.y][game->pos.x - 1] != game->content.wall
		&& game->map[game->pos.y][game->pos.x - 1] != game->content.exit)
	{
		if (game->ptrap == 0)
			game->map[game->pos.y][game->pos.x] = game->content.space;
		else
			game->map[game->pos.y][game->pos.x] = game->content.trap;
		game->ptrap = 0;
		game->pos.x -= 1;
		game->count += 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.obj)
			game->content.count_c -= 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.trap)
		{
			if (game->trap >= 2)
			{
				ft_printf("You lost !\n");
				free_all_bonus(game, 1);
			}
			game->ptrap = 1;
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 1;
	}
}

void	move_right1_bonus(t_slg_b *game)
{
	if (game->map[game->pos.y][game->pos.x + 1] != game->content.wall
		&& game->map[game->pos.y][game->pos.x + 1] != game->content.exit)
	{
		if (game->ptrap == 0)
			game->map[game->pos.y][game->pos.x] = game->content.space;
		else
			game->map[game->pos.y][game->pos.x] = game->content.trap;
		game->ptrap = 0;
		game->pos.x += 1;
		game->count += 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.obj)
			game->content.count_c -= 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.trap)
		{
			if (game->trap >= 2)
			{
				ft_printf("You lost !\n");
				free_all_bonus(game, 1);
			}
			game->ptrap = 1;
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 2;
	}
}
