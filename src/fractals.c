#include "../includes/fractol.h"

void    mandelbrot(t_data *data)
{
    data->movex++;
    ft_putstr_fd("mandel\n", 1);
    return ;
}

void julia(t_data *data)
{
    ft_putstr_fd("julia\n", 1);
    data->movex++;
    return ;
}