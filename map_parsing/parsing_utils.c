/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:15:12 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/10/10 10:51:22 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    texturesCounterChecker(int *textureCounter, char *message)
{
	if (*textureCounter == 1)
		errorMessage(message);
	*textureCounter = 1;
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

int	getSize(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

void    missingTexture(t_checkDuplicate *vars)
{
    if (vars->soCounter == 0)
        errorMessage(SOUTH_TEXTURE_MISSING);
    else if (vars->weCounter == 0)
        errorMessage(WEST_TEXTURE_MISSING);
    else if (vars->noCounter == 0)
        errorMessage(NORTH_TEXTURE_MISSING);
    else if (vars->eaCounter == 0)
        errorMessage(EAST_TEXTURE_MISSING);
    else if (vars->fCounter == 0)
        errorMessage(FLOOR_COLOR_MISSING);
    else if (vars->cCounter == 0)
        errorMessage(CEILING_COLOR_MISSING);
}
