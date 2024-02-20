/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:31:11 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/20 14:13:22 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	xpm_to_others_image1_bonus(t_slg_b *game)
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
}

void	xpm_to_others_image2_bonus(t_slg_b *game)
{
	game->img.coin1 = mlx_xpm_file_to_image(game->mlx, game->img.path.coin1,
			&(game->content.wdt), &(game->content.hgt));
	game->img.coin2 = mlx_xpm_file_to_image(game->mlx, game->img.path.coin2,
			&(game->content.wdt), &(game->content.hgt));
	game->img.coin3 = mlx_xpm_file_to_image(game->mlx, game->img.path.coin3,
			&(game->content.wdt), &(game->content.hgt));
	game->img.coin4 = mlx_xpm_file_to_image(game->mlx, game->img.path.coin4,
			&(game->content.wdt), &(game->content.hgt));
	game->img.coin5 = mlx_xpm_file_to_image(game->mlx, game->img.path.coin5,
			&(game->content.wdt), &(game->content.hgt));
	game->img.trap1 = mlx_xpm_file_to_image(game->mlx, game->img.path.trap1,
			&(game->content.wdt), &(game->content.hgt));
	game->img.trap2 = mlx_xpm_file_to_image(game->mlx, game->img.path.trap2,
			&(game->content.wdt), &(game->content.hgt));
	game->img.trap3 = mlx_xpm_file_to_image(game->mlx, game->img.path.trap3,
			&(game->content.wdt), &(game->content.hgt));
	game->img.exit1 = mlx_xpm_file_to_image(game->mlx, game->img.path.exit1,
			&(game->content.wdt), &(game->content.hgt));
	game->img.exit2 = mlx_xpm_file_to_image(game->mlx, game->img.path.exit2,
			&(game->content.wdt), &(game->content.hgt));
}
