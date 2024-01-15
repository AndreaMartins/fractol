/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:19:42 by andmart2          #+#    #+#             */
/*   Updated: 2024/01/15 12:57:36 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	key_hook(int key, t_fract *f)
{
	if (key == ESC)
		cleanning(f);
	return (0);
}

int	mouse_hook(int key, int x, int y, t_fract *f)
{
	(void)x;
	(void)y;
	if (key == ZOOM_IN)
		f->zoom *= 0.8;
	if (key == ZOOM_OUT)
		f->zoom *= 1.2;
	mlx_clear_window(f->mlx, f->wind);
	draw_fractal(f);
	return (0);
}
