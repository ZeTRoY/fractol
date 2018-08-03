/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:43:52 by aroi              #+#    #+#             */
/*   Updated: 2018/08/03 23:01:57 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			rgb_log(int iter, t_fractol *fractol)
{
	int red;
	int green;
	int blue;

	if (iter == fractol->depth)
		return (0);
	red = 150 * log(fabs(fractol->complex.z_re + fractol->complex.z_im));
	green = 250 * log(fabs(fractol->complex.z_re + fractol->complex.z_im));
	blue = 200 * log(fabs(fractol->complex.z_re + fractol->complex.z_im));
	return ((red << 16) | (green << 8) | blue);
}

int			rgb_log2(int iter, t_fractol *fractol)
{
	int red;
	int green;
	int blue;

	if (iter == fractol->depth)
		return (0);
	red = iter - log(log(sqrt(fractol->complex.z_re * fractol->complex.z_re +
		fractol->complex.z_im * fractol->complex.z_im)) / log(256)) / log(2.0);
	green = 0;
	blue = 0;
	return ((red << 16) | (green << 8) | blue);
}
