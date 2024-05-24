#include "so_long.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*temp_dest;

	temp_dest = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp_dest);
}
