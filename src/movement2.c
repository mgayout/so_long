/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:51:34 by mgayout           #+#    #+#             */
/*   Updated: 2024/01/31 17:51:34 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up2(t_slg *game)
{
	if (game->map[game->pos.y - 1][game->pos.x] != game->content.wall)
	{
		game->map[game->pos.y][game->pos.x] = game->content.space;
		game->pos.y -= 1;
		game->count += 1;
		ft_printf("You moved %d times.\n", game->count);
		if (game->map[game->pos.y][game->pos.x] == game->content.exit)
		{
			ft_printf("You won !\n", 1);
			free_all(game, 1);
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 3;
	}
}

void	move_down2(t_slg *game)
{
	if (game->map[game->pos.y + 1][game->pos.x] != game->content.wall)
	{
		game->map[game->pos.y][game->pos.x] = game->content.space;
		game->pos.y += 1;
		game->count += 1;
		ft_printf("You moved %d times.\n", game->count);
		if (game->map[game->pos.y][game->pos.x] == game->content.exit)
		{
			ft_printf("You won !\n", 1);
			free_all(game, 1);
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 0;
	}
}

void	move_left2(t_slg *game)
{
	if (game->map[game->pos.y][game->pos.x - 1] != game->content.wall)
	{
		game->map[game->pos.y][game->pos.x] = game->content.space;
		game->pos.x -= 1;
		game->count += 1;
		ft_printf("You moved %d times.\n", game->count);
		if (game->map[game->pos.y][game->pos.x] == game->content.exit)
		{
			ft_printf("You won !\n", 1);
			free_all(game, 1);
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 1;
	}
}

void	move_right2(t_slg *game)
{
	if (game->map[game->pos.y][game->pos.x + 1] != game->content.wall)
	{
		game->map[game->pos.y][game->pos.x] = game->content.space;
		game->pos.x += 1;
		game->count += 1;
		ft_printf("You moved %d times.\n", game->count);
		if (game->map[game->pos.y][game->pos.x] == game->content.exit)
		{
			ft_printf("You won !\n", 1);
			free_all(game, 1);
		}
		game->map[game->pos.y][game->pos.x] = game->content.player;
		game->player = 2;
	}
}
