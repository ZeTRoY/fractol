/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:31:18 by aroi              #+#    #+#             */
/*   Updated: 2018/08/04 15:30:29 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					ft_exit(void)
{
	exit(0);
}

static t_img		new_img(void *mlx)
{
	t_img		img;

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size, &img.endian);
	img.bpp /= 8;
	return (img);
}

int					what_fractal_is(char *str)
{
	if (ft_strequ(str, "mandelbrot"))
		return (1);
	else if (ft_strequ(str, "julia"))
		return (2);
	else if (ft_strequ(str, "mandelbar"))
		return (3);
	else if (ft_strequ(str, "heartbrot"))
		return (4);
	else if (ft_strequ(str, "dualbrot"))
		return (5);
	else if (ft_strequ(str, "great axe"))
		return (6);
	else if (ft_strequ(str, "pentabrot"))
		return (7);
	else if (ft_strequ(str, "eggs"))
		return (8);
	else if (ft_strequ(str, "burning ship"))
		return (9);
	else if (ft_strequ(str, "pentaburn"))
		return (10);
	else if (ft_strequ(str, "heartjulia"))
		return (11);
	else if (ft_strequ(str, "pentajulia"))
		return (12);
	return (-1);
}

static t_fractol	*new_fractol(char *str)
{
	t_fractol *fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (0);
	ft_capitalize(str);
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, str);
	fractol->img = new_img(fractol->mlx);
	ft_lower(str);
	fractol->complex.delta = 3;
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
	fractol->info = 1;
	fractol->fractal_number = what_fractal_is(str);
	fractol->name = str;
	return (fractol);
}

void				init_window(char *str)
{
	t_fractol	*fractol;

	fractol = new_fractol(str);
	ft_printf("\n...initializing {yellow}%s{eoc}...\n", str);
	initialize_threads(fractol);
	mlx_hook(fractol->win, 2, 0, key_mapping, fractol);
	mlx_hook(fractol->win, 17, 0, ft_exit, (void *)0);
	mlx_hook(fractol->win, 6, 5, move_with_mouse, fractol);
	mlx_mouse_hook(fractol->win, mouse_controls, fractol);
	mlx_loop(fractol->mlx);
}
