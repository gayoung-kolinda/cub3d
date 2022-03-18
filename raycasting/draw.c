
#include "../cub3d.h"

void	find_which_wall(t_ray *ray)
{
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->nswe = 0;
	if (ray->side == 1 && ray->raydir_y > 0)
		ray->nswe = 1;
	if (ray->side == 0 && ray->raydir_x < 0)
		ray->nswe = 2;
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->nswe = 3;
}

void	draw_fnc(int x)
{
	int		i;

	i = 0;
	while (i < HEIGHT)
	{
		if (i > HEIGHT / 2)
			play()->screen_data[(play()->size_line / 4)
				* i + x] = play()->ceiling_corol[0];//check
		else
			play()->screen_data[(play()->size_line / 4)
				* i + x] = play()->floor_corol[0];//check
		i++;
	}
}

void	draw_texture(t_texture *texture,
		t_ray *ray, int *st_end)
{
	double		step;
	double		temp_y;
	int			tex_y;

	temp_y = 0;
	step = 1.0 * texture[ray->nswe].height / ray->line_height;
	while (st_end[0] < st_end[1])
	{
		tex_y = temp_y;
		play()->screen_data[(play()->size_line / 4) * st_end[0] + st_end[2]]
			= texture[ray->nswe].img_data[(texture[ray->nswe].size_line / 4)
			* tex_y + ray->tex_x];
		st_end[0]++;
		temp_y += step;
	}
}

void	draw(t_texture *texture, t_ray *ray, int x)
{
	int		st_end[3];

	st_end[0] = HEIGHT / 2 - ray->line_height / 2;
	st_end[1] = HEIGHT / 2 + ray->line_height / 2;
	st_end[2] = x;
	if (st_end[0] < 0)
		st_end[0] = 0;
	if (st_end[1] > HEIGHT)
		st_end[1] = HEIGHT;
	find_which_wall(ray);
	ray->tex_x = ray->hit_point * texture[ray->nswe].width;
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = texture[ray->nswe].width - (ray->tex_x + 1);
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = texture[ray->nswe].width - (ray->tex_x + 1);
	draw_fnc(x);
	draw_texture(texture, ray, st_end);
}