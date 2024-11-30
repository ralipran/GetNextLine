#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int fd = open("bjr.txt", O_RDONLY);
	if (fd == -1)
	{
    	printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
	}
	printf("%s\n", get_next_line(fd));
	return (0);
}