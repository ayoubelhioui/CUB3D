/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:47:40 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/10/10 10:49:14 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	checking_duplicate_init(t_checkDuplicate *checkDuplicate)
{
	checkDuplicate->noCounter = 0;
	checkDuplicate->cCounter = 0;
	checkDuplicate->weCounter = 0;
	checkDuplicate->soCounter = 0;
	checkDuplicate->eaCounter = 0;
	checkDuplicate->fCounter = 0;
	
}

void	map_content_init(t_mapContentVars *vars)
{
	vars->i = 0;
	vars->linesCounter = 0;
	vars->trimmedData = NULL;
}

void	second_part_init(t_secondPartVars *vars)
{
	vars->i = 0;
	vars->enteredData = NULL;
	vars->map = NULL;
	vars->isPlayerExist = 0;
	vars->counter = 0;
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