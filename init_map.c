#include "so_long.h"

int	check_map_name(char *name)
{
	int	len;

	len = 0;
	while (name[len] != '\0')
		len++;
	if (name[len - 4] == '.' && (name[len - 3] == 'b'
			&& (name[len - 2] == 'e' && name[len - 1] == 'r')))
		return (1);
	return (0);
}

int	count_len(int fd)
{
	int		read_line;
	char	*buff;
	int		len;

	read_line = 1;
	len = 0;
	buff = malloc(sizeof(char));
	if (!buff)
		exit(EXIT_FAILURE);
	while (read_line)
	{
		read_line = read(fd, buff, 1);
		if (buff[0] == '\n')
			break ;
		len++;
	}
	free(buff);
	return (len);
}

int	count_lines(int fd)
{
	int		lines;
	char	*line;

	lines = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lines++;
		free(line);
	}
	return (lines);
}

void	init_map(char *file, t_game *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0 || !check_map_name(file))
	{
		ft_printf("Map error\n");
		exit(EXIT_FAILURE);
	}
	game->map->width = count_len(fd);
	game->map->height = count_lines(fd);
}
