/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 20:10:17 by aroi              #+#    #+#             */
/*   Updated: 2018/08/02 17:38:30 by aroi             ###   ########.fr       */
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
	ft_printf("\nYou should write {red}one{eoc}, {red}two{eoc} or {red}three{eoc} parametrs, but no more and no less!\n");
	exit(1);
}

int		set_penta_burn(t_fractol *fractol, int i, int j)
{
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex;
    fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey;
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

	fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex;
    fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey;
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

	fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex;
    fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey;
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

	fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex;
    fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey;
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

	fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex;
    fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey;
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
	
	fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex;
    fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey;
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
	
	fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex - 1.765;
    fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey - 0.03;
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

	fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex;
    fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey;
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

int		set_julia(t_fractol *fractol, int i, int j)
{
	int iterations;
	double	temp_re;
	double	temp_im;


	// fractol->complex.c_im = 0.27015;
	// fractol->complex.c_re = -0.7;
	fractol->complex.c_re = (double)fractol->mousex / 1000 - 1;
	fractol->complex.c_im = (double)fractol->mousey / 400 - 1;
	fractol->complex.z_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex;
	fractol->complex.z_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im =  2 * temp_re * temp_im + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re + fractol->complex.z_im
			* fractol->complex.z_im) > 4)
			break;
	}
	return(iterations);
}

//black_n_white

int			rgb(int iter, t_fractol *fractol)
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

// int			rgb(int iter, t_fractol *fractol)
// {
// 	int red;
// 	int green;
// 	int blue;

// 	if (iter == fractol->depth || fractol->complex.z_im > 0)
// 		return (0);
// 	red = 255;
// 	green = 255;
// 	blue = 255;
// 	return ((red << 16) | (green << 8) | blue);
// }

//hujna

// int			rgb(int iter, t_fractol *fractol)
// {
// 	int red;
// 	int green;
// 	int blue;

// 	if (iter == fractol->depth)
// 		return (0);
// 	red = (0 * log(fabs(fractol->complex.z_re + fractol->complex.z_im)));
// 	green = (50 * log(fabs(fractol->complex.z_re + fractol->complex.z_im)));
// 	blue =  (50 * log(fabs(fractol->complex.z_re + fractol->complex.z_im)));
// 	return ((red << 16) | (green << 8) | blue);
// }

//colorful

// int			rgb(int iter, t_fractol *fractol)
// {
// 	int red;
// 	int green;
// 	int blue;

// 	if (iter == fractol->depth)
// 		return (0);
// 	red = 127.5 * (cos((double)iter) + 1);
// 	green = 127.5 * (sin((double)iter) + 1);
// 	blue = 127.5 * (1 - cos((double)iter));
// 	return ((red << 16) | (green << 8) | blue);
// }

int		set_mandelbrot(t_fractol *fractol, int i, int j)
{
	double temp_re;
	double temp_im;
	int iterations;

	fractol->complex.c_re = 1.5 * (i - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH) + fractol->movex;
	fractol->complex.c_im = (j - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT) + fractol->movey;
	// fractol->complex.c_re = (i - fractol->centerx) / fractol->zoom - 2.1 + fractol->movex;
	// fractol->complex.c_im = (fractol->centery - j) / fractol->zoom - 1.2 + fractol->movey;
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

void		lets_paint(t_fractol *fractol)
{
	int i;
	int j;
	int iterations;

	j = fractol->counter;
	// while (j < HEIGHT)
	while (j < HEIGHT / 8 + fractol->counter)
	{
		i = 0;
		while (i < WIDTH)
		{
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
			else
				usage();
			if (i >= 0 && i < WIDTH && j >= 0 && j < HEIGHT)
					*(int *)(fractol->img.addr + i * fractol->img.bpp + j * fractol->img.size) = rgb(iterations, fractol);
			i++;
		}
		j++;
	}
}

void	initialize_threads(t_fractol *fractol)
{
	int i;
	pthread_t	tid[8];
	t_fractol	frac[8];

	i = -1;
	fractol->complex.re_factor = (fractol->complex.max_re - fractol->complex.min_re) / (WIDTH - 1);
	fractol->complex.im_factor = (fractol->complex.max_im - fractol->complex.min_im) / (HEIGHT - 1);
	while (++i < 8)
	{
		frac[i] = *fractol;
		frac[i].counter = i * HEIGHT / 8;
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
	if (ft_strequ(fractol->name, "burning ship"))
		fractol->zoom = 20;
	else
		fractol->zoom = 1;
	fractol->movex = 0;
	fractol->movey = 0;
	fractol->depth = 60;
	fractol->mousex = 0;
	fractol->mousey = 0;
	fractol->mouseon = -1;
	fractol->complex.min_re = -2.0;
	fractol->complex.min_im = -1.2;
	fractol->complex.max_re = 1.0;
	fractol->complex.max_re = 1.05;
	fractol->centerx = WIDTH / 2;
	fractol->centery = HEIGHT / 2;
	// fractol->complex.dre = 4.0;
	return (fractol);
}


int		ft_exit(void)
{
	exit(0);
}

int	key_mapping(int key, t_fractol *fractol)
{
	if (key == MACOS_ESC)
		ft_exit();
	else if (key == MACOS_W)
		fractol->movey -= 0.05 / fractol->zoom;
	else if (key == MACOS_S)
		fractol->movey += 0.05 / fractol->zoom;
	else if (key == MACOS_A)
		fractol->movex += 0.05 / fractol->zoom;
	else if (key == MACOS_D)
		fractol->movex -= 0.05 / fractol->zoom;
	else if (key == MACOS_SPACE)
		fractol->mouseon *= -1;
	mlx_clear_window(fractol->mlx, fractol->win);
	ft_bzero((void *)fractol->img.addr, fractol->img.size * HEIGHT);
	initialize_threads(fractol);
	return (0);
}

// void	draw_fractal(t_fractol *fractol)
// {
// 	int		x;
// 	int		y;
// 	t_iter	ret;

// 	fractol->d_zoom_x = fractol->zoom * WIDTH / (2.7);
// 	fractol->d_zoom_y = fractol->zoom * HEIGHT / (2.4);
// 	y = -1;
// 	while (++y < HEIGHT)
// 	{
// 		x = -1;
// 		while (++x < WIDTH)
// 		{
// 			// ret = w.fractalft(x, y, w);
// 			// mlx_pixel_put_img(&w, x, y, w.colorft(ret, w.itermax));
// 		}
// 	}
// }

// void	zoom_to_center(t_fractol *fractol, int x, int y)
// {
// 	fractol->movex += OFFSETX_SHRINK((fractol->centerx - x) / fractol->zoom);
// 	fractol->movey += OFFSETY_SHRINK((fractol->centery - y) / fractol->zoom);
// 	fractol->centerx = x;
// 	fractol->centery = y;
// }

// void	redraw_fractal(t_fractol *fractol)
// {
// 	draw_fractal(fractol);
// 	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
// 	mlx_do_sync(fractol->mlx);
// }


int			mouse_controls(int mousebutton, int x, int y, t_fractol *fractol)
{
	double re;
	double im;
	double k;

	re = (double)x * (fractol->complex.max_re - fractol->complex.min_re) / WIDTH + fractol->complex.min_re;
	im = (double)y * (fractol->complex.max_im - fractol->complex.min_im) / HEIGHT + fractol->complex.min_im;
	if (mousebutton == SCROLL_DOWN || mousebutton == SCROLL_UP)
	{
		if (mousebutton == SCROLL_DOWN)
		{
			k = 0.9;
			fractol->zoom *= k;
			fractol->depth -= 3;
		}
		else if (mousebutton == SCROLL_UP)
		{
			k = 1.1;
			fractol->zoom *= k;
			fractol->depth += 3;
		}
		// fractol->complex.min_re = re - (double)x / WIDTH * fractol->complex.dre;
		// fractol->complex.min_re = im - (double)y / HEIGHT * fractol->complex.dre;
		
		fractol->complex.min_re = fractol->complex.min_re * k + re * (1 - k);
		fractol->complex.max_re = fractol->complex.max_re * k + re * (1 - k);
		fractol->complex.min_im = fractol->complex.min_im * k + im * (1 - k);
		fractol->complex.max_im = fractol->complex.max_im * k + im * (1 - k);
	}
	mlx_clear_window(fractol->mlx, fractol->win);
	ft_bzero((void *)fractol->img.addr, fractol->img.size * HEIGHT);
	initialize_threads(fractol);
	return (0);
}

int			move_with_mouse(int x, int y, t_fractol *fractol)
{
	if (ft_strequ(fractol->name, "julia") && fractol->mouseon != -1)
	{
		fractol->mousex = x;
		fractol->mousey = y;
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
		!ft_strequ(str, "burning ship") && !ft_strequ(str, "penta burn"))
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
		// if (argv[3] && !is_right_name(argv[3]))
		// 	wait(0);
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









// void	init_mlx(int argc, char **argv)
// {
// 	int		i;
// 	t_mlx	*mlx;

// 	i = 0;
// 	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
// 		error("Couldn't create the mlx structure.");
// 	mlx->mlx = mlx_init();
// 	while (++i < )
// }

// void	show_usage(void)
// {
// 	ft_printf("{red}Usage:{eoc}\n./fractol mandelbrot\n");
// 	ft_printf("\t  julia\n");
// 	ft_printf("Maximum quantity of opened windows is 3.\n");
// 	exit(1);
// }

// #include <pthread.h>
// #include <stdio.h>

// int count; /* общие данные для потоков */
// void *potok(void *param); /* потоковая функция */

// int main(int argc, char *argv[])
// {
// 	pthread_t tid1;
// 	pthread_t tid2;
// 	pthread_attr_t attr1;

// 	if (argc != 3)
// 	{
// 	  fprintf(stderr,"usage: progtest <integer value>\n");
// 	  return -1;
// 	}
// 	if (atoi(argv[1]) < 0 || atoi(argv[2]) < 0)
// 	{
// 	  fprintf(stderr,"Аргумент %d не может быть отрицательным числом\n",atoi(argv[1]));
// 	  return -1;
// 	}
//   pthread_attr_init(&attr1);
//   pthread_create(&tid2, (void *)0, potok, argv[2]);
//   pthread_create(&tid1, &attr1, potok, argv[1]);
//   pthread_join(tid1, NULL);
//   printf("count = %d\n",count);
// //   pthread_join(tid2, NULL);
// //   printf("count = %d\n",count);
// }

// void *potok(void *param) 
// {
//   int i, upper = atoi(param);
//   count = 0;

//   if (upper > 0) {
//     for (i = 1; i <= upper; i++)
//     count += i;
//   }

//   pthread_exit(0);
// }