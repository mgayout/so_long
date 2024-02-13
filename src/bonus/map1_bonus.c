/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:49:17 by mgayout           #+#    #+#             */
/*   Updated: 2024/02/12 13:29:13 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**set_map_bonus(char *map)
{
	int		fd;
	char	**new_map;
	char	*temp_map;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile not found or empty.\n", 1);
		return (0);
	}
	else
		temp_map = set_map2_bonus(fd, i);
	new_map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (new_map);
}

char	*set_map2_bonus(int fd, int i)
{
	char	*line;
	char	*temp_map;

	temp_map = get_next_line(fd);
	while (i == 0)
	{
		line = get_next_line(fd);
		if (line != NULL)
			temp_map = ft_strjoingnl(temp_map, line);
		else
			i = 1;
		free(line);
	}
	return (temp_map);
}

int	map_check_bonus(t_slg *game, char **map, char *arg)
{
	if (rectangle_map_bonus(game, map) == FALSE)
	{
		ft_printf("Error\nMap isn't a rectangle.\n", 1);
		return (FALSE);
	}
	if (wall_map_bonus(game, map) == FALSE)
	{
		ft_printf("Error\nWalls are missing.\n", 1);
		return (FALSE);
	}
	if (char_check_bonus(map) == FALSE)
	{
		ft_printf("Error\nComponents are unknown.\n", 1);
		return (FALSE);
	}
	if (map_check2_bonus(game, map, arg) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	map_check2_bonus(t_slg *game, char **map, char *arg)
{
	char	*s;

	s = "Components are missing or too much entries/exits.";
	if (check_1ecp_bonus(game, map) == FALSE)
	{
		ft_printf("Error\n%s\n", s);
		return (FALSE);
	}
	if (valid_path_bonus(game, arg) == FALSE)
	{
		ft_printf("Error\nPath isn't valid.\n", 1);
		return (FALSE);
	}
	return (TRUE);
}

void	free_map_bonus(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
