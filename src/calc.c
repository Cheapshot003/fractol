/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ole <ole@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:23:27 by ole               #+#    #+#             */
/*   Updated: 2023/03/04 22:02:22 by ole              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int calc_mandelbrot(double x, double y)
{
    double  real;
    double  imag;
    double  real2;
    double  imag2;
    double  temp;
    int     iterations;

    real = 0.0;
    imag = 0.0;
    real2 = 0.0;
    imag2 = 0.0;
    iterations = 0;
    while (iterations < MAXITER && real2 + imag2 <= 4.0)
    {
        temp = real2 - imag2 + x;
        imag = 2.0 * real * imag + y;
        real = temp;
        real2 = real * real;
        imag2 = imag * imag;
        iterations++;
    }
    //ft_putstr_fd(ft_itoa(iterations), 1);
    //ft_putchar_fd('\n', 1);
    return iterations;
}

