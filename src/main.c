#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	int		start;
	t_data	data;
	start = check_args(argc, argv);
	if (start == 2)
	{
		data = init_data();
		init_screen(SCREEN_X, SCREEN_Y, &data);
		data.xmax = 1.0;
		data.xmin = -2.0;
		data.ymax = 1.0;
		data.ymin = -1.0;
		mandelbrot(&data);
	}
	else if (start == 3)
	{
		data = init_data();
		init_screen(SCREEN_X, SCREEN_Y, &data);
		data.xmin = -2.0;
		data.xmax = 2.0;
		data.ymin = -2.0;
		if (argv[2])
			data.kr = ft_atof(argv[2]);
		if (argv[3])
		data.ki = ft_atof(argv[3]);
		data.ymax = data.ymin + (data.xmax - data.xmin) * SCREEN_Y / SCREEN_X;
		julia(&data);
	}
	return (0);
}
