/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:26:50 by aroi              #+#    #+#             */
/*   Updated: 2018/08/04 17:24:34 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		output_key_keys(void *mlx, void *win, int color)
{
	mlx_string_put(mlx, win, WIDTH - 160, 10, color,
		"MOVE : W A S D");
	mlx_string_put(mlx, win, WIDTH - 160, 32, color,
		"ITER : + -");
	mlx_string_put(mlx, win, WIDTH - 250, 54, color,
		"TURN ON JULIA : SPACE");
	mlx_string_put(mlx, win, WIDTH - 170, 76, color,
		"RESET : BACKSPACE");
}

static void		output_colors(void *mlx, void *win, int color)
{
	mlx_string_put(mlx, win, 10, HEIGHT - 190 - 10, color, "COLORS");
	mlx_string_put(mlx, win, 10, HEIGHT - 154 - 10, color, "BLACK'n'WHITE: Z");
	mlx_string_put(mlx, win, 10, HEIGHT - 132 - 10, color, "BIN DECOMP   : X");
	mlx_string_put(mlx, win, 10, HEIGHT - 110 - 10, color, "LIGHT ITER   : C");
	mlx_string_put(mlx, win, 10, HEIGHT - 88 - 10, color, "COLORFUL     : V");
	mlx_string_put(mlx, win, 10, HEIGHT - 66 - 10, color, "PSYCHO       : B");
	mlx_string_put(mlx, win, 10, HEIGHT - 44 - 10, color, "LOGARITHM    : N");
	mlx_string_put(mlx, win, 10, HEIGHT - 22 - 10, color, "LIGHT PURPLE?: M");
}

static void		output_fractals(void *mlx, void *win, int color)
{
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 264 - 10, color,
		"MANDELBROT  : 1");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 242 - 10, color,
		"JULIA       : 2");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 220 - 10, color,
		"MANDELBAR   : 3");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 198 - 10, color,
		"HEARTBROT   : 4");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 176 - 10, color,
		"DUALBROT    : 5");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 154 - 10, color,
		"GREAT AXE   : 6");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 132 - 10, color,
		"PENTABROT   : 7");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 110 - 10, color,
		"EGGS        : 8");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 88 - 10, color,
		"BURNING SHIP: 9");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 66 - 10, color,
		"PENTO BURN  : 0");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 44 - 10, color,
		"HEARTJULIA  : 1(PAD)");
	mlx_string_put(mlx, win, WIDTH - 213, HEIGHT - 22 - 10, color,
		"PENTAJULIA  : 2(PAD)");
}

void			draw_info_table(t_fractol *fractol)
{
	int color;

	color = 0xFF;
	if (fractol->color == 2 || fractol->color == 5)
		color = 0xFF00;
	else if (fractol->color == 4)
		color = 0xFFFF00;
	else if (fractol->color == 3)
		color = 0xFFFFFF;
	if (fractol->info == 1)
		output_key_keys(fractol->mlx, fractol->win, color);
	else if (fractol->info == 2)
		output_colors(fractol->mlx, fractol->win, color);
	else
	{
		mlx_string_put(fractol->mlx, fractol->win, WIDTH - 213,
			HEIGHT - 300 - 10, color, "FRACTALS");
		output_fractals(fractol->mlx, fractol->win, color);
	}
}
