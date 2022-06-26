/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:04:44 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 21:22:34 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct window{
	void	*mlx;
	void	*mlx_win;
	void	*img[7];
	int		length;
	int		height;
	char	**map_table;
	int		x;
	int		y;
	int		nbr_mv;
	int		direc;
}	t_window;

void	return_error(void);
int		ft_map_length(char	**map_table);
int		ft_map_height(char	**map_table);
char	**ft_get_map(int map_fd);
int		ft_rectangular_map(char **map_table);
int		ft_closed_map(char	**map_table);
int		ft_check_characters(char **map_table);
int		ft_check_map(char	*map);
int		play_window(int keycode, t_window *win);
void	ft_put_map(char	**map_table, t_window *win, int i, int j);
void	ft_put_wall(t_window *win);
void	ft_put_space(t_window *win);
void	ft_put_collec(t_window *win);
void	ft_put_exit(t_window *win);
void	ft_put_player(t_window *w, int l);
int		move_player(int keycode, t_window *win);
int		get_i_p(char **map_table);
int		get_j_p(char **map_table);
int		get_x_p(char **map_table);
int		get_y_p(char **map_table);
int		check_collec(char	**map_table);

#endif
