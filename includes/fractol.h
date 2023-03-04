#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include "../libft/libft.h"
#define SCREEN_X 960
#define SCREEN_Y 540
#define MAXITER 1000

typedef struct s_screen
{
    void *mlx;
    void *mlx_win;
} t_screen;

typedef struct s_data 
{
    int fractal;
    int zoom;
    int movex;
    int movey;
    t_screen *screen;
} t_data;


void    mandelbrot(t_data *data);
void    julia(t_data *data);
int     check_args(int argc, char **argv);
void    wrong_args();
void    init_screen(int screenx, int screeny, t_data *data);
t_data  *init_data();

#endif
