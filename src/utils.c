#include "../includes/fractol.h"
#include <stdio.h>

void    free_all(t_data *data)
{
	mlx_destroy_image(data->screen.mlx, data->screen.image.img);
	mlx_destroy_window(data->screen.mlx, data->screen.mlx_win);
	mlx_destroy_display(data->screen.mlx);
	free(data->screen.mlx);
	exit(EXIT_SUCCESS);
}

void    put_pixel_img(t_img data, int x, int y, int color)
{
    char    *dst;

    dst = data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8));
    *(unsigned int*)dst = color; 
}

int	close1(int key, t_data	*data)
{
	if (key == 65307)
	{
		free_all(data);
	}
	else if (key == 32)
		zoom(data, 0.5);
	else if (key == 65361)
	{
		move(data, 0.2, 'L');
	}
	else if (key == 65363)
	{
		move(data, 0.2, 'R');
	}
	else if (key == 65362)
	{
		move(data, 0.2, 'D');
	}
	else if (key == 65364)
	{
		move(data, 0.2, 'U');
	}
	else
		return (0);
	if (data->fractal == 1)
		mandelbrot(data);
	else if (data->fractal == 2)
		julia(data);
	printf("%d\n", key);
	return(0);
}

int	close2(t_data *data)
{
	free_all(data);
	return (0);
}

 void	zoom(t_data *data, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = data->xmin - data->xmax;
	center_i = data->ymax - data->ymin;
	data->xmax = data->xmax + (center_r - zoom * center_r) / 2;
	data->xmin = data->xmax + zoom * center_r;
	data->ymin = data->ymin + (center_i - zoom * center_i) / 2;
	data->ymax = data->ymin + zoom * center_i;
}