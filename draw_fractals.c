/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:36:30 by aroi              #+#    #+#             */
/*   Updated: 2018/08/03 23:16:10 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		choose_a_fractal(t_fractol *fractol, int i, int j)
{
	if (ft_strequ(fractol->name, "mandelbrot"))
		return (set_mandelbrot(fractol, i, j));
	else if (ft_strequ(fractol->name, "julia"))
		return (set_julia(fractol, i, j));
	else if (ft_strequ(fractol->name, "mandelbar"))
		return (set_mandelbar(fractol, i, j));
	else if (ft_strequ(fractol->name, "heartbrot"))
		return (set_heart(fractol, i, j));
	else if (ft_strequ(fractol->name, "dualbrot"))
		return (set_duobrot(fractol, i, j));
	else if (ft_strequ(fractol->name, "great axe"))
		return (set_greataxe(fractol, i, j));
	else if (ft_strequ(fractol->name, "pentabrot"))
		return (set_pentabrot(fractol, i, j));
	else if (ft_strequ(fractol->name, "eggs"))
		return (set_eggs(fractol, i, j));
	else if (ft_strequ(fractol->name, "burning ship"))
		return (set_burning_ship(fractol, i, j));
	else if (ft_strequ(fractol->name, "penta burn"))
		return (set_penta_burn(fractol, i, j));
	else if (ft_strequ(fractol->name, "pentajulia"))
		return (set_pentajulia(fractol, i, j));
	else if (ft_strequ(fractol->name, "heartjulia"))
		return (set_heartjulia(fractol, i, j));
	return (-1);
}

static void		lets_paint(t_fractol *fractol)
{
	int		i;
	int		j;
	int		iterations;

	j = fractol->counter;
	while (j < HEIGHT / THREAD_QNT + fractol->counter)
	{
		i = 0;
		while (i < WIDTH)
		{
			fractol->complex.c_re = fractol->complex.min_re +
				i * fractol->complex.re_factor;
			fractol->complex.c_im = fractol->complex.min_im -
				(HEIGHT - j) * fractol->complex.im_factor;
			iterations = choose_a_fractal(fractol, i, j);
			if (i >= 0 && i < WIDTH && j >= 0 && j < HEIGHT)
				choose_color((int *)(fractol->img.addr +
					i * fractol->img.bpp + j * fractol->img.size),
						iterations, fractol);
			i++;
		}
		j++;
	}
}

void			initialize_threads(t_fractol *fractol)
{
	int			i;
	pthread_t	tid[THREAD_QNT];
	t_fractol	frac[THREAD_QNT];

	i = -1;
	fractol->complex.re_factor = (fractol->complex.delta) / (WIDTH - 1);
	fractol->complex.im_factor = (fractol->complex.delta) / (HEIGHT - 1);
	while (++i < THREAD_QNT)
	{
		frac[i] = *fractol;
		frac[i].counter = i * HEIGHT / THREAD_QNT;
		pthread_create(&tid[i], NULL, (void *)&lets_paint, (void *)&frac[i]);
	}
	while (--i >= 0)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img, 0, 0);
}
