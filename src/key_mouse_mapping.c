/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse_mapping.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:23:31 by aroi              #+#    #+#             */
/*   Updated: 2018/08/07 10:03:19 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			reset(t_fractol *fractol)
{
	fractol->depth = 60;
	fractol->jmousex = WIDTH / 2;
	fractol->jmousey = HEIGHT / 2;
	fractol->mousex = WIDTH / 2;
	fractol->mousey = HEIGHT / 2;
	fractol->mouseon = -1;
	fractol->complex.min_re = -1.5;
	fractol->complex.min_im = 1.5;
	fractol->complex.delta = 3.0;
	fractol->color = 0;
}

static void		change_color(int key, t_fractol *fractol)
{
	if (key == MACOS_Z)
		fractol->color = 0;
	if (key == MACOS_X)
		fractol->color = 1;
	if (key == MACOS_C)
		fractol->color = 2;
	if (key == MACOS_V)
		fractol->color = 3;
	if (key == MACOS_B)
		fractol->color = 4;
	if (key == MACOS_N)
		fractol->color = 5;
	if (key == MACOS_M)
		fractol->color = 6;
}

int				key_mapping(int key, t_fractol *fractol)
{
	if (key == MACOS_ESC)
		exit(0);
	else if (key == MACOS_W)
		fractol->complex.min_im += 0.05 * fractol->complex.delta;
	else if (key == MACOS_S)
		fractol->complex.min_im -= 0.05 * fractol->complex.delta;
	else if (key == MACOS_A)
		fractol->complex.min_re += 0.05 * fractol->complex.delta;
	else if (key == MACOS_D)
		fractol->complex.min_re -= 0.05 * fractol->complex.delta;
	key_mapping_2(key, fractol);
	change_color(key, fractol);
	mlx_clear_window(fractol->mlx, fractol->win);
	ft_bzero((void *)fractol->img.addr, fractol->img.size * HEIGHT);
	initialize_threads(fractol);
	return (0);
}

int				mouse_controls(int mousebutton, int x, int y,
					t_fractol *fractol)
{
	double k;

	if (mousebutton == SCROLL_DOWN || mousebutton == SCROLL_UP)
	{
		if (mousebutton == SCROLL_DOWN)
		{
			k = (double)10 / 9;
			if (fractol->depth > 20)
				fractol->depth -= 3;
		}
		else
		{
			k = (double)9 / 10;
			fractol->depth += 3;
		}
		fractol->complex.delta *= k;
		fractol->complex.min_re = fractol->complex.min_re +
			((double)x / WIDTH) * fractol->complex.delta / k * (1 - k);
		fractol->complex.min_im = fractol->complex.min_im - ((double)(HEIGHT -
			y) / HEIGHT) * fractol->complex.delta / k * (1 - k);
	}
	mlx_clear_window(fractol->mlx, fractol->win);
	ft_bzero((void *)fractol->img.addr, fractol->img.size * HEIGHT);
	initialize_threads(fractol);
	return (0);
}

int				move_with_mouse(int x, int y, t_fractol *fractol)
{
	if (ft_strstr(fractol->name, "julia") && fractol->mouseon != -1)
	{
		fractol->jmousex = (double)x / WIDTH;
		fractol->jmousey = (double)y / HEIGHT;
		mlx_clear_window(fractol->mlx, fractol->win);
		ft_bzero((void *)fractol->img.addr, fractol->img.size * HEIGHT);
		initialize_threads(fractol);
	}
	return (1);
}
