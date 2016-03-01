/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:02:15 by mfortin           #+#    #+#             */
/*   Updated: 2016/03/01 22:47:23 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIN_X 1080
# define WIN_Y 1000

typedef struct	s_env
{
	void		*mlx;
	void		*win;

	void		*im;
	void		*imc;
	int			bpp;
	int			imlen;
	int			endi;

	int			i;
	int			x;
	int			y;

	float		x1;
	float		x2;
	float		y1;
	float		y2;

	int			iter_max;
	int			im_x;
	int			im_y;

	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	float		tmp;

	float		zoom;
	float		zoom_x;
	float		zoom_y;
}				t_env;

void			ft_ini_val_mand(t_env *e);
void			ft_ini_val_julia(t_env *e);
void			ft_choose_fact(t_env *e, char *str);
void			ft_print_mandel(t_env *e);
void			ft_print_julia(t_env *e);

void			ft_put_pixel(t_env *e, int x, int y, int color);
int				ft_core(t_env *e);
void			ft_error(void);

#endif
