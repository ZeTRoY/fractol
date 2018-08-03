/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:31:18 by aroi              #+#    #+#             */
/*   Updated: 2018/08/03 23:16:50 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_exit(void)
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
	fractol->name = str;
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
	return (fractol);
}

void				init_window(char *str)
{
	t_fractol	*fractol;

	fractol = new_fractol(str);
	ft_printf("\n...initializing {yellow}%s{eoc}...\n", fractol->name);
	initialize_threads(fractol);
	mlx_hook(fractol->win, 2, 0, key_mapping, fractol);
	mlx_hook(fractol->win, 17, 0, ft_exit, (void *)0);
	mlx_hook(fractol->win, 6, 5, move_with_mouse, fractol);
	mlx_mouse_hook(fractol->win, mouse_controls, fractol);
	mlx_loop(fractol->mlx);
}
