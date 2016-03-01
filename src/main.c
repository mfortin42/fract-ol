/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:05:19 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/01 22:52:13 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_choose_fract(t_env *e, char *str)
{
	if (!(ft_strcmp(str, "mandelbrot")))
	{
		ft_ini_val_mand(e);
		ft_print_mandel(e);
	}
	if (!(ft_strcmp(str, "julia")))
	{
		ft_ini_val_julia(e);
		ft_print_julia(e);
	}
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc == 2 && ((!(ft_strcmp(argv[1], "mandelbrot")))
		|| (!(ft_strcmp(argv[1], "julia")))))
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Fractol");
		e.im = mlx_new_image(e.mlx, WIN_X, WIN_Y);
		e.imc = mlx_get_data_addr(e.im, &e.bpp, &e.imlen, &e.endi);
		ft_choose_fract(&e, argv[1]);
		mlx_loop_hook(e.mlx, ft_core, &e);
		mlx_loop(e.mlx);
	}
	else
		ft_error();
	return (0);
}
