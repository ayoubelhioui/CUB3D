/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:26:09 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/10/08 14:41:39 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    checkingRFBFormatUtils1(t_checking_rgb *var, char *secondPart)
{
	(void)var;
	(void)secondPart;

    // if (ft_isdigit(secondPart[var->i]))
    // {
	// 	var->digitCounter = 0;
    //     var->start = var->i++;
	// 	while (secondPart[var->i] == SPACE)
	// 		var->i++;
    //     while (ft_isdigit(secondPart[var->i]))
	// 	{
	// 		var->i++;
	// 		var->digitCounter++;
	// 	}
	// 	while (secondPart[var->i] == SPACE)
	// 		var->i++;
    //     var->end = var->i - var->start;
    //     return ;
    // }
    // else if (secondPart[var->i] == COMMA)
    // {
	// 	var->i++;
	// 	while (secondPart[var->i] == SPACE)
	// 		var->i++;
    //     var->commasCounter++;
    //     var->number = ft_substr(secondPart, var->start, var->end);
    //     var->colorNumber = ft_atoi(var->number);
	// 	printf("[%d]\n", var->colorNumber);
    //     if (!(var->digitCounter >= 1 && var->digitCounter <= 3) || var->commasCounter > 2 ||\
    //     !(var->colorNumber >= 0 && var->colorNumber <= 255))
	// 	{
	// 		printf("heress and : %c and end is : %d\n", secondPart[var->i], var->end);	
    //     	errorMessage(WRONG_RGB_MSG);
	// 	}
    //     var->value += var->colorNumber << var->base;
    //     var->base -= 8;
    //     free (var->number);
    // }
    // else
	// {
	// 	printf("here and : %d and the index is : %d\n", secondPart[var->i], var->i);
    //     errorMessage(WRONG_RGB_MSG);
	// }
    // var->i++;
}

void	checkingRGBFormatUtils(char *secondPart, t_checking_rgb *var)
{
	while (secondPart[var->i])
        checkingRFBFormatUtils1(var, secondPart);
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

// void	gettingTexturesUtils(t_directions *path, t_getting_textures *vars)
// {
// 	t_checkDuplicate duplicateVars;

// 	while (vars->i < 6)
// 	{
// 		vars->s = ft_split(vars->data[vars->i], SPACE);
// 		if (!ft_strncmp(vars->s[0], "C") || !ft_strncmp(vars->s[0], "F"))
// 			ceilingFloorColor(vars->data[vars->i], path, &duplicateVars);
// 		else if (!ft_strncmp(vars->s[0], "WE") || !ft_strncmp(vars->s[0], "EA") ||\
//         !ft_strncmp(vars->s[0], "NO") || !ft_strncmp(vars->s[0], "SO"))
//             choosing_directions(vars->data[vars->i], path, &duplicateVars);
// 		vars->i++;
// 		ft_free(vars->s);
// 	}
//     missingTexture(&duplicateVars);
// }

// void	gettingTextures(char *map, t_directions *path)
// {
	
// 	t_getting_textures vars;

// 	vars.i = 0;
// 	vars.data = ft_split(map, NEW_LINE);
// 	vars.map_size = getSize(vars.data);
// 	path->map = malloc (sizeof(char *) * (vars.map_size - 6 + 1));
// 	init(path);
//     gettingTexturesUtils(path, &vars);
//     while (vars.data[vars.i])
// 	{
//         path->map[vars.i - 6] = ft_strdup(vars.data[vars.i]);
//         vars.i++;
//     }
//     path->map[vars.i - 6] = NULL;
//     mapValidation(path);
//     ft_free(vars.data);
// }

// int	check_for_double_new_line(char *map)
// {
// 	int startIndex;

// 	startIndex = get_start_index(map);
// 	if (startIndex == -1)
// 		return (0);
// 	while (map[startIndex])
// 	{
// 		if (map[startIndex] == NEW_LINE && map[startIndex + 1] == NEW_LINE)
// 			return (1);
// 		startIndex++;
// 	}
// 	return (0);
// }

//void	gettingTexturesUtils(t_directions *path, t_getting_textures *vars)
//{
//	t_checkDuplicate duplicateVars;
//
//	while (vars->i < 6)
//	{
//		vars->s = ft_split(vars->data[vars->i], SPACE);
//		if (!ft_strncmp(vars->s[0], "C") || !ft_strncmp(vars->s[0], "F"))
//			ceilingFloorColor(vars->data[vars->i], path, &duplicateVars);
//		else if (!ft_strncmp(vars->s[0], "WE") || !ft_strncmp(vars->s[0], "EA") ||\
//        !ft_strncmp(vars->s[0], "NO") || !ft_strncmp(vars->s[0], "SO"))
//            choosing_directions(vars->data[vars->i], path, &duplicateVars);
//		vars->i++;
//		ft_free(vars->s);
//	}
//    missingTexture(&duplicateVars);
//}

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
		errorMessage(NOTFOUND_TEXTURE_MSG);
	choosing_direction_utils(firstPart, secondPart, checkDuplicate, path);
}

void	ceilingFloorColor(char *firstPart, char *secondPart,t_directions *path, t_checkDuplicate *checkDuplicate)
{
	if (firstPart[0] == FLOOR)
    {
        texturesCounterChecker(&checkDuplicate->fCounter, FLOOR_DUPLICATE);
        path->FLOOR_COLOR = checkingRGBFormat(secondPart);
    }
	else
    {
        texturesCounterChecker(&checkDuplicate->cCounter, CEILING_DUPLICATE);
        path->CEILING_COLOR = checkingRGBFormat(secondPart);
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

void    get_type(char *enteredData, t_directions *path, t_checkDuplicate *checkDuplicate)
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

void	gettingMapContent(int fd, t_directions *path)
{
	char	*map;
	char	*data;
	char	*trimmed;
	int counter;
	int i;
	t_checkDuplicate checkDuplicate;

	i = 0;
	map = NULL;
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
			data[ft_strlen(data) - 1] = '\0';
			trimmed = ft_strtrim(data, " ");
			counter++;
        	get_type(trimmed, path, &checkDuplicate);
		}
		map = ft_strjoin(map, data);
		free (data);
		i++;
	}
	// printf("no : %s\n", path->NORTH);
	// printf("we : %s\n", path->WEST);
	// printf("ea : %s\n", path->EAST);
	// printf("so : %s\n", path->SOUTH);
	// printf("ceiling : %d\n", path->FLOOR_COLOR);
	// printf("floor : %d\n", path->CEILING_COLOR);
    exit (1);
	if (i < 9)
		errorMessage(INVALID_MAP);
	// gettingTextures(map, path);
	free (map);
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
			startGame(&path);
		}
	}
	else
		errorMessage(ERROR_OCCURRED);
}
