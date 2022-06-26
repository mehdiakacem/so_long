/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:02:53 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 18:10:15 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_i_p(char **map_table)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_map_height(map_table))
	{
		j = 0;
		while (j < ft_map_length(map_table))
		{
			if (map_table[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_j_p(char **map_table)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_map_height(map_table))
	{
		j = 0;
		while (j < ft_map_length(map_table))
		{
			if (map_table[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_x_p(char **map_table)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < ft_map_height(map_table))
	{
		x = 0;
		j = 0;
		while (j < ft_map_length(map_table))
		{
			if (map_table[i][j] == 'P')
				return (x);
			j++;
			x = x + 60;
		}
		i++;
		y = y + 60;
	}
	return (0);
}

int	get_y_p(char **map_table)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < ft_map_height(map_table))
	{
		x = 0;
		j = 0;
		while (j < ft_map_length(map_table))
		{
			if (map_table[i][j] == 'P')
				return (y);
			j++;
			x = x + 60;
		}
		i++;
		y = y + 60;
	}
	return (0);
}

int	check_collec(char	**map_table)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < ft_map_height(map_table))
	{
		if (ft_strchr(map_table[i], 'C') != NULL)
			c++;
		i++;
	}
	if (c == 0)
		return (0);
	return (1);
}
