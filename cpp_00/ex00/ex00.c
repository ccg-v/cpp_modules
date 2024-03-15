#include <unistd.h>

int	main(int argc, char **argv)
{
	int 	i;
	int 	j;
	char	c;

	i = 1;
	if (argc == 1)
		write(1, "* LOUD AND UNBEARABLE FEEDBACK NOISE *", 38);
	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				c = argv[i][j];
				if (c >= 'a' && c <= 'z')
					c = c - 32;
				write(1, &c, 1);
				j++;
			}
			i++;
		}
	}
	return (0);
}
