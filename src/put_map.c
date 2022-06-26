/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:45:17 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 21:24:46 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_this(t_window *win, int i, int j)
{
	if (win->map_table[i][j] == '1')
		ft_put_wall(win);
	else if (win->map_table[i][j] == '0')
		ft_put_space(win);
	else if (win->map_table[i][j] == 'P')
		ft_put_player(win, 0);
	else if (win->map_table[i][j] == 'C')
		ft_put_collec(win);
	else if (win->map_table[i][j] == 'E')
		ft_put_exit(win);
}

void	ft_put_map(char	**map_table, t_window *win, int i, int j)
{
	win->x = 0;
	win->y = 0;
	while (i < ft_map_height(map_table))
	{
		win->x = 0;
		j = 0;
		while (j < ft_map_length(map_table))
		{
			check_this(win, i, j);
			j++;
			win->x = win->x + 60;
		}
		i++;
		win->y = win->y + 60;
	}
}
