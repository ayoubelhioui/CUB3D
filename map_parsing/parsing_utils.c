/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:15:12 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/10/09 13:23:37 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    texturesCounterChecker(int *textureCounter, char *message)
{
	if (*textureCounter == 1)
		errorMessage(message);
	*textureCounter = 1;
}

void	checking_duplicate_init(t_checkDuplicate *checkDuplicate)
{
	checkDuplicate->noCounter = 0;
	checkDuplicate->cCounter = 0;
	checkDuplicate->weCounter = 0;
	checkDuplicate->soCounter = 0;
	checkDuplicate->eaCounter = 0;
	checkDuplicate->fCounter = 0;
	
}

void	path_init(t_directions *path)
{
	path->NORTH = NULL;
	path->EAST = NULL;
	path->WEST = NULL;
	path->SOUTH = NULL;
	path->CEILING_COLOR = 0;
	path->FLOOR_COLOR = 0;
}

void	rgb_init(t_checking_rgb *var)
{
	var->digitsCounter = 0;
	var->base = 16;
	var->colorNumber = 0;
	var->commasCounter = 0;
	var->end = 0;
	var->i = 0;
	var->number = NULL;
	var->start = 0;
	var->value = 0;
}

void	ft_free(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		free(data[i++]);
	free (data);
}

void	errorMessage(char *message)
{
	printf("%s\n", message);
	exit (1);
}

// void	choosing_direction_utils( t_checkDuplicate *vars, char **data, t_directions *path)
// {
// 	char	*realDirectionPath;

// 	realDirectionPath = ft_strdup(data[1]);
// 	if (!ft_strncmp(data[0], _NORTH))
// 	{
// 		texturesCounterChecker(&vars->noCounter, NORTH_TEXTURE_DUPLICATE);
// 		path->NORTH = realDirectionPath;
// 	}
// 	else if (!ft_strncmp(data[0], _WEST))
// 	{
// 		texturesCounterChecker(&vars->weCounter, WEST_TEXTURE_DUPLICATE);
// 		path->WEST = realDirectionPath;
// 	}
// 	else if (!ft_strncmp(data[0], _EAST))
// 	{
// 		texturesCounterChecker(&vars->eaCounter, EAST_TEXTURE_DUPLICATE);
// 		path->EAST = realDirectionPath;
// 	}
// 	else if(!ft_strncmp(data[0], _SOUTH))
// 	{
// 		texturesCounterChecker(&vars->soCounter, SOUTH_TEXTURE_DUPLICATE);
// 		path->SOUTH = realDirectionPath;
// 	}
// 	else
// 		errorMessage(INVALID_DIRECTION_MSG);
// }

// void	choosing_directions(char *direction, \
// t_directions *path, t_checkDuplicate *vars)
// {
// 	char	**data;

// 	data = ft_split(direction, SPACE);
// 	if (access(data[1], F_OK))
// 		errorMessage(NOTFOUND_TEXTURE_MSG);
// 	choosing_direction_utils(vars, data, path);
// 	ft_free (data);
// }
