/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:37:47 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/04 15:39:27 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	all_free(char **str)
{
	int i = 0;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int rgb_input(int i, char **input)
{
	char	**rgb;

	rgb = ft_split(input[1], ',');
	if (rgb == NULL)
	{
		all_free(input);
		return (1);
	}
	if (i == 8)
	{
		play()->floor_corol[0] = ft_atoi(rgb[0]);
		play()->floor_corol[1] = ft_atoi(rgb[1]);
		play()->floor_corol[2] = ft_atoi(rgb[2]);
	}
	else
	{
		play()->ceiling_corol[0] = ft_atoi(rgb[0]);
		play()->ceiling_corol[1] = ft_atoi(rgb[1]);
		play()->ceiling_corol[2] = ft_atoi(rgb[2]);
	}
	all_free(rgb);
	return (0);
}

int	get_init_data(char *line, int i)
{
	char	**input; //free 시켜줘야하는 친구!

	if (line == NULL)
		return (0);
	input = ft_split(line, ' ');
	if (input == NULL)
		return (1);
	if (i >= 1 && i <= 4)
	{
		if (ft_strcmp(input[0], "NO") == 0)
			play()->image_address[0] = ft_strdup(input[1]);	
		else if (ft_strcmp(input[0], "SO") == 0)
			play()->image_address[1] = ft_strdup(input[1]);
		else if (ft_strcmp(input[0], "WE") == 0)
			play()->image_address[2] = ft_strdup(input[1]);
		else if (ft_strcmp(input[0], "EA") == 0)
			play()->image_address[3] = ft_strdup(input[1]);
	}
	else if (i == 6 || i == 7)
	{
		if (rgb_input(i, input))
			return (1);
	}
	all_free(input);
	return (0);
}

int	get_map_data(char **line)
{
	char	*temp;

	temp = ft_strjoin(*line, "\n");
	if (temp == NULL)
		return (1);
	free(*line);
	*line = temp;
	temp = ft_strjoin(play()->map_line, *line);
	if (temp == NULL)
		return (1);
	free(play()->map_line);
	play()->map_line = temp;
	return (0);
}