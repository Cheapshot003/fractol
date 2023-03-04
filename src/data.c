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
    return (data);
}