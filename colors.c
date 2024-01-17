/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:33:25 by andmart2          #+#    #+#             */
/*   Updated: 2024/01/17 13:48:10 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_color_ship(t_data *frac)
{
	int	red;
	int	green;
	int	blue;

	red = ((((frac->i * 5) % 255 * 0.5) + 0x7B) + 0xA1 * frac->i / 100) / 2;
	green = ((((frac->i * 7) % 255 * 0.5) + 0xD3) + 0xEE * frac->i / 100) / 2;
	blue = ((((frac->i * 11) % 255 * 0.5) + 0xEA) + 0xBD * frac->i / 100) / 2;
	return (red << 16 | green << 8 | blue);
}

int	calculate_color_mandelbrot(t_data *frac)
{
	int	red;
	int	green;
	int	blue;

	red = ((frac->i * 5) % 255 * 0.5) + 0x71;
	green = ((frac->i * 7) % 255 * 0.5) + 0x1D;
	blue = ((frac->i * 11) % 255 * 0.5) + 0xB0;
	return (red << 16 | (green + frac->i * 2) << 8 | blue + frac->i);
}

int	calculate_color_else(t_data *frac)
{
	int	red;
	int	green;
	int	blue;

	red = ((((frac->i * 8) % 255 * 0.5) + 0x29) + 0x78 * frac->i / 75) / 2;
	green = ((((frac->i * 10) % 255 * 0.5) + 0x4B) + 0x94 * frac->i / 75) / 2;
	blue = ((((frac->i * 12) % 255 * 0.5) + 0x29) + 0x61 * frac->i / 75) / 2;
	return (red << 16 | (green + frac->i * 3) << 8 | blue + frac->i);
}

int	ft_color(t_data *frac)
{
	if (frac->i == 100)
		return (0x000000);
	if (frac->type == 3)
		return (calculate_color_ship(frac));
	else if (frac->type == 1)
		return (calculate_color_mandelbrot(frac));
	else
		return (calculate_color_else(frac));
}
