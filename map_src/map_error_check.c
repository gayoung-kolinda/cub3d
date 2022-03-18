/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimhyeyeon <kimhyeyeon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:07:25 by kimhyeyeon        #+#    #+#             */
/*   Updated: 2022/03/18 21:04:38 by kimhyeyeon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dfs(int y, int x, int start_x)
{
	int x_arr[4];
	int y_arr[4];
	int x_;
	int y_;

	x_arr[0] = -1;
	x_arr[1] = 0;
	x_arr[2] = 1;
	x_arr[3] = 0;
	y_arr[0] = 0;
	y_arr[1] = 1;
	y_arr[2] = 0;
	y_arr[3] = -1;
	play()->map[y][x] = 'W';
	for (int i = 0; i < 4; i++)
	{	
		x_ = x_arr[i] + x;
		y_ = y_arr[i] + y;
		int len = ft_strlen(play()->map[y]);

		if (0 == y_ && start_x == x_)
		{
			play()->ret = 0;
			return ;
		}
		if (x_ >= 0 && y_ >= 0 && x_ < len && y_ < play()->colum && play()->map[y_][x_] == '1')
			dfs(y_, x_, start_x);
	}
}

int	get_map_size(void)
{
	int k;
	int max_row;
	int len;

	k = 0;
	max_row = 0;
	while (play()->map[k])
	{
		len = ft_strlen(play()->map[k]);
		if (max_row < len)
			max_row = len;
		k++;
	}
	play()->max_len = max_row;
	play()->colum = k;
	if (k == 0)
		return (0);
	return (1);
}

int not_recover_wall(void)
{
	int j;
	
	if (get_map_size() == 0)
		return (1);
	j = 0;
	while (play()->map[0][j] && play()->map[0][j] != '1')
		j++;
	play()->ret = 1;
	if (play()->map[1][j] == '1' && play()->map[2][j] == '1')
	{
		play()->map[0][j] = 'W';
		play()->map[1][j] = 'W';
		dfs(2, j, j);
	}
	else
		return (1);
	return (play()->ret);
}

int map_error_check(void)
{
	 // 갯수들이 멀쩡하니 다있니 중복된거 없나 없는거 없나ㅏ
	if (error_check_map_components())
		return (1);
	if (not_recover_wall()) //벽으로 둘러 쌓여 있나 //중간에 벽이 이어져 있으면 밖에가 뚫여 있어도 뭐라고 안함
		return (1);
	return (0);
}