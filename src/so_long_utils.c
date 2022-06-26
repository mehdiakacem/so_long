/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:43:44 by makacem           #+#    #+#             */
/*   Updated: 2022/06/26 21:13:51 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	return_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	ft_map_length(char	**map_table)
{
	int	len;

	len = ft_strlen(map_table[0]);
	return (len);
}

int	ft_map_height(char	**map_table)
{
	int	len;

	len = 0;
	while (map_table[len] != NULL)
	{
		len++;
	}
	return (len);
}
