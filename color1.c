/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:42:08 by aroi              #+#    #+#             */
/*   Updated: 2018/08/03 23:08:58 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		rgb_b(int iter, t_fractol *fractol)
{
	int red;
	int green;
	int blue;

	if (iter == fractol->depth)
		return (0);
	red = 255;
	green = 255;
	blue = 255;
	return ((red << 16) | (green << 8) | blue);
}

static int		rgb_bin(int iter, t_fractol *fractol)
{
	int red;
	int green;
	int blue;

	if (iter == fractol->depth || fractol->complex.z_im > 0)
		return (0);
	red = 255;
	green = 255;
	blue = 255;
	return ((red << 16) | (green << 8) | blue);
}

static int		rgb_color(int iter, t_fractol *fractol)
{
	int red;
	int green;
	int blue;

	if (iter == fractol->depth)
		return (0);
	red = 127.5 * (cos((double)iter) + 1);
	green = 127.5 * (sin((double)iter) + 1);
	blue = 127.5 * (1 - cos((double)iter));
	return ((red << 16) | (green << 8) | blue);
}

static int		rgb_r(int iter, t_fractol *fractol)
{
	int red;
	int green;
	int blue;

	if (iter == fractol->depth)
		return (0);
	red = (double)iter / fractol->depth * 255;
	green = 0;
	blue = 0;
	return ((red << 16) | (green << 8) | blue);
}

void			choose_color(int *color, int iterations, t_fractol *fractol)
{
	if (fractol->color == 0)
		*color = rgb_b(iterations, fractol);
	if (fractol->color == 1)
		*color = rgb_bin(iterations, fractol);
	if (fractol->color == 2)
		*color = rgb_r(iterations, fractol);
	if (fractol->color == 3)
		*color = rgb_color(iterations, fractol);
	if (fractol->color == 4)
		*color = rgb_log(iterations, fractol);
	else if (fractol->color == 5)
		*color = rgb_log2(iterations, fractol);
}
