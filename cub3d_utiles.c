#include "cub3d.h"

t_play	*play(void)
{
	static t_play	data;

	return (&data);
}

void	error_mg(char *error_message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(error_message, 1);
	write(1, "\n", 1);
	exit(1);
}