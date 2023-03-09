#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include "../libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#define SCREEN_X 960
#define SCREEN_Y 540
#define MAXITER 100

typedef struct s_julia
{
	double kr;
	double ki;
	/* data */
} t_juila;

typedef struct s_view
{
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
} t_view;


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_img;


typedef struct s_screen
{
	void	*mlx;
	void	*mlx_win;
	t_img	image;
} t_screen;

typedef struct s_data 
{
	int			fractal;    // 1: Mandelbrot; 2: Julia
	double		zoom;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	double		kr;
	double		ki;
	
	int			movex;
	int			movey;
	t_screen	screen;
} t_data;


void	mandelbrot(t_data *data);
void	julia(t_data *data);
int		check_args(int argc, char **argv);
void	wrong_args();
void	init_screen(int screenx, int screeny, t_data *data);
t_data	init_data();
void	free_all(t_data *data);
void	put_pixel_img(t_img data, int x, int y, int color);
int		calc_mandelbrot(double x, double y);
int		mandelbrot_pixel(int x_pixel, int y_pixel);
double	getX(int x, t_data view);
double	getY(int y, t_data view);
int		close1(int key, t_data	*data);
int		close2(t_data	*data);
int		getColor(int iters);
void	zoom(t_data *data, double zoom);
double	ft_atof(char *str);
int		calc_julia(t_data *data, double zr, double zi);
int		ft_isspace(char c);
void	move(t_data *data, double dist, char dir);

#endif
