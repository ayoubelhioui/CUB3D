/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:32:16 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/10/10 10:58:03 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    isSurroundedByWallsUtils(char *trimmed)
{
    int j;

    j = 0;
    while (trimmed[j])
    {
        if (trimmed[j] != '1' && trimmed[j] != SPACE)
            errorMessage(SURROUNDED_MSG);
        j++;
    }
}

void	isSurroundedByWalls(char **map, int map_height)
{
	int	stringLength;
	int	i;
	char	*trimmed;

	i = 0;
	stringLength = 0;
	while (map[i])
	{
		trimmed = ft_strtrim(map[i], " ");
		stringLength = ft_strlen(trimmed) - 1;
		if (is_full_spaces(trimmed))
		{
			i++;
			continue;
		}
		else if (trimmed[0] != '1' || trimmed[stringLength] != '1')
            errorMessage(SURROUNDED_MSG);
		if (i == 0 || i == map_height - 1)
            isSurroundedByWallsUtils(trimmed);
		free (trimmed);
		i++;
	}
}


int	check_for_double_newlines(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == NEW_LINE && map[i + 1] == NEW_LINE)
			errorMessage(DOUBLE_NEW_LINE);
		i++;
	}
	return (0);
}
    
void unwanted_characters(t_secondPartVars *vars)
{
    int j;

    j = 0;
    while (vars->enteredData[j])
    {
        if (vars->enteredData[j] == 'N' || vars->enteredData[j] == 'S' || vars->enteredData[j] == 'W' || vars->enteredData[j] == 'E')
        {
            if (vars->isPlayerExist == 0)
                vars->isPlayerExist = 1;
            else
                errorMessage(CONTAIN_MORE_MSG);
        }
        else if (vars->enteredData[j] != ZERO && vars->enteredData[j] != ONE && vars->enteredData[j] != SPACE && vars->enteredData[j] != NEW_LINE)
            errorMessage(UNWANTED_CHARACTER_MSG);
        j++;
    }
}