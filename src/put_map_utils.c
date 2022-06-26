/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:47:38 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 18:23:44 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_wall(t_window *w)
{
	char	*path;
	int		width;
	int		height;

	path = "images/wall.xpm";
	w->img[0] = mlx_xpm_file_to_image(w->mlx, path, &width, &height);
	mlx_put_image_to_window(w->mlx, w->mlx_win, w->img[0], w->x, w->y);
}

void	ft_put_space(t_window *w)
{
	char	*path;
	int		width;
	int		height;

	path = "images/space.xpm";
	w->img[1] = mlx_xpm_file_to_image(w->mlx, path, &width, &height);
	mlx_put_image_to_window(w->mlx, w->mlx_win, w->img[1], w->x, w->y);
}

void	ft_put_collec(t_window *w)
{
	char	*path_c;
	int		width;
	int		height;

	path_c = "images/collec.xpm";
	w->img[2] = mlx_xpm_file_to_image(w->mlx, path_c, &width, &height);
	ft_put_space(w);
	mlx_put_image_to_window(w->mlx, w->mlx_win, w->img[2], w->x, w->y);
}

void	ft_put_exit(t_window *w)
{
	char	*path;
	int		width;
	int		height;

	path = "images/exit.xpm";
	w->img[3] = mlx_xpm_file_to_image(w->mlx, path, &width, &height);
	ft_put_space(w);
	mlx_put_image_to_window(w->mlx, w->mlx_win, w->img[3], w->x, w->y);
}

void	ft_put_player(t_window *w, int l)
{
	char	*path_p;
	int		width;
	int		height;

	if (l == 1)
	{
		path_p = "images/player2.xpm";
		w->img[5] = mlx_xpm_file_to_image(w->mlx, path_p, &width, &height);
		ft_put_space(w);
		mlx_put_image_to_window(w->mlx, w->mlx_win, w->img[5], w->x, w->y);
	}
	else if (l == 0)
	{
		path_p = "images/player.xpm";
		w->img[4] = mlx_xpm_file_to_image(w->mlx, path_p, &width, &height);
		ft_put_space(w);
		mlx_put_image_to_window(w->mlx, w->mlx_win, w->img[4], w->x, w->y);
	}
}
