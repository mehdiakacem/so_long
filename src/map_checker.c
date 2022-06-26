/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:10:20 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 18:11:33 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	**free_split(char **map_table)
{
	int	i;

	i = ft_map_height(map_table) - 1;
	while (i >= 0)
	{
		free(map_table[i]);
		i--;
	}
	free(map_table);
	return (0);
}

int	ft_check_map(char	*map)
{
	int		map_fd;
	char	**map_table;

	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
		return (1);
	map_table = ft_get_map(map_fd);
	close(map_fd);
	if (ft_rectangular_map(map_table) == 1)
	{
		free_split(map_table);
		return (1);
	}
	else if (ft_closed_map(map_table) == 1)
	{
		free_split(map_table);
		return (1);
	}
	else if (ft_check_characters(map_table) == 1)
	{
		free_split(map_table);
		return (1);
	}
	free_split(map_table);
	return (0);
}
