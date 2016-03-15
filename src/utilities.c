/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 21:47:52 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/15 12:52:12 by mfortin          ###   ########.fr       */
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

void	ft_print_settings(void)
{
	ft_putstr("\n\n      #################################################");
	ft_putstr("\n      #           WELCOLME TO WORLD OF FRACTOL        #\n");
	ft_putstr("      #################################################\n\n");
	ft_putstr("              HERE'S HOW TO INTERACT WITH FRACTOL:\n");
	ft_putstr("      -------------------------------------------------\n");
	ft_putstr("      |       KEY        |           ACTION           |\n");
	ft_putstr("      -------------------------------------------------\n");
	ft_putstr("      |      'ESC'       |      exit the programm     |\n");
	ft_putstr("      |   'left click'   |          zoom in           |\n");
	ft_putstr("      |  'right click'   |          zoom out          |\n");
	ft_putstr("      |       '+'        |    increase iteration      |\n");
	ft_putstr("      |       '-'        |    decrease iteration      |\n");
	ft_putstr("      | '1 - 2 - 3 or 4' | switch to an other fractal |\n");
	ft_putstr("      |       'C'        |   pause the modifications  |\n");
	ft_putstr("      |                  |          of Julia          |\n");
	ft_putstr("      |       '0'        |           reset            |\n");
	ft_putstr("      ------------------------------------------------\n\n\n");
}

void	ft_error(void)
{
	ft_putstr_fd("error : You can only use the following arguments : ", 2);
	ft_putstr_fd("1) mandelbrot\n", 2);
	ft_putstr_fd("               ", 2);
	ft_putstr_fd("                                    2) julia\n", 2);
	ft_putstr_fd("               ", 2);
	ft_putstr_fd("                                    3) burning-ship\n", 2);
	ft_putstr_fd("               ", 2);
	ft_putstr_fd("                                    4) mandelbis\n", 2);
	exit(1);
}
