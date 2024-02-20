/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:32:34 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/12 11:32:34 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	move_up2_bonus(t_slg_b *game)
{
	if (game->map[game->pos.y - 1][game->pos.x] != game->content.wall)
	{
		if (game->ptrap == 0)
			game->map[game->pos.y][game->pos.x] = game->content.space;
		else
			game->map[game->pos.y][game->pos.x] = game->content.trap;
		game->ptrap = 0;
		game->pos.y -= 1;
		game->count += 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.trap)
			game->ptrap = 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.exit)
		{
			ft_printf("You won !\n", 1);
			free_all_bonus(game, 1);
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 3;
	}
}

void	move_down2_bonus(t_slg_b *game)
{
	if (game->map[game->pos.y + 1][game->pos.x] != game->content.wall)
	{
		if (game->ptrap == 0)
			game->map[game->pos.y][game->pos.x] = game->content.space;
		else
			game->map[game->pos.y][game->pos.x] = game->content.trap;
		game->ptrap = 0;
		game->pos.y += 1;
		game->count += 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.trap)
			game->ptrap = 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.exit)
		{
			ft_printf("You won !\n", 1);
			free_all_bonus(game, 1);
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 0;
	}
}

void	move_left2_bonus(t_slg_b *game)
{
	if (game->map[game->pos.y][game->pos.x - 1] != game->content.wall)
	{
		if (game->ptrap == 0)
			game->map[game->pos.y][game->pos.x] = game->content.space;
		else
			game->map[game->pos.y][game->pos.x] = game->content.trap;
		game->ptrap = 0;
		game->pos.x -= 1;
		game->count += 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.trap)
			game->ptrap = 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.exit)
		{
			ft_printf("You won !\n", 1);
			free_all_bonus(game, 1);
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 1;
	}
}

void	move_right2_bonus(t_slg_b *game)
{
	if (game->map[game->pos.y][game->pos.x + 1] != game->content.wall)
	{
		if (game->ptrap == 0)
			game->map[game->pos.y][game->pos.x] = game->content.space;
		else
			game->map[game->pos.y][game->pos.x] = game->content.trap;
		game->ptrap = 0;
		game->pos.x += 1;
		game->count += 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.trap)
			game->ptrap = 1;
		if (game->map[game->pos.y][game->pos.x] == game->content.exit)
		{
			ft_printf("You won !\n", 1);
			free_all_bonus(game, 1);
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 2;
	}
}
