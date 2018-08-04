/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:36:30 by aroi              #+#    #+#             */
/*   Updated: 2018/08/04 14:56:24 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		choose_a_fractal(t_fractol *fractol, int i, int j)
{
	if (fractol->fractal_number == 1)
		return (set_mandelbrot(fractol, i, j));
	else if (fractol->fractal_number == 2)
		return (set_julia(fractol, i, j));
	else if (fractol->fractal_number == 3)
		return (set_mandelbar(fractol, i, j));
	else if (fractol->fractal_number == 4)
		return (set_heart(fractol, i, j));
	else if (fractol->fractal_number == 5)
		return (set_dualbrot(fractol, i, j));
	else if (fractol->fractal_number == 6)
		return (set_greataxe(fractol, i, j));
	else if (fractol->fractal_number == 7)
		return (set_pentabrot(fractol, i, j));
	else if (fractol->fractal_number == 8)
		return (set_eggs(fractol, i, j));
	else if (fractol->fractal_number == 9)
		return (set_burning_ship(fractol, i, j));
	else if (fractol->fractal_number == 10)
		return (set_penta_burn(fractol, i, j));
	else if (fractol->fractal_number == 11)
		return (set_heartjulia(fractol, i, j));
	else if (fractol->fractal_number == 12)
		return (set_pentajulia(fractol, i, j));
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
	if (fractol->info > 0)
		draw_info_table(fractol);
	mlx_string_put(fractol->mlx, fractol->win, 10, 10, 0xFF0000,
		"Max iterations: ");
	mlx_string_put(fractol->mlx, fractol->win, 165, 10, 0xFF0000,
		ft_itoa(fractol->depth));
}
