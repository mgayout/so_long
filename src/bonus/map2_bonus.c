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
	int	height;
	int	width;
	int	rtrn;

	height = 0;
	width = 0;
	rtrn = wall_map2_bonus(game, map, height, width);
	return (rtrn);
}

int	wall_map2_bonus(t_slg_b *game, char **map, int height, int width)
{
	while (map[height] != NULL)
	{
		if (height == 0 && map[height][width] == game->content.wall)
			width++;
		else if ((height >= 1 && height < game->height)
			&& (map[height][0] == game->content.wall
			|| map[height][game->width - 1] == game->content.wall)
			&& (width != game->width))
			width++;
		else if (height == game->height
			&& map[height][width] == game->content.wall)
			width++;
		else if ((map[height][width] == '\0') && (height < game->height))
		{
			height++;
			width = 0;
		}
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
