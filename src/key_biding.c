/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_biding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 21:52:55 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/02 18:17:58 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	ft_key_biding(void)
{
	return (0);
}

int	ft_key_release(int keycode)
{
	if (keycode == ESC)
		exit(1);
	return (0);
}

int	ft_do_key_action(void)
{
	return (0);
}

int	ft_core(t_env *e)
{
//	mlx_destroy_image(e->mlx, e->im);
//	e->im = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	ft_do_key_action();
	ft_print_fract(e);
	mlx_put_image_to_window(e->mlx, e->win, e->im, 0, 0);
	return (1);
}
