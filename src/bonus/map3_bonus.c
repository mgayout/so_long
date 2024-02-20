/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:56:24 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/20 14:15:41 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	check_1ecp_bonus(t_slg_b *game, char **map)
{
	int	height;
	int	width;

	height = 0;
	while (map[height] != NULL)
	{
		width = 0;
		while (map[height][width] != '\0')
		{
			if (map[height][width] == game->content.exit)
				game->content.count_e++;
			if (map[height][width] == game->content.obj)
				game->content.count_c++;
			if (map[height][width] == game->content.player)
				game->content.count_p++;
			width++;
		}
		height++;
	}
	if (game->content.count_e != 1 || game->content.count_c == 0
		|| game->content.count_p != 1)
		return (FALSE);
	return (TRUE);
}

int	valid_path_bonus(t_slg_b *game, char *arg)
{
	char	**copy;
	int		height;

	copy = set_map_bonus(arg);
	height = 0;
	if (valid_path2_bonus(game, copy, height, arg) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	valid_path2_bonus(t_slg_b *game, char **copy, int h, char *arg)
{
	int	width;

	while (copy[h] != NULL)
	{
		width = 0;
		while (copy[h][width] != '\0')
		{
			if ((copy[h][width] == game->content.obj
				|| copy[h][width] == game->content.exit)
				&& path_bonus(game, copy, h, width) == FALSE)
			{
				free_map_bonus(copy);
				return (FALSE);
			}
			free_map_bonus(copy);
			copy = set_map_bonus(arg);
			width++;
		}
		h++;
	}
	free_map_bonus(copy);
	return (TRUE);
}

int	path_bonus(t_slg_b *game, char **map, int height, int width)
{
	if (map[height][width] == game->content.wall)
		return (FALSE);
	if (map[height][width] == game->content.player)
		return (TRUE);
	if (map[height][width] == game->content.trap)
		game->path.ptrap += 1;
	else
		game->path.ptrap = 0;
	map[height][width] = game->content.wall;
	if (game->path.ptrap > 4)
		return (FALSE);
	if (path_bonus(game, map, height + 1, width) == TRUE)
		return (TRUE);
	if (path_bonus(game, map, height, width + 1) == TRUE)
		return (TRUE);
	if (path_bonus(game, map, height - 1, width) == TRUE)
		return (TRUE);
	if (path_bonus(game, map, height, width - 1) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	check_ber_bonus(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 4] != '.' || map[i - 3] != 'b'
		|| map[i - 2] != 'e' || map[i - 1] != 'r')
		return (FALSE);
	return (TRUE);
}
