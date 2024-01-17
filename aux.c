/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:18:51 by andmart2          #+#    #+#             */
/*   Updated: 2024/01/17 13:27:52 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_put(t_data *frac, int x, int y, int color)
{
	char	*pix;

	pix = frac->img.ppt + (frac->img.line * y + x * (frac->img.bits / 8));
	*(int *)pix = color;
}

int	ft_color(t_data *frac)
{
	int	red;
	int green;
	int	blue;

	if (frac->i == 100)
		return (0x000000);
	if (frac->type == 3)
	{
		red = ((((frac->i * 5) % 255 * 0.5) + 0x7B) + 0xA1 * frac->i / 100) / 2;
		green = ((((frac->i * 7) % 255 * 0.5) + 0xD3) + 0xEE * frac->i / 100) / 2;
		blue = ((((frac->i * 11) % 255 * 0.5) + 0xEA) + 0xBD * frac->i / 100) / 2;
		return red << 16 | green << 8 | blue;
	}
	else if (frac->type == 1)
	{
		red = ((frac->i * 5) % 255 * 0.5) + 0x71;
		green = ((frac->i * 7) % 255 * 0.5) + 0x1D;
		blue = ((frac->i * 11) % 255 * 0.5) + 0xB0;
		return red << 16 | (green + frac->i * 2) << 8 | blue + frac->i;
	}
	else
	{
		red = ((((frac->i * 8) % 255 * 0.5) + 0x29) + 0x78 * frac->i / 75) / 2;
		green = ((((frac->i * 10) % 255 * 0.5) + 0x4B) + 0x94 * frac->i / 75) / 2;
		blue = ((((frac->i * 12) % 255 * 0.5) + 0x29) + 0x61 * frac->i / 75) / 2;
		return red << 16 | (green + frac->i * 3) << 8 | blue + frac->i;
	}
}


int	ft_key_hook(int key, t_data *frac)
{
	if (key == ESC)
		ft_free(frac);
	else if (key == SHIFT)
	{
		if (frac->color < 1000)
			frac->color *= 3;
		else
			frac->color = 1;
	}
	else
		return (1);
	fractal_draw(frac);
	return (0);
}

int	ft_read_keys(int key, t_data *frac)
{
	if (key > 122 && key < 127)
		ft_move(key, frac);
	fractal_draw(frac);
	return (0);
}

int	ft_mouse_hook(int key, int x, int y, t_data *frac)
{
	if (frac -> type == 2 && key == LEFT_CLICK)
	{
		frac->lim.cr = -2 + (frac->lim.xmax - frac->lim.xmin) * \
						(double)x / WIDTH;
		frac->lim.cim = -2 + (frac->lim.ymax - frac->lim.ymin) * \
						(double)y / HEIGHT;
	}
	if (key == ZOOM_IN || key == ZOOM_OUT)
		ft_zoom(key, (double)x / WIDTH, (double)y / (HEIGHT), frac);
	fractal_draw(frac);
	return (0);
}
