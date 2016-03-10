/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:05:19 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/10 15:22:22 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_ini_fract(t_env *e)
{
	if (!(ft_strcmp(e->argv, "mandelbrot")))
		ft_ini_val_mandel(e);
	if (!(ft_strcmp(e->argv, "julia")))
		ft_ini_val_julia(e);
	if (!(ft_strcmp(e->argv, "burning-ship")))
		ft_ini_val_bship(e);
	if (!(ft_strcmp(e->argv, "mandelbis")))
		ft_ini_val_mandelbis(e);
}

void	ft_print_fract(t_env *e)
{
	if (!(ft_strcmp(e->argv, "mandelbrot")))
		ft_print_mandel(e);
	if (!(ft_strcmp(e->argv, "julia")))
		ft_print_julia(e);
	if (!(ft_strcmp(e->argv, "burning-ship")))
		ft_print_bship(e);
	if (!(ft_strcmp(e->argv, "mandelbis")))
		ft_print_mandelbis(e);
}

int		main(int argc, char **argv)
{
	t_env e;

	e.argv = argv[1];
	if (argc == 2 && ((!(ft_strcmp(e.argv, "mandelbrot")))
		|| (!(ft_strcmp(e.argv, "julia")))
		|| (!(ft_strcmp(e.argv, "burning-ship")))
		|| (!(ft_strcmp(e.argv, "mandelbis")))))
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Fractol");
		e.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
		e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi);
		ft_ini_fract(&e);
		ft_print_fract(&e);
		mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, ft_key_biding, &e);
		mlx_hook(e.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &e);
		mlx_loop_hook(e.mlx, ft_core, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error();
	return (0);
}
