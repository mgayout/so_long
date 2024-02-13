/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:44:03 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/12 13:35:52 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	set_content_bonus(t_contslg *content)
{
	content->wdt = 32;
	content->hgt = 32;
	content->player = 'P';
	content->wall = '1';
	content->obj = 'C';
	content->space = '0';
	content->trap = 'T';
	content->exit = 'E';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

void	init_game_bonus(t_slg *game)
{
	set_img_bonus(game);
	game->mlx_win = mlx_new_window(game->mlx,
			(game->width * game->content.wdt),
			(game->height * game->content.hgt), "so_long");
	if (game->mlx_win == NULL)
		free_all_bonus(game, 1);
	mlx_loop_hook(game->mlx, &draw_bonus, game);
	mlx_hook(game->mlx_win, KeyRelease, KeyReleaseMask, &press_key_bonus, game);
	mlx_loop(game->mlx);
}

int	free_all_bonus(t_slg *game, int type)
{
	if (game->map != NULL)
		free_map_bonus(game->map);
	if (type == 1)
	{
		mlx_destroy_image(game->mlx, game->img.player_down1);
		mlx_destroy_image(game->mlx, game->img.player_down2);
		mlx_destroy_image(game->mlx, game->img.player_down3);
		mlx_destroy_image(game->mlx, game->img.player_down4);
		mlx_destroy_image(game->mlx, game->img.player_left1);
		mlx_destroy_image(game->mlx, game->img.player_left2);
		mlx_destroy_image(game->mlx, game->img.player_left3);
		free_img_bonus(game);
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void	free_img_bonus(t_slg *game)
{
	mlx_destroy_image(game->mlx, game->img.player_left4);
	mlx_destroy_image(game->mlx, game->img.player_right1);
	mlx_destroy_image(game->mlx, game->img.player_right2);
	mlx_destroy_image(game->mlx, game->img.player_right3);
	mlx_destroy_image(game->mlx, game->img.player_right4);
	mlx_destroy_image(game->mlx, game->img.player_up1);
	mlx_destroy_image(game->mlx, game->img.player_up2);
	mlx_destroy_image(game->mlx, game->img.player_up3);
	mlx_destroy_image(game->mlx, game->img.player_up4);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.lcwall);
	mlx_destroy_image(game->mlx, game->img.rcwall);
	mlx_destroy_image(game->mlx, game->img.leftwall);
	mlx_destroy_image(game->mlx, game->img.rightwall);
	mlx_destroy_image(game->mlx, game->img.space);
	mlx_destroy_image(game->mlx, game->img.coin1);
	mlx_destroy_image(game->mlx, game->img.coin2);
	mlx_destroy_image(game->mlx, game->img.coin3);
	mlx_destroy_image(game->mlx, game->img.coin4);
	mlx_destroy_image(game->mlx, game->img.coin5);
	mlx_destroy_image(game->mlx, game->img.trap1);
	mlx_destroy_image(game->mlx, game->img.trap2);
	mlx_destroy_image(game->mlx, game->img.trap3);
	mlx_destroy_image(game->mlx, game->img.exit1);
	mlx_destroy_image(game->mlx, game->img.exit2);
}

int	main(int argc, char **argv)
{
	t_slg	game;

	if (argc != 2)
	{
		ft_printf("Error\nOnly 2 parameters are accepted.\n", 1);
		return (0);
	}
	game.count = 0;
	game.player = 0;
	game.trap = 0;
	game.ptrap = 0;
	game.loop_count = 0;
	game.mlx = mlx_init();
	set_content_bonus(&(game.content));
	if (check_ber_bonus(argv[1]) == FALSE)
	{
		ft_printf("Error\nMap file isn't '.ber' format.\n", 1);
		return (0);
	}
	game.map = set_map_bonus(argv[1]);
	if (game.map != NULL && map_check_bonus(&game, game.map, argv[1]) == TRUE)
		init_game_bonus(&game);
	else
		free_all_bonus(&game, 0);
	return (1);
}
