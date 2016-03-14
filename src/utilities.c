/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 21:47:52 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/14 16:12:41 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
	ft_putstr_fd("     ", 2);
	ft_putstr_fd("                                     4) mandelbis\n", 2);
	exit(1);
}
