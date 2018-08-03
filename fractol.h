/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 09:58:20 by aroi              #+#    #+#             */
/*   Updated: 2018/08/03 23:03:21 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 600
# define THREAD_QNT 8

# define MACOS_ESC 53
# define MACOS_W 13
# define MACOS_A 0
# define MACOS_S 1
# define MACOS_D 2
# define MACOS_Z 6
# define MACOS_X 7
# define MACOS_C 8
# define MACOS_V 9
# define MACOS_B 11
# define MACOS_N 45
# define MACOS_M 46
# define SCROLL_DOWN 5
# define SCROLL_UP 4
# define MACOS_SPACE 49
# define MACOS_BACKSPACE 51
# define MACOS_MINUS 78
# define MACOS_PLUS 69
# define MACOS_MINUS2 27
# define MACOS_EQ 24

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>

typedef struct		s_z
{
	double			z_re;
	double			z_im;
	double			c_re;
	double			c_im;
	double			z;
	double			delta;
	double			min_re;
	double			min_im;
	double			max_re;
	double			max_im;
	double			re_factor;
	double			im_factor;
}					t_z;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_fractol
{
	char			*name;
	void			*mlx;
	void			*win;
	t_img			img;
	t_z				complex;
	int				depth;
	int				counter;
	int				mousex;
	int				mousey;
	double			jmousex;
	double			jmousey;
	int				mouseon;
	int				color;
}					t_fractol;

typedef struct		s_mlx
{
	void			*mlx;
	t_fractol		fractol[3];
}					t_mlx;

int					error(char *str);
int					key_mapping(int key, t_fractol *fractol);
void				reset(t_fractol *fractol);
int					mouse_controls(int mousebutton, int x, int y,
						t_fractol *fractol);
int					move_with_mouse(int x, int y, t_fractol *fractol);
void				init_window(char *str);
void				initialize_threads(t_fractol *fractol);
void				choose_color(int *color, int iterations,
						t_fractol *fractol);
int					rgb_log(int iter, t_fractol *fractol);
int					rgb_log2(int iter, t_fractol *fractol);
int					set_mandelbrot(t_fractol *fractol, int i, int j);
int					set_julia(t_fractol *fractol, int i, int j);
int					set_duobrot(t_fractol *fractol, int i, int j);
int					set_mandelbar(t_fractol *fractol, int i, int j);
int					set_pentabrot(t_fractol *fractol, int i, int j);
int					set_greataxe(t_fractol *fractol, int i, int j);
int					set_heart(t_fractol *fractol, int i, int j);
int					set_heartjulia(t_fractol *fractol, int i, int j);
int					set_eggs(t_fractol *fractol, int i, int j);
int					set_burning_ship(t_fractol *fractol, int i, int j);
int					set_penta_burn(t_fractol *fractol, int i, int j);
int					set_pentajulia(t_fractol *fractol, int i, int j);

#endif
