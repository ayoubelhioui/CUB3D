/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:26:09 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/10/10 10:58:50 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	choosing_direction_utils(char *firstPart, char *secondPart, t_checkDuplicate *vars, t_directions *path)
{
	if (!ft_strncmp(firstPart, _NORTH))
	{
		texturesCounterChecker(&vars->noCounter, NORTH_TEXTURE_DUPLICATE);
		path->NORTH = secondPart;
	}
	else if (!ft_strncmp(firstPart, _WEST))
	{
		texturesCounterChecker(&vars->weCounter, WEST_TEXTURE_DUPLICATE);
		path->WEST = secondPart;
	}
	else if (!ft_strncmp(firstPart, _EAST))
	{
		texturesCounterChecker(&vars->eaCounter, EAST_TEXTURE_DUPLICATE);
		path->EAST = secondPart;
	}
	else if(!ft_strncmp(firstPart, _SOUTH))
	{
		texturesCounterChecker(&vars->soCounter, SOUTH_TEXTURE_DUPLICATE);
		path->SOUTH = secondPart;
	}
	else
		errorMessage(INVALID_DIRECTION_MSG);
}

void	choosing_directions(char *firstPart,char *secondPart, t_directions *path, t_checkDuplicate *checkDuplicate)
{
	
	if (open(secondPart, R_OK) == -1)
	{
		free(firstPart);
		free(secondPart);
		errorMessage(NOTFOUND_TEXTURE_MSG);
	}
	choosing_direction_utils(firstPart, secondPart, checkDuplicate, path);
}

void	ceilingFloorColor(char *firstPart, char *secondPart,t_directions *path, t_checkDuplicate *checkDuplicate)
{
	(void)checkDuplicate;
	if (firstPart[0] == FLOOR)
	{
		path->FLOOR_COLOR = checkingRGBFormat(secondPart);
		checkDuplicate->fCounter = 1;
	}
	else
	{
        path->CEILING_COLOR = checkingRGBFormat(secondPart);
		checkDuplicate->cCounter = 1;
	}
}

int	get_first_index(char *enteredData)
{
	int	i;

	i = 0;
	while (enteredData[i] && enteredData[i] != SPACE)
		i++;
	while (enteredData[i] && enteredData[i] == SPACE)
		i++;
	return (i);
}

void    map_first_part(char *enteredData, t_directions *path, t_checkDuplicate *checkDuplicate)
{
	int firstIndex;
    char *firstPart;
	char *secondPart;
	
    firstPart = ft_substr(enteredData, 0, 2);
	firstIndex = get_first_index(enteredData);
	secondPart = ft_substr(enteredData, firstIndex, ft_strlen(enteredData) - ft_strlen(firstPart));
    if (!ft_strncmp(firstPart, "WE") || !ft_strncmp(firstPart, "EA") ||\
	 !ft_strncmp(firstPart, "NO") || !ft_strncmp(firstPart, "SO"))
    	choosing_directions(firstPart, secondPart, path, checkDuplicate);
    else if (!ft_strncmp(firstPart, "C ") || !ft_strncmp(firstPart, "F "))
		ceilingFloorColor(firstPart, secondPart, path, checkDuplicate);
    else
		errorMessage(INVALID_DIRECTION_MSG);
}

void	get_player_position(t_directions *path)
{
	int	i;
	int	j;

	i = 0;
	while (path->map[i])
	{
		j = 0;
		while (path->map[i][j])
		{
			if (path->map[i][j] == 'N' || path->map[i][j] == 'S' || path->map[i][j] == 'W' || path->map[i][j] == 'E')
			{
				path->startPosition = path->map[i][j];
				path->PLAYER_X = j;
				path->PLAYER_Y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	map_second_part(int fd, t_directions *path)
{	
	t_secondPartVars vars;

	second_part_init(&vars);
	while (TRUE)
	{
		vars.enteredData = get_next_line(fd);
		if (!vars.enteredData)
			break ;
		if (ft_strncmp(vars.enteredData, "\n"))
			vars.counter++;
		unwanted_characters(&vars);
		vars.map = ft_strjoin(vars.map, vars.enteredData);
		free (vars.enteredData);
	}
	if (vars.counter < 3)
		errorMessage(INVALID_MAP);
	if (vars.isPlayerExist == 0)
		errorMessage(MISSING_PLAYER_MSG);
	while (vars.map[vars.i] && vars.map[vars.i] == NEW_LINE)
		vars.i++;
	path->map = ft_split(vars.map + vars.i, NEW_LINE);
	get_player_position(path);
	check_for_double_newlines(vars.map + vars.i);
	mapValidation(path);
}
void	space_skipping(char *map, int *index)
{
	while (map[*index] && map[*index] == SPACE)
		(*index)++;
}

void	gettingMapContent(int fd, t_directions *path)
{
	t_mapContentVars vars;
	t_checkDuplicate checkDuplicate;

	checking_duplicate_init(&checkDuplicate);
	map_content_init(&vars);
	while (vars.linesCounter < 6)
	{
		vars.enteredData = get_next_line(fd);
		if (!vars.enteredData)
			break ;
		if (ft_strncmp(vars.enteredData, "\n"))
		{
			if (vars.enteredData[ft_strlen(vars.enteredData) - 1] == NEW_LINE)
				vars.enteredData[ft_strlen(vars.enteredData) - 1] = '\0';
			vars.trimmedData = ft_strtrim(vars.enteredData, " ");
			vars.linesCounter++;
        	map_first_part(vars.trimmedData, path, &checkDuplicate);
		}
		free (vars.enteredData);
		vars.i++;
	}
	if (vars.linesCounter < 6)
		errorMessage(INVALID_MAP);
	missingTexture(&checkDuplicate);
	map_second_part(fd, path);
}


int main(int ac, char **av)
{
	int fd;
	char	*cub_extension;
	t_directions	path;
	
	path_init(&path);
	cub_extension = search(av[1], '.');
	if (cub_extension && ft_strncmp(cub_extension, ".cub") == 0 && ac == 2)
	{
		fd = open(av[1], 2);
		gettingMapContent(fd, &path);
		startGame(&path);
	}
	else
		errorMessage(ERROR_OCCURRED);
}
