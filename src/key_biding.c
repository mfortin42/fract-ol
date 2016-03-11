/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 21:52:55 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/10 15:33:15 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_key_biding(int keycode, t_env *e)
{
	if (keycode == COLOR)
		e->c = 1;
	if (keycode == ITER_M || keycode == ITER_L)
		e->itm = (keycode == ITER_M ? 1 : -1);
	if (keycode == RESET)
		e->res = 1;
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(1);
	if (keycode == COLOR)
		e->c = 0;
	if (keycode == ITER_M || keycode == ITER_L)
		e->itm = 0;
	if (keycode == RESET)
		e->res = 0;
	return (0);
}

void	ft_do_key_action(t_env *e)
{
	if (e->c)
		e->col = e->col + 100;
	if (e->itm == -1 && e->iter_max > 20)
		e->iter_max -= 20;
	if (e->itm == 1)
		e->iter_max += 20;
	if (e->res == 1)
		ft_ini_fract(e);
}

int		ft_core(t_env *e)
{
	mlx_destroy_image(e->mlx, e->im);
	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_do_key_action(e);
	ft_print_fract(e);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	return (1);
}
