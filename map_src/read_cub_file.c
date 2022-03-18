#include "../cub3d.h"

int read_cub_file(char *file_name)
{
    int fd;
    char	*line;
	int	i;
	int	rat;
	
	fd = open(file_name, O_RDONLY);
	line = NULL;
	i = 1;
	if (fd == -1 || play()->image_address == NULL)
		return (1);
	while (get_next_line(fd, &line) == 1)
	{
		if (i < 8)
			rat = get_init_data(line, i);
		else
			rat = get_map_data(&line);
		free(line);
		line = NULL;
		i++;
	}
	free(line);
	close(fd);
	return (rat);
}