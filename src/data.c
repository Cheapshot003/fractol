#include "../includes/fractol.h"

t_data  init_data()
{
    t_data data;

    data.zoom = 1.0;
    data.fractal = 0;
    data.movex = 0;
    data.movey = 0;
	data.ki = 0.5;
	data.kr = 0.187;
    return (data);
}