/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <ole@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:51:58 by ole               #+#    #+#             */
/*   Updated: 2023/03/09 20:37:52 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    mandelbrot(t_data *data)
{
    int x;
    int y;
	int	iters;

	iters = 0;
    data->fractal = 1;
    x = 0;
    ft_putstr_fd("mandel\n", 1);
    while (x <= SCREEN_X)
    {
        y = 0;
        while (y <= SCREEN_Y)
        {
			iters = calc_mandelbrot(getX(x, *data), getY(y, *data));
            if (iters >= MAXITER)
                put_pixel_img(data->screen.image, x, y, 0x00FF0000);
			else
				put_pixel_img(data->screen.image, x, y, getColor(iters));
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->screen.mlx, data->screen.mlx_win, data->screen.image.img, 0, 0);
    mlx_loop(data->screen.mlx);
    return ;
}

int	getColor(int iters)
{
	return (0xFF0000000 + iters * 10);
}

void julia(t_data *data)
{
	int	iters;
	int	x;
	int	y;

	x = 0;
	y = 0;
	
    data->fractal = 2;

    ft_putstr_fd("julia\n", 1);
	while (x <= SCREEN_X)
    {
        y = 0;
        while (y <= SCREEN_Y)
        {
			iters = calc_julia(data, getX(x, *data), getY(y, *data));
            if (iters >= MAXITER)
                put_pixel_img(data->screen.image, x, y, 0x00FF0000);
			else
				put_pixel_img(data->screen.image, x, y, getColor(iters));
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->screen.mlx, data->screen.mlx_win, data->screen.image.img, 0, 0);
    mlx_loop(data->screen.mlx);
	
    mlx_loop(data->screen.mlx);
    return ;
}

double  getX(int x, t_data view)
{
    double x1;

    x1 = x / 960.0 * (view.xmax - view.xmin) + view.xmin;
    return (x1);
}

double  getY(int y, t_data view)
{
    double y1;

    y1 = y / 540.0 * (view.ymax - view.ymin) + view.ymin;
    return (y1);
}