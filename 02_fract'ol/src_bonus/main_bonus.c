/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:50:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/05 14:47:43 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

void	print_instructions(void)
{
	ft_printf("Usage should be:\n");
	ft_printf("either: ./fractol_bonus mandelbrot \n or: ");
	ft_printf("./fractol_bonus julia <real> <imaginary> \n\n");
	ft_printf("For eg.\n ./fractol_bonus mandelbrot \n");
	ft_printf("./fractol_bonus julia -0.4 0.6\n");
	ft_printf("For bonus\n ./fractol_bonus newton\n");
}

int	is_valid_double(char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] != '\0')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		has_digit = 1;
		i++;
	}
	return (has_digit);
}

// checks if type of fractals and if parameters keyed in is correct
int	parse_args(t_data *data, int argc, char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 11) && argc == 2)
	{
		data->fractol_type = MANDELBROT;
		return (1);
	}
	if (!ft_strncmp(argv[1], "julia", 6) && argc == 4)
	{
		if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
			return (ft_printf("Error: Parameters must be valid numbers\n"), 0);
		data->fractol_type = JULIA;
		data->c.real = ft_atof(argv[2]);
		data->c.imag = ft_atof(argv[3]);
		if (fabs(data->c.real) > 2 || fabs(data->c.imag) > 2)
			return (ft_printf("Error: Parameters must be between -2 & 2\n"), 0);
		return (1);
	}
	if (!ft_strncmp(argv[1], "newton", 7) && argc == 2)
	{
		data->fractol_type = NEWTON;
		return (1);
	}
	return (0);
}

// sets up hooks, that is start "looking out" for the various input
void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_key, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, handle_mouse, data);
	mlx_hook(data->win, DestroyNotify, 0, handle_close, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 4)
		return (print_instructions(), 1);
	init_default_values(&data);
	if (!parse_args(&data, argc, argv))
		return (print_instructions(), 1);
	if (!init_mlx(&data))
	{
		ft_printf("Error\n");
		return (1);
	}
	setup_hooks(&data);
	render_fractal(&data);
	mlx_loop(data.mlx);
	return (0);
}
