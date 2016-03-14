/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 21:52:55 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/14 14:21:29 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_mouse_hook(int keycode, int x, int y, t_env *e)
{
	float	tmpx;
	float	tmpy;
	float	tmpx2;
	float	tmpy2;

	if (keycode == 2)
	{
		e->zoom /= 2;
		tmpx = e->x1 + x * (e->x2 - e->x1) / WIN_X;
		tmpy = e->y1 + y * (e->y2 - e->y1) / WIN_Y;
		tmpx2 = e->x1;
		tmpy2 = e->y1;
		e->x1 = tmpx - (e->x2 - e->x1);
		e->x2 = tmpx + (e->x2 - tmpx2);
		e->y1 = tmpy - (e->y2 - e->y1);
		e->y2 = tmpy + (e->y2 - tmpy2);
	}
	if (keycode == 1)
	{
		e->zoom *= 2;
		tmpx = e->x1 + x * (e->x2 - e->x1) / WIN_X;
		tmpy = e->y1 + y * (e->y2 - e->y1) / WIN_Y;
		tmpx2 = e->x1;
		tmpy2 = e->y1;
		e->x1 = tmpx - (e->x2 - e->x1) / 4;
		e->x2 = tmpx + (e->x2 - tmpx2) / 4;
		e->y1 = tmpy - (e->y2 - e->y1) / 4;
		e->y2 = tmpy + (e->y2 - tmpy2) / 4;
	}
	if ((!(ft_strcmp(e->argv, "julia"))))
	{
		e->c_r = (x - WIN_X) / 300;
		e->c_i = (y - WIN_Y) / 300;
	}
	return (1);
}

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
