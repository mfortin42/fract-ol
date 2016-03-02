/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 21:47:52 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/02 16:43:35 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_ini_val_mandel(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->im_x = 1000;
	e->im_y = 1000;
	e->zoom_x = e->im_x / (e->x2 - e->x1);
	e->zoom_y = e->im_y / (e->y2 - e->y1);
	e->iter_max = 50;
	e->x = 0;
}

void	ft_ini_val_julia(t_env *e)
{
	e->x1 = -1;
	e->x2 = 1;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->zoom = 400;
	e->im_x = (e->x2 - e->x1) * e->zoom;
	e->im_y = (e->y2 - e->y1) * e->zoom;
	e->iter_max = 250;
	e->x = 0;
}

void	ft_ini_val_bship(t_env *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->im_x = 1000;
	e->im_y = 1000;
	e->zoom_x = e->im_x / (e->x2 - e->x1) - 70;
	e->zoom_y = e->im_y / (e->y2 - e->y1) - 70;
	e->iter_max = 100;
	e->x = 0;
}

void	ft_put_pixel(t_env *e, int x, int y, int color)
{
	int *tmp;

	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	tmp = (int *)&e->imc[(y * e->imlen) + (x * (e->bpp / 8))];
	*tmp = color;
}

void	ft_error(void)
{
	ft_putstr_fd("error : veuillez rentrer en parametre,\n", 2);
	ft_putstr_fd("        ", 2);
	ft_putstr_fd("uniquement un des ces arguments : 1) mandelbrot\n", 2);
	ft_putstr_fd("                                          2) julia\n", 2);
	ft_putstr_fd("     ", 2);
	ft_putstr_fd("                                     3) burning-ship\n", 2);
	exit(1);
}
