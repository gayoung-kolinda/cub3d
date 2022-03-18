/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:59:27 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/18 21:08:36 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    key_press(int keycode)
{
    if (keycode == KEY_ESC)
        exit(0);
    return (0);
}

int	init_data()
{
	play()->image_address = malloc(sizeof(char *) * 4);
	if (play()->image_address == NULL)
		return (0);
	play()->map_line = NULL;
	play()->player_direc = 'P';

	t_player    p;
    t_texture    t[4];

    play()->player = &p;
    play()->texture = t;
	return (1);
}

int	file_extension_check(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'b')
		return (0);
	if (filename[len - 2] != 'u')
		return (0);
	if (filename[len - 3] != 'c')
		return (0);
	if (filename[len - 4] != '.')
		return (0);
	return (1);
}

// void	texture_init()
// {
// 	int		i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		texture[i].img = mlx_xpm_file_to_image(window->mlx, texture[i].adr,
// 				&texture[i].width, &texture[i].height);
// 		if (texture[i].width < 1 && texture[i].width < 1)
// 			error("texture open error");
// 		texture[i].img_data = (unsigned int *)mlx_get_data_addr(texture[i].img,
// 				&texture[i].bpp, &texture[i].size_line, &texture[i].endian);
// 		i++;
// 	}
// }

// system("leaks cub3D");
// int main(int argc, char **argv)
int main()
{
    // if (argc == 2)
    // {
		if (init_data() == 0)
			error_mg("image_address malloc error");
		if (file_extension_check("map.cub") == 0) //argv로 바꿔야함
			error_mg("is not .cub file");
        if (read_cub_file("map.cub"))//argv로 바꿔야함
		    error_mg("Wrong Files");
		play()->map = ft_split(play()->map_line, '\n');
		if (play()->map_line == NULL)
			error_mg("Wrong map Files");
		if (map_error_check())
			error_mg("Invalid map");

		// texture_init();
		mlx_hook(play()->win, 2, 0, key_press, &play);
   		//mlx_hook(play()->win, 17, 0, destroy_notify, &window);
    	mlx_loop_hook(play()->mlx, raycasting, &play);
    	mlx_loop(play()->mlx);
		// mlx_loop_main();

    // }
    // else
    //     error_mg("Invalid input");
}