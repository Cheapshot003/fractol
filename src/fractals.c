/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <ole@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:51:58 by ole               #+#    #+#             */
/*   Updated: 2023/03/04 22:21:42 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    mandelbrot(t_data *data)
{
    int x;
    int y;
	double	zoom;
    t_view  view;

	zoom = 1.0;
    view.xmax = 1.0 + (0.1 * data->movex) * zoom;
    view.xmin = -2.0 + (0.1 * data->movex) * zoom;
    view.ymax = 1.0 + (0.1 * data->movey) * zoom;
    view.ymin = -1.0 + (0.1 * data->movey) * zoom;
    
    data->fractal = 1;
    x = 0;
    ft_putstr_fd("mandel\n", 1);
    while (x <= SCREEN_X)
    {
        y = 0;
        while (y <= SCREEN_Y)
        {
            if (calc_mandelbrot(getX(x, view), getY(y, view)) < MAXITER)
                put_pixel_img(data->screen->image, x, y, 0x00FF0000);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->screen->mlx, data->screen->mlx_win, data->screen->image->img, 0, 0);
    ft_putchar_fd('5', 1);
    mlx_loop(data->screen->mlx);
    return ;
}

void julia(t_data *data)
{
    data->fractal = 2;

    ft_putstr_fd("julia\n", 1);
    mlx_loop(data->screen->mlx);
    return ;
}

double  getX(int x, t_view view)
{
    double x1;

    x1 = x / 960.0 * (view.xmax - view.xmin) + view.xmin;
    return (x1);
}

double  getY(int y, t_view view)
{
    double y1;

    y1 = y / 540.0 * (view.ymax - view.ymin) + view.ymin;
    return (y1);
}