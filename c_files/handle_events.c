/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:28:53 by ijmari            #+#    #+#             */
/*   Updated: 2022/10/03 10:16:49 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	next_frame(int key, t_player *player)
{
	if (key == 53)
	{
		free(player->ray);
		free(player->width_for_each);
		exit(1);
	}
	initKeys(player, key);
	mlx_clear_window(player->image.mlx, player->image.win);
	change_player_status(player);
	get_rays(player);
	render_3d(player);
	mlx_put_image_to_window(player->image.mlx, \
		player->image.win, player->img.img, 0, 0);
	get_value_back(player);
	return (0);
}

int	stop(void)
{
	return (0);
}

int	close_win(t_player *player)
{
	free(player->width_for_each);
	free(player->ray);
	exit(1);
}
