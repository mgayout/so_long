/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:32:18 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/12 11:32:18 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	rectangle_map_bonus(t_slg_b *game, char **map)
{
	size_t	width;
	size_t	height;

	height = 0;
	width = ft_strlen(map[height]);
	while (map[height] != NULL)
	{
		if (ft_strlen(map[height]) != width)
			return (FALSE);
		width = ft_strlen(map[height]);
		height++;
	}
	if (width == height)
		return (FALSE);
	game->height = (int)height;
	game->width = (int)width;
	return (TRUE);
}

int	wall_map_bonus(t_slg_b *game, char **map)
{
	if (game->height < 3)
		return (FALSE);
	if (wall_ud_bonus(game, map) != TRUE)
		return (FALSE);
	if (wall_lr_bonus(game, map) != TRUE)
		return (FALSE);
	return (TRUE);
}

int	wall_ud_bonus(t_slg_b *game, char **map)
{
	int	width;

	width = 0;
	while (map[0][width] != '\0')
	{
		if (map[0][width] == game->content.wall)
			width++;
		else
			return (FALSE);
	}
	width = 0;
	while (map[game->height - 1][width] != '\0')
	{
		if (map[game->height - 1][width] == game->content.wall)
			width++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	wall_lr_bonus(t_slg_b *game, char **map)
{
	int	height;
	int	width;
	int	width2;

	height = 1;
	width = 0;
	width2 = game->width - 1;
	while (height != game->height - 1)
	{
		if (map[height][width] == game->content.wall
		&& map[height][width2] == game->content.wall)
			height++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	char_check_bonus(char **map)
{
	int	height;
	int	width;

	height = 0;
	while (map[height] != NULL)
	{
		width = 0;
		while (map[height][width] != '\0')
		{
			if (map[height][width] != '1' && map[height][width] != '0'
			&& map[height][width] != 'P' && map[height][width] != 'C'
			&& map[height][width] != 'E' && map[height][width] != 'T')
				return (FALSE);
			width++;
		}
		height++;
	}
	return (TRUE);
}
