/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 20:10:17 by aroi              #+#    #+#             */
/*   Updated: 2018/08/03 21:17:42 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			error(char *str)
{
	ft_printf("{red}%s{eoc}\n", str);
	return (1);
}

t_img		new_img(t_fractol *fractol)
{
	t_img		img;

	img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size, &img.endian);
	img.bpp /= 8;
	return (img);
}

void		usage(void)
{
	ft_printf("       {red}Usage:{eoc}\n./fractol mandelbrot\n");
	ft_printf("./fractol julia\n./fractol mandelbar\n./fractol heartbrot\n");
	ft_printf("./fractol dualbrot\n./fractol \"great axe\"\n./fractol pentabrot\n");
	ft_printf("./fractol eggs\n./fractol \"burning ship\"\n./fractol \"penta burn\"\n");
	ft_printf("./fractol heartjulia\n./fractol pentajulia\n");
	ft_printf("\nYou should write {red}one{eoc}, {red}two{eoc} or {red}three{eoc} parametrs, but no more and no less!\n");
	exit(1);
}

int		set_penta_burn(t_fractol *fractol, int i, int j)
{
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while(++iterations < fractol->depth)
    {
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = fabs(temp_re) * (temp_re * temp_re * temp_re * temp_re - 10 * temp_re * temp_re * temp_im * temp_im + 5 * temp_im * temp_im * temp_im * temp_im) +
			fractol->complex.c_re;
		fractol->complex.z_im =  fabs(temp_im) * (5 * temp_re * temp_re * temp_re * temp_re - 10 * temp_im * temp_im * temp_re * temp_re + temp_im * temp_im * temp_im * temp_im) + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return (iterations);
}

int		set_pentabrot(t_fractol *fractol, int i, int j)
{
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while(++iterations < fractol->depth)
    {
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * (temp_re * temp_re * temp_re * temp_re - 10 * temp_re * temp_re * temp_im * temp_im + 5 * temp_im * temp_im * temp_im * temp_im) +
			fractol->complex.c_re;
		fractol->complex.z_im =  temp_im * (5 * temp_re * temp_re * temp_re * temp_re - 10 * temp_im * temp_im * temp_re * temp_re + temp_im * temp_im * temp_im * temp_im) + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return (iterations);
}

int		set_greataxe(t_fractol *fractol, int i, int j)
{
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while(++iterations < fractol->depth)
    {
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = (temp_re * temp_re - 3 * temp_im * temp_im) * fabs(temp_re) +
			fractol->complex.c_re;
		fractol->complex.z_im =  (3 * temp_re * temp_re - temp_im * temp_im) * fabs(temp_im) + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return (iterations);
}

int		set_duobrot(t_fractol *fractol, int i, int j)
{
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while(++iterations < fractol->depth)
    {
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re * temp_re - 3 * temp_re * temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im =  3 * temp_re * temp_re * temp_im - temp_im * temp_im * temp_im + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return (iterations);
}

int		set_heart(t_fractol *fractol, int i, int j)
{
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while(++iterations < fractol->depth)
    {
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im -
			fractol->complex.c_re;
		fractol->complex.z_im =  2 * fabs(temp_re) * temp_im + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return (iterations);
}

int		set_eggs(t_fractol *fractol, int i, int j)
{
	
	double temp_re;
	double temp_im;
	int iterations;
	
	fractol->complex.z_re = 2;
	fractol->complex.z_im = 0;
	iterations = -1;
	while(++iterations < fractol->depth)
    {
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im =  2 * fabs(temp_re * temp_im) + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return (iterations);
}

int		set_burning_ship(t_fractol *fractol, int i, int j)
{
	
	double temp_re;
	double temp_im;
	int iterations;
	
	// fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex - 1.765;
    // fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey - 0.03;
	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
    {
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im =  2 * fabs(temp_re * temp_im) + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return (iterations);
}

int		set_mandelbar(t_fractol *fractol, int i, int j)
{
	
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
    {
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im =  -2 * temp_re * temp_im + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return (iterations);
}

int		set_pentajulia(t_fractol *fractol, int i, int j)
{
	int iterations;
	double	temp_re;
	double	temp_im;


	fractol->complex.z_re = fractol->complex.c_re;
	fractol->complex.z_im = fractol->complex.c_im;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * (temp_re * temp_re * temp_re * temp_re - 10 * temp_re * temp_re * temp_im * temp_im + 5 * temp_im * temp_im * temp_im * temp_im) +
		(double)fractol->jmousex;
		fractol->complex.z_im =  temp_im * (5 * temp_re * temp_re * temp_re * temp_re - 10 * temp_im * temp_im * temp_re * temp_re + temp_im * temp_im * temp_im * temp_im) + (double)fractol->jmousex;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return(iterations);
}

int		set_julia(t_fractol *fractol, int i, int j)
{
	int iterations;
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
		fractol->complex.z_im =  2 * temp_re * temp_im + (double)fractol->jmousey;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return(iterations);
}

//black_n_white

int			rgb_b(int iter, t_fractol *fractol)
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

int			rgb_r(int iter, t_fractol *fractol)
{
	int red;
	int green;
	int blue;

	if (iter == fractol->depth)
		return (0);
	red = (double)iter/fractol->depth * 255;
	green = 0;
	blue = 0;
	return ((red << 16) | (green << 8) | blue);
}

int			rgb_bin(int iter, t_fractol *fractol)
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

//hujna

int			rgb_log(int iter, t_fractol *fractol)
{
	int red;
	int green;
	int blue;

	if (iter == fractol->depth)
		return (0);
	red = (150 * log(fabs(fractol->complex.z_re + fractol->complex.z_im)));
	green = (250 * log(fabs(fractol->complex.z_re + fractol->complex.z_im)));
	blue =  (200 * log(fabs(fractol->complex.z_re + fractol->complex.z_im)));
	return ((red << 16) | (green << 8) | blue);
}

//colorful

int			rgb_color(int iter, t_fractol *fractol)
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

int		set_heartjulia(t_fractol *fractol, int i, int j)
{
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.z_re = fractol->complex.c_re;
	fractol->complex.z_im = fractol->complex.c_im;
	iterations = -1;
	while (++iterations < fractol->depth)
    {
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->jmousex;
		fractol->complex.z_im =  2 * fabs(temp_re) * temp_im + fractol->jmousey;
	}
	return (iterations);
}
int		set_mandelbrot(t_fractol *fractol, int i, int j)
{
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
    {
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im =  2 * temp_re * temp_im + fractol->complex.c_im;
	}
	return (iterations);
}

void		choose_color(int *color, int iterations, t_fractol* fractol)
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
}

void		lets_paint(t_fractol *fractol)
{
	int i;
	int j;
	int iterations;

	j = fractol->counter;
	// while (j < HEIGHT)
	while (j < HEIGHT / THREAD_QNT + fractol->counter)
	{
		i = 0;
		while (i < WIDTH)
		{
			fractol->complex.c_re = fractol->complex.min_re + i * fractol->complex.re_factor;
			fractol->complex.c_im = fractol->complex.min_im - (HEIGHT - j) * fractol->complex.im_factor;
			if (ft_strequ(fractol->name, "mandelbrot"))
				iterations = set_mandelbrot(fractol, i, j);
			else if (ft_strequ(fractol->name, "julia"))
				iterations = set_julia(fractol, i, j);
			else if (ft_strequ(fractol->name, "mandelbar"))
				iterations = set_mandelbar(fractol, i, j);
			else if (ft_strequ(fractol->name, "heartbrot"))
				iterations = set_heart(fractol, i, j);
			else if (ft_strequ(fractol->name, "dualbrot"))
				iterations = set_duobrot(fractol, i, j);
			else if (ft_strequ(fractol->name, "great axe"))
				iterations = set_greataxe(fractol, i, j);
			else if (ft_strequ(fractol->name, "pentabrot"))
				iterations = set_pentabrot(fractol, i, j);
			else if (ft_strequ(fractol->name, "eggs"))
				iterations = set_eggs(fractol, i, j);
			else if (ft_strequ(fractol->name, "burning ship"))
				iterations = set_burning_ship(fractol, i, j);
			else if (ft_strequ(fractol->name, "penta burn"))
				iterations = set_penta_burn(fractol, i, j);
			else if (ft_strequ(fractol->name, "pentajulia"))
				iterations = set_pentajulia(fractol, i, j);
			else if (ft_strequ(fractol->name, "heartjulia"))
				iterations = set_heartjulia(fractol, i, j);
			if (i >= 0 && i < WIDTH && j >= 0 && j < HEIGHT)
				choose_color((int *)(fractol->img.addr + i * fractol->img.bpp + j * fractol->img.size), iterations, fractol);
			i++;
		}
		j++;
	}
}

void	initialize_threads(t_fractol *fractol)
{
	int i;
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
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

t_fractol	*new_fractol(char *str)
{
	t_fractol *fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		return (0);
	ft_capitalize(str);
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, str);
	fractol->img = new_img(fractol);
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

int		ft_exit(void)
{
	exit(0);
}

void		reset(t_fractol *fractol)
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

int	key_mapping(int key, t_fractol *fractol)
{
	if (key == MACOS_ESC)
		ft_exit();
	else if (key == MACOS_W)
		fractol->complex.min_im += 0.05 * fractol->complex.delta;
	else if (key == MACOS_S)
		fractol->complex.min_im -= 0.05 * fractol->complex.delta;
	else if (key == MACOS_A)
		fractol->complex.min_re -= 0.05 * fractol->complex.delta;
	else if (key == MACOS_D)
		fractol->complex.min_re += 0.05 * fractol->complex.delta;
	else if (key == MACOS_SPACE)
		fractol->mouseon *= -1;
	else if (key == MACOS_BACKSPACE)
		reset(fractol);
	else if (key == MACOS_Z)
		fractol->color = 0;
	else if (key == MACOS_X)
		fractol->color = 1;
	else if (key == MACOS_C)
		fractol->color = 2;
	else if (key == MACOS_V)
		fractol->color = 3;
	else if (key == MACOS_B)
		fractol->color = 4;
	else if (key == MACOS_N)
		fractol->color = 5;
	mlx_clear_window(fractol->mlx, fractol->win);
	ft_bzero((void *)fractol->img.addr, fractol->img.size * HEIGHT);
	initialize_threads(fractol);
	return (0);
}

int			mouse_controls(int mousebutton, int x, int y, t_fractol *fractol)
{
	double k;
	
	if (mousebutton == SCROLL_DOWN || mousebutton == SCROLL_UP)
	{
		if (mousebutton == SCROLL_DOWN)
		{
			k = (double)10 / 9;
			fractol->complex.delta *= k;
			if (fractol->depth > 20)
				fractol->depth -= 3;
		}
		else if (mousebutton == SCROLL_UP)
		{
			k = (double)9 / 10;
			fractol->complex.delta *= k;
			fractol->depth += 3;
		}
		fractol->complex.min_re = fractol->complex.min_re + ((double)x / WIDTH) * fractol->complex.delta / k * (1 - k);
		fractol->complex.min_im = fractol->complex.min_im - ((double)(HEIGHT - y) / HEIGHT) * fractol->complex.delta / k * (1 - k);
	}
	mlx_clear_window(fractol->mlx, fractol->win);
	ft_bzero((void *)fractol->img.addr, fractol->img.size * HEIGHT);
	initialize_threads(fractol);
	return (0);
}

int			move_with_mouse(int x, int y, t_fractol *fractol)
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

void		init_window(char *str)
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

int			is_right_name(char *str)
{
	if (!ft_strequ(str, "julia") && !ft_strequ(str, "mandelbrot") &&
		!ft_strequ(str, "mandelbar") && !ft_strequ(str, "heartbrot") &&
		!ft_strequ(str, "dualbrot") && !ft_strequ(str, "great axe") &&
		!ft_strequ(str, "pentabrot") && !ft_strequ(str, "eggs") &&
		!ft_strequ(str, "burning ship") && !ft_strequ(str, "penta burn") &&
		!ft_strequ(str, "pentajulia") && !ft_strequ(str, "heartjulia"))
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	int			i;
	pid_t		id[2];
	int k;

	i = 0;
	k = 0;
	id[0] = 55;
	id[1] = 56;
	if (argc == 1 || argc > 4)
		usage();
	if (argc > 2)
		id[0] = fork();
	if (id[0] > 0)
	{
		if ((!is_right_name(argv[1]) || !is_right_name(argv[2])) && !is_right_name(argv[3]))
			wait(0);
		if (!is_right_name(argv[1]))
			usage();
		init_window(argv[1]);
	}
	else
	{
		if (argc > 3)
			id[1] = fork();
		if (id[1] > 0)
		{
			if (!is_right_name(argv[2]) || !is_right_name(argv[3]))
				wait(0);
			if (!is_right_name(argv[2]))
				usage();
			init_window(argv[2]);
		}
		else
		{
			if (!is_right_name(argv[3]))
				usage();
			init_window(argv[3]);
		}
	}
	return (0);
}
