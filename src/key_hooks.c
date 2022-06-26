/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:53:10 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 21:24:27 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_window *win, int i, int j)
{
	if (win->map_table[i - 1][j] == 'E' && check_collec(win->map_table) == 0)
		exit(0);
	else if (win->map_table[i - 1][j] != 'E')
	{
		win->nbr_mv++;
		ft_printf("number of movements: %d\n", win->nbr_mv);
		ft_put_space(win);
		win->x = get_x_p(win->map_table);
		win->y = win->y - 60;
		ft_put_player(win, win->direc);
		win->map_table[i - 1][j] = 'P';
		win->map_table[i][j] = '0';
	}
}

void	move_down(t_window *win, int i, int j)
{
	win->direc = 1;
	if (win->map_table[i][j - 1] == 'E' && check_collec(win->map_table) == 0)
		exit(0);
	else if (win->map_table[i][j - 1] != 'E')
	{
		win->nbr_mv++;
		ft_printf("number of movements: %d\n", win->nbr_mv);
		ft_put_space(win);
		win->x = win->x - 60;
		win->y = get_y_p(win->map_table);
		ft_put_player(win, win->direc);
		win->map_table[i][j - 1] = 'P';
		win->map_table[i][j] = '0';
	}
}

void	move_right(t_window *win, int i, int j)
{
	win->direc = 0;
	if (win->map_table[i][j + 1] == 'E' && check_collec(win->map_table) == 0)
		exit(0);
	else if (win->map_table[i][j + 1] != 'E')
	{
		win->nbr_mv++;
		ft_printf("number of movements: %d\n", win->nbr_mv);
		ft_put_space(win);
		win->x = win->x + 60;
		win->y = get_y_p(win->map_table);
		ft_put_player(win, win->direc);
		win->map_table[i][j + 1] = 'P';
		win->map_table[i][j] = '0';
	}
}

void	move_left(t_window *win, int i, int j)
{
	if (win->map_table[i + 1][j] == 'E' && check_collec(win->map_table) == 0)
		exit(0);
	else if (win->map_table[i + 1][j] != 'E')
	{
		win->nbr_mv++;
		printf("number of movements: %d\n", win->nbr_mv);
		ft_put_space(win);
		win->x = get_x_p(win->map_table);
		win->y = win->y + 60;
		ft_put_player(win, win->direc);
		win->map_table[i + 1][j] = 'P';
		win->map_table[i][j] = '0';
	}	
}

int	play_window(int keycode, t_window *win)
{
	int	i;
	int	j;

	i = get_i_p(win->map_table);
	j = get_j_p(win->map_table);
	win->x = get_x_p(win->map_table);
	win->y = get_y_p(win->map_table);
	if (keycode == 53)
	{
		exit(0);
	}
	else if (keycode == 13 && win->map_table[i - 1][j] != '1')
		move_up(win, i, j);
	else if (keycode == 2 && win->map_table[i][j + 1] != '1')
		move_right(win, i, j);
	else if (keycode == 1 && win->map_table[i + 1][j] != '1')
		move_left(win, i, j);
	else if (keycode == 0 && win->map_table[i][j - 1] != '1')
		move_down(win, i, j);
	return (0);
}
