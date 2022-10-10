/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:26:09 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/10/09 20:37:44 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
	
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
	char	*map;
	char 	*data;
	int		isPlayerExist;
	int 	i;
	int 	counter;
	

	i = 0;
	data = NULL;
	map = NULL;
	isPlayerExist = 0;
	counter = 0;
	while (TRUE)
	{
		data = get_next_line(fd);
		if (!data)
			break ;
		if (ft_strncmp(data, "\n"))
			counter++;
		unwanted_characters(data, path, &isPlayerExist);
		map = ft_strjoin(map, data);
		free (data);
	}
	if (counter < 3)
		errorMessage(INVALID_MAP);
	if (isPlayerExist == 0)
		errorMessage(MISSING_PLAYER_MSG);
	while (map[i] && map[i] == NEW_LINE)
		i++;
	path->map = ft_split(map + i, NEW_LINE);
	get_player_position(path);
	check_for_double_newlines(map + i);
	mapValidation(path);
}
void	space_skipping(char *map, int *index)
{
	while (map[*index] && map[*index] == SPACE)
		(*index)++;
}

void	gettingMapContent(int fd, t_directions *path)
{
	t_checkDuplicate checkDuplicate;
	char	*data;
	char	*trimmed;
	int counter;
	int i;

	i = 0;
	counter = 0;
	checking_duplicate_init(&checkDuplicate);
	trimmed = NULL;
	while (counter < 6)
	{
		data = get_next_line(fd);
		if (!data)
			break ;
		if (ft_strncmp(data, "\n"))
		{
			if (data[ft_strlen(data) - 1] == NEW_LINE)
				data[ft_strlen(data) - 1] = '\0';
			trimmed = ft_strtrim(data, " \n");
			counter++;
        	map_first_part(trimmed, path, &checkDuplicate);
		}
		free (data);
		i++;
	}
	if (counter < 6)
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
	if (cub_extension && ac == 2)
	{
		if (ft_strncmp(cub_extension, ".cub") == 0)
		{
			fd = open(av[1], 2);
			gettingMapContent(fd, &path);
			printf("here\n");
			startGame(&path);
		}
	}
	else
		errorMessage(ERROR_OCCURRED);
}
