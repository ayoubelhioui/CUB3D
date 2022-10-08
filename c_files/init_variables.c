/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:06:03 by ijmari            #+#    #+#             */
/*   Updated: 2022/10/03 10:24:52 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initKeys(t_player *player, int key)
{
	if (key == 13 || key == 126)
		player->walkDirection = 1;
	if (key == 123)
		player->turnDirection = -1;
	if (key == 0)
		player->moveDirection = 1;
	if (key == 2)
		player->moveDirection = -1;
	if (key == 1 || key == 125)
		player->walkDirection = -1;
	if (key == 124)
		player->turnDirection = 1;
}

float	getInitPos(t_directions *path)
{
	if (path->startPosition == 'N')
		return ((3 * M_PI) / 2);
	if (path->startPosition == 'W')
		return (M_PI);
	if (path->startPosition == 'S')
		return ((M_PI / 2));
	if (path->startPosition == 'E')
		return (0);
	return (0);
}

void	init_player(t_directions *path, t_player *player)
{
	player->x = (path->PLAYER_X + 0.5) * 64;
	player->y = (path->PLAYER_Y + 0.5) * 64;
	player->height = get_height(path);
	player->width = get_width(path);
	player->width_for_each = get_widths(path, player->height);
	player->turnDirection = 0;
	player->walkDirection = 0;
	player->tab_press = 0;
	player->rotationAngle = getInitPos(path);
	player->walkSpeed = 0.60 * 64;
	player->turnSpeed = 10 * (M_PI / 180);
	player->image.mlx = mlx_init();
	player->image.win = mlx_new_window(player->image.mlx, 1500, 900, "Cub3d");
	player->data = path;
	player->ray = malloc(1500 * sizeof(t_ray));
}

void	get_value_back(t_player *player)
{
	player->walkDirection = 0;
	player->turnDirection = 0;
	player->moveDirection = 0;
}

void	set_player(float a, float b, t_player *player)
{
	player->x = a;
	player->y = b;
}