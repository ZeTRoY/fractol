/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:54:40 by aroi              #+#    #+#             */
/*   Updated: 2018/08/04 10:04:49 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			set_julia(t_fractol *fractol, int i, int j)
{
	int		iterations;
	double	temp_re;
	double	temp_im;

	fractol->complex.z_re = fractol->complex.c_re;
	fractol->complex.z_im = fractol->complex.c_im;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
		(double)fractol->jmousex;
		fractol->complex.z_im = 2 * temp_re * temp_im +
			(double)fractol->jmousey;
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}

int			set_heartjulia(t_fractol *fractol, int i, int j)
{
	double	temp_re;
	double	temp_im;
	int		iterations;

	fractol->complex.z_re = fractol->complex.c_re;
	fractol->complex.z_im = fractol->complex.c_im;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->jmousex;
		fractol->complex.z_im = 2 * fabs(temp_re) * temp_im + fractol->jmousey;
	}
	return (iterations);
}

int			set_pentajulia(t_fractol *fractol, int i, int j)
{
	int		iterations;
	double	temp_re;
	double	temp_im;

	fractol->complex.z_re = fractol->complex.c_re;
	fractol->complex.z_im = fractol->complex.c_im;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * (temp_re * temp_re * temp_re *
			temp_re - 10 * temp_re * temp_re * temp_im * temp_im + 5 *
			temp_im * temp_im * temp_im * temp_im) + (double)fractol->jmousex;
		fractol->complex.z_im = temp_im * (5 * temp_re * temp_re * temp_re *
			temp_re - 10 * temp_im * temp_im * temp_re * temp_re + temp_im *
			temp_im * temp_im * temp_im) + (double)fractol->jmousex;
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}

int			set_heart(t_fractol *fractol, int i, int j)
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
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im -
			fractol->complex.c_re;
		fractol->complex.z_im = 2 * fabs(temp_re) * temp_im +
			fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}

int			set_eggs(t_fractol *fractol, int i, int j)
{
	double	temp_re;
	double	temp_im;
	int		iterations;

	fractol->complex.z_re = 2;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im = 2 * fabs(temp_re * temp_im) +
			fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}
