/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:56:24 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/12 13:56:10 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_1ecp(t_slg *game, char **map)
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

int	valid_path(t_slg *game, char *arg)
{
	char	**copy;
	int		height;

	copy = set_map(arg);
	height = 0;
	if (valid_path2(game, copy, height, arg) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	valid_path2(t_slg *game, char **copy, int height, char *arg)
{
	int	width;

	while (copy[height] != NULL)
	{
		width = 0;
		while (copy[height][width] != '\0')
		{
			if ((copy[height][width] == game->content.obj
				|| copy[height][width] == game->content.exit)
				&& path(game, copy, height, width) == FALSE)
			{
				free_map(copy);
				return (FALSE);
			}
			free_map(copy);
			copy = set_map(arg);
			width++;
		}
		height++;
	}
	free_map(copy);
	return (TRUE);
}

int	path(t_slg *game, char **map, int height, int width)
{
	if (map[height][width] == game->content.wall)
		return (FALSE);
	if (map[height][width] == game->content.player)
		return (TRUE);
	map[height][width] = game->content.wall;
	if (path(game, map, height + 1, width) == TRUE)
		return (TRUE);
	if (path(game, map, height, width + 1) == TRUE)
		return (TRUE);
	if (path(game, map, height - 1, width) == TRUE)
		return (TRUE);
	if (path(game, map, height, width - 1) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	check_ber(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 4] != '.' || map[i - 3] != 'b'
		|| map[i - 2] != 'e' || map[i - 1] != 'r')
		return (FALSE);
	return (TRUE);
}
