# ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_X_BUTTON 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

# define WIDTH 1600 //SCREEN_W
# define HEIGHT 1200 //SCREEN_H

struct s_player;
struct s_texture;

typedef struct s_play
{
	void			*mlx;
	void			*win;
	void			*screen;
	unsigned int	*screen_data;
	int				bpp;
	int				size_line;
	int				endian;

	char			**image_address; //***image뿐만 아니라 안에 구성 요소들도 마지막에 전부 free 시켜 줘야함***
	char			**map; //***map뿐만 아니라 안에 구성 요소들도 마지막에 전부 free 시켜 줘야함***
	int				ceiling_corol[3]; //c_color
	int				floor_corol[3]; //f_color
	char			*map_line;
	int				ret;
	int				colum; //최대세로
	int				max_len; //맵의 최대가로길이 line_n(확인필요)

	struct s_player		*player;
	struct s_texture	*texture;

	char			player_direc;
	int				x;
	int				y;
}t_play;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_texture
{
	char			*adr;
	void			*img;
	unsigned int	*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct s_ray
{
	double			raydir_x;
	double			raydir_y;
	double			sidedist_x;
	double			sidedist_y;
	double			camera_x;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	double			hit_point;
	int				step_x;
	int				step_y;
	int				side;
	int				tex_x;
	int				line_height;
	int				map_x;
	int				map_y;
	int				nswe;
}					t_ray;

t_play	*play(void);
void	error_mg(char *error_message);

int	get_init_data(char *line, int i);
int	get_map_data(char **line);
int map_error_check(void);
int error_check_map_components(void);
int read_cub_file(char *file_name);

void	mlx_loop_main();

int	raycasting();
void	cast(t_ray *ray);
void	sum_ray(t_ray *ray);
void	check_step(t_player *player, t_ray *ray);

void	dist(t_player *player, t_ray *ray);
void	dir_camera_set(t_player *player, t_ray *ray, int x);

void	draw(t_texture *texture, t_ray *ray, int x);

#endif
