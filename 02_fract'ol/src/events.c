/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:50:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/05 20:35:54 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	handle_key(int keycode, t_data *data)
{
	double	pan_amount;

	pan_amount = 0.1 / data->zoom;
	if (keycode == KEY_ESC)
		clean_exit(data);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		data->x_offset -= pan_amount;
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		data->x_offset += pan_amount;
	else if (keycode == KEY_UP || keycode == KEY_W)
		data->y_offset -= pan_amount;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		data->y_offset += pan_amount;
	render_fractal(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	t_complex	before;
	t_complex	after;

	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		before = screen_to_complex(x, y, data);
		if (button == MOUSE_SCROLL_UP)
			data->zoom = data->zoom * ZOOM_FACTOR;
		else if (button == MOUSE_SCROLL_DOWN)
			data->zoom = data->zoom / ZOOM_FACTOR;
		after = screen_to_complex(x, y, data);
		data->x_offset += before.real - after.real;
		data->y_offset += before.imag - after.imag;
		render_fractal(data);
	}
	return (0);
}

int	handle_close(t_data *data)
{
	clean_exit(data);
	return (0);
}

// Puts a single colour pixel into image
void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	if (!data->addr || x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
	{
		ft_printf("Error pixel coordinates/null\n", 0);
		return ;
	}
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

// add colour to represent differnt speed at which the "point" escapes
// black is stable(that is number gets smaller), dont escape, haha,black hole
int	get_colour(int iterations, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iterations == max_iter)
		return (0x000000);
	t = (double)iterations / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}
