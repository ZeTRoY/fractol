/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 20:10:17 by aroi              #+#    #+#             */
/*   Updated: 2018/08/03 23:13:04 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			error(char *str)
{
	ft_printf("{red}%s{eoc}\n", str);
	return (1);
}

void		usage(void)
{
	ft_printf("       {red}Usage:{eoc}\n./fractol mandelbrot\n");
	ft_printf("./fractol julia\n./fractol mandelbar\n./fractol heartbrot\n");
	ft_printf("./fractol dualbrot\n./fractol \"great axe\"\n\
	./fractol pentabrot\n");
	ft_printf("./fractol eggs\n./fractol \"burning ship\"\n\
	./fractol \"penta burn\"\n");
	ft_printf("./fractol heartjulia\n./fractol pentajulia\n");
	ft_printf("\nYou should write {red}one{eoc}, {red}two{eoc} or \
	{red}three{eoc} parametrs, but no more and no less!\n");
	exit(1);
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

void		func_for_second_window(int argc, char **argv)
{
	pid_t	id;

	id = 1;
	if (argc > 3)
		id = fork();
	if (id > 0)
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

int			main(int argc, char **argv)
{
	int			i;
	pid_t		id;
	int			k;

	i = 0;
	k = 0;
	id = 55;
	if (argc == 1 || argc > 4)
		usage();
	if (argc > 2)
		id = fork();
	if (id > 0)
	{
		if ((!is_right_name(argv[1]) || !is_right_name(argv[2])) &&
				!is_right_name(argv[3]))
			wait(0);
		if (!is_right_name(argv[1]))
			usage();
		init_window(argv[1]);
	}
	else
		func_for_second_window(argc, argv);
	return (0);
}
