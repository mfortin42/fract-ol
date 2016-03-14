/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 22:11:30 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/14 14:14:21 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_print_julia(t_env *e)
{
	e->x = 0;
	while (e->x < e->im_x)
	{
		e->y = 0;
		while (e->y < e->im_y)
		{
			//e->c_r = 0.285;
			//e->c_i = 0.01;
			e->z_r = e->x / e->zoom + e->x1;
			e->z_i = e->y / e->zoom + e->y1;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			if (e->i == e->iter_max)
				ft_put_pixel(e, e->x, e->y, 0xFFFFFF);
			else
				ft_put_pixel(e, e->x, e->y, e->i * 1100000);
			e->y++;
		}
		e->x++;
	}
}
