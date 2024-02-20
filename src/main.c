/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:44:03 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/20 16:02:57 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_content(t_contslg *content)
{
	content->wdt = 32;
	content->hgt = 32;
	content->player = 'P';
	content->wall = '1';
	content->obj = 'C';
	content->space = '0';
	content->exit = 'E';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

void	init_game(t_slg *game)
{
	set_img(game);
	game->mlx_win = mlx_new_window(game->mlx,
			(game->width * game->content.wdt),
			(game->height * game->content.hgt), "so_long");
	if (game->mlx_win == NULL)
	{
		free(game->mlx);
		return ;
	}
	mlx_loop_hook(game->mlx, &draw, game);
	mlx_hook(game->mlx_win, KeyRelease, KeyReleaseMask, &press_key, game);
	mlx_hook(game->mlx_win, 17, 0, &free_all, game);
	mlx_loop(game->mlx);
}

int	free_all(t_slg *game, int type)
{
	if (game->map != NULL)
		free_map(game->map);
	if (type != 0)
	{
		mlx_destroy_image(game->mlx, game->img.player_down1);
		mlx_destroy_image(game->mlx, game->img.player_left1);
		mlx_destroy_image(game->mlx, game->img.player_right1);
		mlx_destroy_image(game->mlx, game->img.player_up1);
		mlx_destroy_image(game->mlx, game->img.wall);
		mlx_destroy_image(game->mlx, game->img.lcwall);
		mlx_destroy_image(game->mlx, game->img.rcwall);
		mlx_destroy_image(game->mlx, game->img.leftwall);
		mlx_destroy_image(game->mlx, game->img.rightwall);
		mlx_destroy_image(game->mlx, game->img.space);
		mlx_destroy_image(game->mlx, game->img.coin1);
		mlx_destroy_image(game->mlx, game->img.exit1);
		mlx_destroy_image(game->mlx, game->img.exit2);
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
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
	game.mlx = mlx_init();
	set_content(&(game.content));
	if (check_ber(argv[1]) == FALSE)
	{
		ft_printf("Error\nMap file isn't '.ber' format.\n", 1);
		return (0);
	}
	game.map = set_map(argv[1]);
	if (game.map != NULL && map_check(&game, game.map, argv[1]) == TRUE)
		init_game(&game);
	else
		free_all(&game, 0);
	return (1);
}
