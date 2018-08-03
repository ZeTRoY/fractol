/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_burning_ship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <aroi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 22:56:28 by aroi              #+#    #+#             */
/*   Updated: 2018/08/03 23:13:20 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		set_penta_burn(t_fractol *fractol, int i, int j)
{
	double	temp_re;
	double	temp_im;
	int		iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = fabs(temp_re) * (temp_re * temp_re * temp_re *
			temp_re - 10 * temp_re * temp_re * temp_im * temp_im + 5 *
			temp_im * temp_im * temp_im * temp_im) + fractol->complex.c_re;
		fractol->complex.z_im = fabs(temp_im) * (5 * temp_re * temp_re *
			temp_re * temp_re - 10 * temp_im * temp_im * temp_re * temp_re +
			temp_im * temp_im * temp_im * temp_im) + fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}

int		set_burning_ship(t_fractol *fractol, int i, int j)
{
	double	temp_re;
	double	temp_im;
	int		iterations;

	fractol->complex.z_re = 0;
	fractol->complex.z_im = 0;
	iterations = -1;
	while (++iterations < fractol->depth)
	{
		temp_re = fractol->complex.z_re;
		temp_im = fractol->complex.z_im;
		fractol->complex.z_re = temp_re * temp_re - temp_im * temp_im +
			fractol->complex.c_re;
		fractol->complex.z_im = 2 * fabs(temp_re * temp_im) +
			fractol->complex.c_im;
		if ((fractol->complex.z_re * fractol->complex.z_re +
				fractol->complex.z_im * fractol->complex.z_im) > 4)
			break ;
	}
	return (iterations);
}
