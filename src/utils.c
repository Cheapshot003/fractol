#include "../includes/fractol.h"

void    free_all(t_data *data)
{
    //mlx_destroy_image(data->screen->mlx, data->screen->image->img);
    //mlx_destroy_window(data->screen->mlx, data->screen->mlx_win);
    mlx_destroy_display(data->screen->mlx);
    return ;
}

void    put_pixel_img(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color; 
}

int	close1(int key, t_data	*data)
{
	key++;
	free_all(data);
	exit(EXIT_SUCCESS);
}