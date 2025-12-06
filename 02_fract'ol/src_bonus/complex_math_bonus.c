/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_math_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:50:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/05 21:02:24 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

// complex number operations
t_complex	complex_new(double real, double imag)
{
	t_complex	c;

	c.real = real;
	c.imag = imag;
	return (c);
}

t_complex	complex_multiply(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real * b.real - a.imag * b.imag;
	result.imag = a.real * b.imag + a.imag * b.real;
	return (result);
}

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

double	complex_mag_squared(t_complex c)
{
	return (c.real * c.real + c.imag * c.imag);
}

// range of 2 to -2 jf any iteration of a point ever gets farther than 2 units
// away from the origin (0,0), that point will definitely escape to infinity
// and thus isn't in the Mandelbrot set.
// julia is slightly different but will fit into the range too centres x
// to match the screen coordinates with the complex plane (0,0 in the centre)
t_complex	screen_to_complex(int x, int y, t_data *data)
{
	t_complex	c;

	c.real = (x - WIDTH / 2.0) / (data->zoom * WIDTH / 4.0) + data->x_offset;
	c.imag = - (y - HEIGHT / 2.0) / (data->zoom * HEIGHT / 4.0) + data->y_offset;
	return (c);
}
