#include "../includes/fractol.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	int		start;
	t_data	*data;
	start = check_args(argc, argv);
	if (start == 2)
	{
		data = init_data();
		init_screen(SCREEN_X, SCREEN_Y, data);
		mandelbrot(data);
	}
	else if (start == 3)
	{
		data = init_data();
		init_screen(SCREEN_X, SCREEN_Y, data);
		julia(data);
	}
	return (0);
}
