/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:07:29 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/02 17:33:48 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_print_bship(t_env *e)
{
	while (e->x < e->im_x)
	{
		e->y = 0;
		while (e->y < e->im_y)
		{
			e->c_r = e->x / e->zoom_x + e->x1;
			e->c_i = e->y / e->zoom_y + e->y1 - 0.4;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * fabs(e->z_i * e->tmp) + e->c_i;
				e->i++;
			}
			if (e->i == e->iter_max)
				ft_put_pixel(e, e->x, e->y + 100, 0x000000);
			else
				ft_put_pixel(e, e->x, e->y + 100, e->i * 256000000000 / e->iter_max);
			e->y++;
		}
		e->x++;
	}
}
