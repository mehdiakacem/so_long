/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:25:03 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 18:22:18 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_get_map(int map_fd)
{
	char	*line;
	char	*long_map;
	char	**map_table;
	char	*tmp;

	line = get_next_line(map_fd);
	tmp = ft_calloc(1, sizeof(char));
	if (!tmp || !line)
		return_error();
	while (line)
	{
		long_map = ft_strjoin(tmp, line);
		free(tmp);
		tmp = long_map;
		free(line);
		line = get_next_line(map_fd);
	}
	if (long_map[(int)ft_strlen(long_map) - 1] == '\n')
	{
		free(long_map);
		return_error();
	}
	free(long_map);
	map_table = ft_split(long_map, '\n');
	return (map_table);
}

int	ft_rectangular_map(char **map_table)
{
	int	i;
	int	len;

	i = 1;
	len = ft_map_length(map_table);
	while (i < ft_map_height(map_table))
	{
		if (len != (int)ft_strlen(map_table[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_closed_map(char **map_table)
{
	int	len;
	int	i;
	int	last_line;
	int	last_char;

	len = ft_map_length(map_table);
	i = 0;
	last_line = ft_map_height(map_table) - 1;
	while (i < len)
	{
		if (map_table[0][i] != '1' || map_table[last_line][i] != '1')
			return (1);
		i++;
	}
	last_char = ft_map_length(map_table) - 1;
	i = 0;
	len = ft_map_height(map_table);
	while (i < len)
	{
		if (map_table[i][0] != '1' || map_table[i][last_char] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_characters(char **map_table)
{
	int	i;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (i < ft_map_height(map_table))
	{
		if (ft_strchr(map_table[i], 'P') != NULL)
			p++;
		if (ft_strchr(map_table[i], 'C') != NULL)
			c++;
		if (ft_strchr(map_table[i], 'E') != NULL)
			e++;
		i++;
	}
	if (c == 0 || e == 0 || p == 0)
		return (1);
	return (0);
}
