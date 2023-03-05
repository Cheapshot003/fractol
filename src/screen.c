/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <ole@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:04:34 by ole               #+#    #+#             */
/*   Updated: 2023/03/04 22:28:01 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    init_screen(int screenx, int screeny, t_data *data)
{
    t_screen *screen;

    screen = data->screen;
    screen->mlx = mlx_init();
    screen->mlx_win = mlx_new_window(screen->mlx, screenx, screeny, "Fractol");
    screen->image->img = mlx_new_image(screen->mlx, screenx, screeny);
    screen->image->addr = mlx_get_data_addr(screen->image->img, &(screen->image->bits_per_pixel),
     &(screen->image->line_length), &(screen->image->endian));
    mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->image->img, 0, 0);
	mlx_hook(screen->mlx_win, 17, 1L<<0, close1, data);
    return ;
}