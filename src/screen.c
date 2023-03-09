/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <ole@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:04:34 by ole               #+#    #+#             */
/*   Updated: 2023/03/09 10:44:40 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
void    init_screen(int screenx, int screeny, t_data *data)
{
	

    data->screen.mlx = mlx_init();
    data->screen.mlx_win = mlx_new_window(data->screen.mlx, screenx, screeny, "Fractol");
    data->screen.image.img = mlx_new_image(data->screen.mlx, screenx, screeny);
    data->screen.image.addr = mlx_get_data_addr(data->screen.image.img, &(data->screen.image.bits_per_pixel),
     &(data->screen.image.line_length), &(data->screen.image.endian));
    mlx_put_image_to_window(data->screen.mlx, data->screen.mlx_win, data->screen.image.img, 0, 0);
	mlx_hook(data->screen.mlx_win, 17, 1L<<0, &close2, data);
	mlx_key_hook(data->screen.mlx_win, &close1, data);
    return ;
}