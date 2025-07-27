/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:29:43 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/27 18:24:53 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_tile(t_map *map, int x, int y)
{
	int	type;

	type = map->array[y / IMG_PXL][x / IMG_PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.empty, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.player_down, x + 8, y);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.exit, x, y);
	else if (type == '1')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x, y);
}

void	render_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			render_tile(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_moves(t_map *map)
{
	char	*move;
	int *w;
	int n;
	
	n = IMG_PXL;
	w = &n;
	move = ft_itoa(map->moves);
	mlx_string_put(map->mlx, map->wnd,
		60, 60, 0x000000, move);
	mlx_xpm_file_to_image(map->mlx,
			"textures/door.xpm", w, w);
	write(1, move, ft_strlen(move));
	write(1, " moves\n", 7);
	free(move);
}