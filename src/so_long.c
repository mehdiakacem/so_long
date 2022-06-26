/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:16:33 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 21:10:28 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	end(t_window	win)
{
	(void) win;
	exit(0);
	return (0);
}

int	main(int argc, char	*argv[])
{
	t_window	win;

	if (argc != 2 || ft_check_map(argv[1]) == 1)
		return_error();
	win.map_table = ft_get_map(open(argv[1], O_RDONLY));
	win.length = ft_map_length(win.map_table) * 60;
	win.height = ft_map_height(win.map_table) * 60;
	win.mlx = mlx_init();
	if (win.mlx == NULL)
		return_error();
	win.mlx_win = mlx_new_window(win.mlx, win.length, win.height, "so_long");
	if (win.mlx_win == NULL)
		return_error();
	ft_put_map(win.map_table, &win, 0, 0);
	mlx_hook(win.mlx_win, 17, 0, end, &win);
	mlx_hook(win.mlx_win, 2, 0, play_window, &win);
	mlx_loop(win.mlx);
}
