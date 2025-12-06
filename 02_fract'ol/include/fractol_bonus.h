/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:50:08 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/05 20:33:19 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
//increases the view by 20%, similar to many mouse wheels
# define ZOOM_FACTOR 1.2
# define MIN_ZOOM 0.001
# define MAX_ZOOM 1000

# define MANDELBROT 1
# define JULIA 2
# define NEWTON 3

/* Key codes for Linux/X11 */
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_C		99

/* Mouse button codes */
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	double		x_offset;
	double		y_offset;
	t_complex	c;
	t_complex	z;
	int			fractol_type;
	int			colour_shift;
}	t_data;

//fractals
int			get_iterations(t_complex z, t_complex c);
int			calculate_mandelbrot(t_data *data, int x, int y);
int			calculate_julia(t_data *data, int x, int y);
void		render_fractal(t_data *data);

// complex number operations
t_complex	complex_new(double real, double imag);
t_complex	complex_multiply(t_complex a, t_complex b);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	screen_to_complex(int x, int y, t_data *data);
double		complex_mag_squared(t_complex c);

//events and colouring
int			handle_key(int keycode, t_data *data);
int			handle_mouse(int button, int x, int y, t_data *data);
int			handle_close(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int colour);
int			get_colour(t_data *data, int iterations, int max_iter);

//initialise
void		init_default_values(t_data *data);
int			init_mlx(t_data *data);

//exit
void		clean_exit(t_data *data);

void		print_instructions(void);
int			is_valid_double(char *str);
int			parse_args(t_data *data, int argc, char **argv);
void		setup_hooks(t_data *data);

//utils_ft_atof
const char	*handle_prefix(const char *str, int *sign);
double		process_whole_number(const char **str);
double		process_fraction(const char *str);
double		ft_atof(const char *str);

//additional functions for newton
t_complex	complex_divide(t_complex a, t_complex b);
t_complex	newton_step(t_complex z);
int			get_newton_iterations(t_complex z);
int			calculate_newton(t_data *data, int x, int y);
int			get_colour_newton(t_data *data, int raw, int max_iter);
#endif
