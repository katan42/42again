/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_newton_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ka-tan <ka-tan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:50:42 by ka-tan            #+#    #+#             */
/*   Updated: 2025/12/05 14:16:18 by ka-tan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol_bonus.h"

// denominator = |b|² = b.real² + b.imag²
// real part = (a_real * b_real + a_imag * b_imag) / |b|²
// imag part = (a_imag * b_real - a_real * b_imag) / |b|²
// z(next) = z – (z³ – 1)/(3z²)
t_complex	complex_divide(t_complex a, t_complex b)
{
	t_complex	res;
	double		deno;

	deno = b.real * b.real + b.imag * b.imag;
	res.real = (a.real * b.real + a.imag * b.imag) / deno;
	res.imag = (a.imag * b.real - a.real * b.imag) / deno;
	return (res);
}

//z(next) = z – (f(z) / f’(z))
//f(z) = z³ – 1
//f’(z) = 3z²
t_complex	newton_step(t_complex z)
{
	t_complex	z2;
	t_complex	z3;
	t_complex	numer;
	t_complex	deno;
	t_complex	step;

	z2 = complex_multiply(z, z);
	z3 = complex_multiply(z2, z);
	numer.real = z3.real - 1;
	numer.imag = z3.imag;
	deno.real = 3 * z2.real;
	deno.imag = 3 * z2.imag;
	step = complex_divide(numer, deno);
	z.real = z.real - step.real;
	z.imag = z.imag - step.imag;
	return (z);
}

// the equation has 3 roots(solution)
// convergence to each root will be one unique col
int	get_newton_iterations(t_complex z)
{
	int	iter;

	iter = 0;
	while (iter < MAX_ITER)
	{
		if (fabs(z.real -1) < 0.0005 && fabs(z.imag) < 0.0005)
			return ((1 << 24) | iter);
		if (fabs(z.real + 0.5) < 0.0005 && fabs(z.imag - 0.866025) < 0.0005)
			return ((2 << 24) | iter);
		if (fabs(z.real + 0.5) < 0.0005 && fabs(z.imag + 0.866025) < 0.0005)
			return ((3 << 24) | iter);
		z = newton_step(z);
		iter++;
	}
	return (0);
}

int	calculate_newton(t_data *data, int x, int y)
{
	t_complex	z;

	z = screen_to_complex(x, y, data);
	return (get_newton_iterations(z));
}

int	get_colour_newton(t_data *data, int raw, int max_iter)
{
	int	root;
	int	iterations;
	int	base;

	root = (raw >> 24) & 0xFF;
	iterations = raw & 0xFF;
	if (root == 0)
		return (0x000000);
	base = get_colour(data, iterations, max_iter);
	if (root == 1)
		return (base);
	if (root == 2)
		return ((base >> 1) & 0x7F7F7F);
	return ((base << 1) | 0x101010);
}
