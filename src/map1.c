/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:49:17 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/14 10:13:07 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**set_map(char *map)
{
	int		fd;
	char	**new_map;
	char	*temp_map;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile not found or empty.\n");
		return (0);
	}
	else
		temp_map = set_map2(fd, i);
	new_map = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (new_map);
}

char	*set_map2(int fd, int i)
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

int	map_check(t_slg *game, char **map, char *arg)
{
	if (rectangle_map(game, map) == FALSE)
	{
		ft_printf("Error\nMap isn't a rectangle.\n");
		return (FALSE);
	}
	if (wall_map(game, map) == FALSE)
	{
		ft_printf("Error\nWalls are missing.\n");
		return (FALSE);
	}
	if (char_check(map) == FALSE)
	{
		ft_printf("Error\nComponents are unknown.\n");
		return (FALSE);
	}
	if (map_check2(game, map, arg) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	map_check2(t_slg *game, char **map, char *arg)
{
	char	*s;

	s = "Components are missing or too much entries/exits.";
	if (check_1ecp(game, map) == FALSE)
	{
		ft_printf("Error\n%s\n", s);
		return (FALSE);
	}
	if (valid_path(game, arg) == FALSE)
	{
		ft_printf("Error\nPath isn't valid.\n");
		return (FALSE);
	}
	return (TRUE);
}

void	free_map(char **map)
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
