/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:12:36 by aroi              #+#    #+#             */
/*   Updated: 2018/08/04 13:26:17 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		change_name(t_fractol *fractol)
{
	if (fractol->fractal_number == 1)
		fractol->name = "mandelbrot";
	if (fractol->fractal_number == 2)
		fractol->name = "julia";
	if (fractol->fractal_number == 3)
		fractol->name = "mandelbar";
	if (fractol->fractal_number == 4)
		fractol->name = "heartbrot";
	if (fractol->fractal_number == 5)
		fractol->name = "dualbrot";
	if (fractol->fractal_number == 6)
		fractol->name = "great axe";
	if (fractol->fractal_number == 7)
		fractol->name = "pentabrot";
	if (fractol->fractal_number == 8)
		fractol->name = "eggs";
	if (fractol->fractal_number == 9)
		fractol->name = "burning ship";
	if (fractol->fractal_number == 10)
		fractol->name = "pentaburn";
	if (fractol->fractal_number == 11)
		fractol->name = "heartjulia";
	if (fractol->fractal_number == 12)
		fractol->name = "pentajulia";
}

static void		change_fractal(int key, t_fractol *fractol)
{
	if (key == MACOS_ONE)
		fractol->fractal_number = 1;
	if (key == MACOS_TWO)
		fractol->fractal_number = 2;
	if (key == MACOS_THREE)
		fractol->fractal_number = 3;
	if (key == MACOS_FOUR)
		fractol->fractal_number = 4;
	if (key == MACOS_FIVE)
		fractol->fractal_number = 5;
	if (key == MACOS_SIX)
		fractol->fractal_number = 6;
	if (key == MACOS_SEVEN)
		fractol->fractal_number = 7;
	if (key == MACOS_EIGHT)
		fractol->fractal_number = 8;
	if (key == MACOS_NINE)
		fractol->fractal_number = 9;
	if (key == MACOS_TEN)
		fractol->fractal_number = 10;
	if (key == MACOS_ONE_PAD)
		fractol->fractal_number = 11;
	if (key == MACOS_TWO_PAD)
		fractol->fractal_number = 12;
	change_name(fractol);
}

void			key_mapping_2(int key, t_fractol *fractol)
{
	if (key == MACOS_SPACE)
		fractol->mouseon *= -1;
	else if (key == MACOS_BACKSPACE)
		reset(fractol);
	else if (key == MACOS_PLUS || key == MACOS_EQ)
		fractol->depth += 5;
	else if ((key == MACOS_MINUS || key == MACOS_MINUS2) && fractol->depth > 20)
		fractol->depth -= 5;
	if (key == MACOS_H)
	{
		if (fractol->info != 3)
			fractol->info++;
		else
			fractol->info = 0;
	}
	change_fractal(key, fractol);
}
