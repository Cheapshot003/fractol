#include "../includes/fractol.h"

int check_args(int argc, char **argv)
{
    if (argc == 1)
        wrong_args();
    else if (!ft_strncmp(argv[1], "mandelbrot", 10))
        return (2);
    else if (!ft_strncmp(argv[1], "julia", 10))
        return (3);
    else
        wrong_args();
    return (4);
}

void    wrong_args()
{
    ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia\n", 1);
    exit(EXIT_FAILURE);
}

void    exit_free(t_data *data)
{
    free(data);
    exit(EXIT_SUCCESS);
}