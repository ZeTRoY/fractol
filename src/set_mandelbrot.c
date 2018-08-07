/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:45:52 by aroi              #+#    #+#             */
/*   Updated: 2018/08/07 10:04:49 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_mandelbrot(t_fractol *fractol)
{
	double	temp_re;
	double	temp_im;
	int		iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im = 2 * temp_re * temp_im + fractol->complex.c_im;
	}
	return (iterations);
}

int		set_dualbrot(t_fractol *fractol)
{
	double	temp_re;
	double	temp_im;
	int		iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re * temp_re - 3 * temp_re *
			temp_im * temp_im + fractol->complex.c_re;
		fractol->complex.z_im = 3 * temp_re * temp_re * temp_im - temp_im *
			temp_im * temp_im + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}

int		set_mandelbar(t_fractol *fractol)
{
	double	temp_re;
	double	temp_im;
	int		iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im = -2 * temp_re * temp_im + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re +
			fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}

int		set_pentabrot(t_fractol *fractol)
{
	double	temp_re;
	double	temp_im;
	int		iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * (temp_re * temp_re * temp_re * temp_re
			- 10 * temp_re * temp_re * temp_im * temp_im + 5 * temp_im * temp_im
			* temp_im * temp_im) + fractol->complex.c_re;
		fractol->complex.z_im = temp_im * (5 * temp_re * temp_re * temp_re *
			temp_re - 10 * temp_im * temp_im * temp_re * temp_re + temp_im *
			temp_im * temp_im * temp_im) + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}

int		set_greataxe(t_fractol *fractol)
{
	double	temp_re;
	double	temp_im;
	int		iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = (temp_re * temp_re - 3 * temp_im * temp_im) *
		fabs(temp_re) + fractol->complex.c_re;
		fractol->complex.z_im = (3 * temp_re * temp_re - temp_im * temp_im) *
			fabs(temp_im) + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}
