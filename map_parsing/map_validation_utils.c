/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:32:16 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/10/09 17:41:28 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void    unwantedCharactersUtils(int *isExist, char **map, t_directions  *path, int i)
// {
//     int j;

//     j = 0;
//     while (map[i][j])
//     {
//         if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
//         {
//             if (*isExist == 0)
//             {
//                 path->PLAYER_Y = i;
//                 path->PLAYER_X = j;
//                 path->startPosition = map[i][j];
//                 *isExist = 1;
//             }
//             else
//                 errorMessage(CONTAIN_MORE_MSG);
//         }
//         else if (map[i][j] != ZERO && map[i][j] != ONE && map[i][j] != SPACE)
//             errorMessage(UNWANTED_CHARACTER_MSG);
//         j++;
//     }
// }

// void    unwantedCharacters(char **map, t_directions *path)
// {
//     int i;
//     int isExist;

//     i = 0;
//     isExist = 0;
//     while (map[i])
// 	{
//         unwantedCharactersUtils(&isExist, map, path, i);
// 		i++;
// 	}
// 	if (isExist == 0)
// 		errorMessage(MISSING_PLAYER_MSG);
// }

void unwanted_characters(char *map, t_directions *path, int *isExist)
{
    int j;

    j = 0;
    while (map[j])
    {
        if (map[j] == 'N' || map[j] == 'S' || map[j] == 'W' || map[j] == 'E')
        {
            if (*isExist == 0)
            {
                // printf("the player is : %c, i is : %d and j is : %d\n", map[j], i, j);
                // path->PLAYER_Y = j;
                // path->PLAYER_X = i;
                path->startPosition = map[j];
                printf("start position is : %c\n", path->startPosition);
                *isExist = 1;
            }
            else
                errorMessage(CONTAIN_MORE_MSG);
        }
        else if (map[j] != ZERO && map[j] != ONE && map[j] != SPACE && map[j] != NEW_LINE)
            errorMessage(UNWANTED_CHARACTER_MSG);
        j++;
    }
}