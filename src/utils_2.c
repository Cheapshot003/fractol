#include "../includes/fractol.h"

#include <ctype.h>
#include <stdbool.h>

double ft_atof(char *str) {
    char	negative;
	double	result;
	double	fraction;
	double	divisor;
	
	negative = 0;
	fraction = 0.0;
	divisor = 0.0;
	
	// skip leading whitespace
	while (ft_isspace(*str)) {
		++str;
	}

    // determine sign
    negative = 0;
    if (*str == '-') {
        negative = 1;
        ++str;
    } else if (*str == '+') {
        ++str;
    }

    // parse integer part of number
    result = 0.0;
    while (isdigit(*str)) {
        result = result * 10.0 + (*str - '0');
        ++str;
    }

    // parse decimal part of number
    if (*str == '.') {
        fraction = 0.0;
        divisor = 1.0;
        ++str;
        while (isdigit(*str)) {
            fraction = fraction * 10.0 + (*str - '0');
            divisor *= 10.0;
            ++str;
        }
        result += fraction / divisor;
    }

    // return result with correct sign
    return negative ? -result : result;
}

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' ||
	    c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

void	move(t_data *data, double dist, char dir)
{
	double	center_r;
	double	center_i;

	center_r = data->xmax - data->xmin;
	center_i = data->ymax - data->ymin;
	if (dir == 'R')
	{
		data->xmin += center_r * dist;
		data->xmax += center_r * dist;
	}
	else if (dir == 'L')
	{
		data->xmin -= center_r * dist;
		data->xmax -= center_r * dist;
	}
	else if (dir == 'D')
	{
		data->ymin -= center_i * dist;
		data->ymax -= center_i * dist;
	}
	else if (dir == 'U')
	{
		data->ymin += center_i * dist;
		data->ymax += center_i * dist;
	}
}