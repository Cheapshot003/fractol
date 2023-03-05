#include "../includes/fractol.h"

t_data  *init_data()
{
    t_data *data;

    data = malloc(sizeof(t_data));
    data->zoom = 0;
    data->fractal = 0;
    data->movex = 0;
    data->movey = 0;
    data->screen = malloc(sizeof(t_screen));
	data->screen->image = malloc(sizeof(data->screen->image));
	data->screen->mlx = malloc(sizeof(data->screen->mlx));
	data->screen->mlx_win = malloc(sizeof(data->screen->mlx_win));
    data->screen->image = malloc(sizeof(t_img));
    return (data);
}