/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   too_complex_fractals_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:50:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/05 14:25:24 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

// Calculate how quickly a "point" escapes
// its quite cool we use > 4.0 because its just less painful to due with
// (sq rt (real2+ imag2) > 2)
int	get_iterations(t_complex z, t_complex c)
{
	int	iter;

	iter = 0;
	while (iter < MAX_ITER)
	{
		if (complex_mag_squared(z) > 4.0)
			return (iter);
		z = complex_add(complex_multiply(z, z), c);
		iter++;
	}
	return (MAX_ITER);
}

int	calculate_mandelbrot(t_data *data, int x, int y)
{
	t_complex	z;
	t_complex	c;

	z = complex_new(0.0, 0.0);
	c = screen_to_complex(x, y, data);
	return (get_iterations(z, c));
}

int	calculate_julia(t_data *data, int x, int y)
{
	t_complex	z;

	z = screen_to_complex(x, y, data);
	return (get_iterations(z, data->c));
}

static int	get_pixel_colour(t_data *data, int x, int y)
{
	int	iterations;

	if (data->fractol_type == MANDELBROT)
	{
		iterations = calculate_mandelbrot(data, x, y);
		return (get_colour(data, iterations, MAX_ITER));
	}
	else if (data->fractol_type == JULIA)
	{
		iterations = calculate_julia(data, x, y);
		return (get_colour(data, iterations, MAX_ITER));
	}
	else if (data->fractol_type == NEWTON)
	{
		iterations = calculate_newton(data, x, y);
		return (get_colour_newton(data, iterations, MAX_ITER));
	}
	return (0);
}

// loops through every pixel on the screen to put colour
void	render_fractal(t_data *data)
{
	int	y;
	int	x;
	int	colour;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			colour = get_pixel_colour(data, x, y);
			my_mlx_pixel_put(data, x, y, colour);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
