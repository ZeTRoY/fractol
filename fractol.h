/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 09:58:20 by aroi              #+#    #+#             */
/*   Updated: 2018/08/03 19:47:20 by aroi             ###   ########.fr       */
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
# define SCROLL_DOWN 5
# define SCROLL_UP 4
# define MACOS_SPACE 49
# define MACOS_BACKSPACE 51

# define INTERPOLATE(start, end, inerpolation) start + (end - start) * interpolation

# define OFFSETX_SHRINK(x) (double)(-1 * ((double)(x) / WIDTH) * (2.7))
# define OFFSETY_SHRINK(y) (double)(     ((double)(y) / HEIGHT) * (2.4))
# define OFFSETX_DEPLOY(x) (int)((x * WIDTH) / (2.7) * -1)
# define OFFSETY_DEPLOY(y) (int)((y * HEIGHT) / (2.4))

#include "libft.h"
#include "mlx.h"
#include <math.h>
#include <pthread.h>

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

#endif