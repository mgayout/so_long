/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:09:15 by mgayout           #+#    #+#             */
/*   Updated: 2024/01/31 18:09:15 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	rectangle_map(t_slg *game, char **map)
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

int	wall_map(t_slg *game, char **map)
{
	int	height;
	int	width;
	int	rtrn;

	height = 0;
	width = 0;
	rtrn = wall_map2(game, map, height, width);
	return (rtrn);
}

int	wall_map2(t_slg *game, char **map, int height, int width)
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

int	char_check(char **map)
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
			&& map[height][width] != 'E')
				return (FALSE);
			width++;
		}
		height++;
	}
	return (TRUE);
}
