#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include "printf/ft_printf.h"
#include "getnextline/get_next_line.h"

int main(void)
{
	int	fd;
	int i;
	
	i = 1;
	fd = open("map.ber", O_RDONLY);

	while(i <= 5)
	{
		ft_printf("fd: %s", get_next_line(fd));
		i++;
	}

	return (0);
}
