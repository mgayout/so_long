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
	if (game->height < 3)
		return (FALSE);
	if (wall_ud(game, map) != TRUE)
		return (FALSE);
	if (wall_lr(game, map) != TRUE)
		return (FALSE);
	return (TRUE);
}

int	wall_ud(t_slg *game, char **map)
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

int	wall_lr(t_slg *game, char **map)
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
