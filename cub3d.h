/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hiou <ael-hiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:26:26 by ael-hiou          #+#    #+#             */
/*   Updated: 2022/10/09 17:34:02 by ael-hiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "includes/get_next_line.h"
#include "library/library.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

#define DOUBLE_NEW_LINE "\033[0;31mError \nMAP Contain Multiple New Lines"
#define CEILING_COLOR_MISSING "\033[0;31mError \nCeiling Color Is Missing"
#define FLOOR_COLOR_MISSING "\033[0;31mError \nFloor Color Is Missing"
#define SOUTH_TEXTURE_MISSING "\033[0;31mError \nSOUTH Texture Is Missing"
#define NORTH_TEXTURE_MISSING "\033[0;31mError \nNORTH Texture Is Missing"
#define WEST_TEXTURE_MISSING "\033[0;31mError \nWEST Texture Is Missing"
#define EAST_TEXTURE_MISSING "\033[0;31mError \nEAST Texture Is Missing"
#define NORTH_TEXTURE_DUPLICATE "\033[0;31mError \nNorth Texture Already Defined"
#define WEST_TEXTURE_DUPLICATE "\033[0;31mError \nWest Texture Already Defined"
#define EAST_TEXTURE_DUPLICATE "\033[0;31mError \nEast Texture Already Defined"
#define SOUTH_TEXTURE_DUPLICATE "\033[0;31mError \nSouth Texture Already Defined"
#define FLOOR_DUPLICATE "\033[0;31mError \nFloor Color Already Defined"
#define CEILING_DUPLICATE "\033[0;31mError \nCeiling Color Already Defined"
#define MISSING_PLAYER_MSG "\033[0;31mError \nMap Must Contain A Player"
#define INVALID_MAP "\033[0;31mError \nInvalid Map"
#define SURROUNDED_SPACE_MSG "\033[0;31mError \nSpace Should Be Surrounded By Walls"
#define SURROUNDED_MSG "\033[0;31mError \nMap Should Be Surrounded By Walls"
#define INVALID_DIRECTION_MSG "\033[0;31mError \nInvalid Input"
#define NOTFOUND_TEXTURE_MSG "\033[0;31mError \nTexture Not Found"
#define WRONG_RGB_MSG "\033[0;31mError \nWrong RGB Format"
#define FLOOR_CEILING_MISSING_MSG "\033[0;31mError \nFloor Or Ceiling Color Missing"
#define UNWANTED_CHARACTER_MSG "\033[0;31mError \nUnwanted Character Exist"
#define CONTAIN_MORE_MSG "\033[0;31mError \nMap Mustn't Contain More Than 1 Player"
#define ERROR_OCCURRED "Error occurred"
#define _NORTH "NO"
#define _WEST "WE"
#define _EAST "EA"
#define _SOUTH "SO"
#define FLOOR 'F'
#define CEILING 'C'
#define TRUE 1
#define FALSE 0
#define SPACE ' '
#define COMMA ','
#define NEW_LINE '\n'
#define ZERO '0'
#define TAB '	'
#define ONE '1'

typedef struct checkDuplicate
{
    int fCounter;
    int cCounter;
    int noCounter;
    int soCounter;
    int eaCounter;
    int weCounter;
}               t_checkDuplicate;
typedef struct directions
{
	char	startPosition;
	int     PLAYER_X;
	int		PLAYER_Y;
	int		FLOOR_COLOR;
	int		CEILING_COLOR;
	char	*NORTH;
	char	*WEST;
	char	*EAST;
	char	*SOUTH;
	char	**map;
}
				t_directions;

typedef struct checking_rgb
{
	int	digitsCounter;
	int	i;
	int start;
	int end;
	int	commasCounter;
	int	colorNumber;
	int	value;
	int	base;
	char	*number;	
}			t_checking_rgb;

typedef struct getting_textures
{
	int				map_size;
	int				i;
	char			**s;
	char			**data;
}					t_getting_textures;

typedef struct s_img
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*img;
	void	*win;
}	t_img;

typedef struct  s_data {
	void    *img;
	char    *addr;
	int             bits_per_pixel;
	int             line_length;
	int             endian;
}	t_data;
typedef struct s_ray
{
	float distance;
	float ray_angle;
	float Wallhitx;
	float Wallhity;
	int   was_hit_vertical;
	int ray_content;
	int isRay_left;
	int isRay_right;
	int isRay_down;
	int isRay_up;
}	t_ray;

typedef struct s_player
{
	float		x;
	float		y;
	int *width_for_each;
	int height;
	int width;
	int turnDirection;
	int walkDirection;
	int moveDirection;
	int	tab_press;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
	int pic_width;
	int pic_height;
	t_data img1;
	t_data img2;
	t_data img3;
	t_data img4;
	t_data img5;
	t_img	image;
	t_data img;
	t_directions *data;
	t_ray  *ray;
	int *fixes;
}	t_player;

typedef struct s_ray_steps
{
	float x_intercept;
	float y_intercept;
	float xstep;
	float ystep;
	int   ray_down;
	int   ray_up;
	int   ray_left;
	int   ray_right;
	float distance;
	float found_wall;
	float Wall_x;
	float Wall_y;
	int vertical;
}	t_ray_steps;

typedef struct s_threed_handle
{
	int Xoffset;
	int ceil_y;
	int floor_y;
	int loop;
	int put_pos;
} t_threed_handle;

void 	unwanted_characters(char *map, t_directions *path, int *isExist);
void	checking_duplicate_init(t_checkDuplicate *checkDuplicate);
void	rgb_init(t_checking_rgb *var);
void    unwantedCharactersUtils(int *isExist, char **map, t_directions  *path, int i);
void    unwantedCharacters(char **map, t_directions *path);
void    texturesCounterChecker(int *textureCounter, char *message);
void	checkingRGBFormatUtils(char *directions, t_checking_rgb *var);
int		checkingRGBFormat(char *secondPart);
void	choosing_directions(char *firstPart, char *secondPart, t_directions *path, t_checkDuplicate *checkDuplicate);
void	ft_free(char **data);
void	errorMessage(char *message);
void	path_init(t_directions *path);
void	isSurroundedByWalls(char **map, int map_height);
void	mapValidation(t_directions *path);
void	errorMessage(char *message);
int		getSize(char **data);
void	startGame(t_directions *path);
void	initKeys(t_player *player, int key);
float	getInitPos(t_directions *path);
void	init_player(t_directions *path, t_player *player);
void	get_value_back(t_player *player);
void	set_player(float a, float b, t_player *player);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw_elem(int x, int y, t_player *player, int color);
void	draw_line(t_player *player, float endX, float endY, int color);
unsigned int	get_color(int y, int x, t_data *img);
void	put_image_strip(t_player *player, int index, \
t_threed_handle *data, int yoffset);
void	handle_multiple3d(t_threed_handle *data, t_player *player, \
int index, float project_height);
void	handle_single3d(t_threed_handle *data, t_player *player, \
int index, float project_height);
void	put_stripin3d(t_player *player, float project_height, int index);
void	render_3d(t_player *player);
int		get_width(t_directions *path);
int		get_height(t_directions *path);
int		*get_widths(t_directions *path, int height);
void	create_images(t_player *player);
int		close_win(t_player *player);
int		stop(void);
int		next_frame(int key, t_player *player);
float	distance(t_player *p, float Wallx, float Wally);
void	fill_data(t_ray *ray, float angle, t_ray_steps data, int was_vertical);
t_ray_steps	get_vert_steps(t_player *player, float angle);
t_ray_steps	get_horz_steps(t_player *player, float angle);
void	set_distance(t_ray_steps *data, t_player *player);
void	horz_distance(t_ray_steps *data, t_player *player);
void	vert_distance(t_ray_steps *data, t_player *player);
void	cast_ray(t_player *player, float angle);
void	get_rays(t_player *player);
int		iswall(float a, float b, t_player *player);
void	change_player_status(t_player *player);