/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:20:08 by andmart2          #+#    #+#             */
/*   Updated: 2024/01/17 12:19:32 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mandelbrot(t_data *frac)
{
	frac -> type = 1;
	frac -> color = 9;
	frac -> lim.xmin = -2.1;
	frac -> lim.xmax = 0.7;
	frac -> lim.ymin = -1.2;
	frac -> lim.ymax = 1.2;
	frac -> lim.cr = 0;
	frac -> lim.cim = 0;
}

void	draw_mandel(t_data *frac)
{
	double	x;
	double	y;
	double	temp;

	x = 0;
	y = 0;
	frac -> i = -1;
	while ((x * x + y * y) <= 6.0 && ++frac -> i < 100)
	{
		temp = x * x - y * y + frac->x;
		y = 2 * x * y + frac->y;
		x = temp;
	}
}
