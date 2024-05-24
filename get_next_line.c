#include "so_long.h"

static char	*read_line(int fd, char *buff, char *backup)
{
	int		read_line;
	char	*save;

	read_line = 1;
	while (read_line)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if (read_line == -1)
		{
			free(backup);
			return (NULL);
		}
		else if (read_line == 0)
			break ;
		buff[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		save = backup;
		backup = ft_strjoin(save, buff);
		free(save);
		save = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (backup);
}

static char	*getline_updatebuff(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (NULL);
	backup = ft_strdup(line + count + 1);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*backup[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = read_line(fd, buff, backup[fd]);
	free(buff);
	if (!line)
		return (NULL);
	buff = NULL;
	backup[fd] = getline_updatebuff(line);
	return (line);
}
