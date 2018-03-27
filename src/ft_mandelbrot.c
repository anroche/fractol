/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anroche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 22:30:54 by anroche           #+#    #+#             */
/*   Updated: 2018/02/24 17:47:25 by anroche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../fractol.h"
#include "../minilibx_macos/mlx.h"
#include <stdio.h>

void	ft_fractol(int index)
{
	t_indication id;

	id.fractal = index;
	id.julx = 0.285;
	id.july = 0.1;
	id.mlx = mlx_init();
	id.win = mlx_new_window(id.mlx, VARX, VARY, "FRACTOL");
	ft_ini(&id);
	id.pause = 0;
	id.i = 5;
	id.colour = 85;
	set_image(&id);
	mlx_mouse_hook(id.win, mouse_zoom, &id);
	mlx_key_hook(id.win, ft_key_func, &id);
	if (id.pause % 2 == 0)
		mlx_hook(id.win, 6, 0, ft_fractolize, &id);
	mlx_loop(id.mlx);
}

void	ft_ini(t_indication *id)
{
	id->iter = 10;
	id->x1 = -2.25;
	id->y1 = -2.25;
	id->x2 = 3.5;
	id->y2 = 2.5;
	id->zoom = 180;
	id->image_x = VARX;
	id->image_y = VARY;
}

void	ft_init(t_indication *id)
{
	id->i = 0;
	if (id->fractal == 1)
	{
		id->c_r = id->x / id->zoom + id->x1;
		id->c_i = id->y / id->zoom + id->y1;
		id->z_r = 0.0;
		id->z_i = 0.0;
	}
	if (id->fractal == 2)
	{
		id->c_r = id->julx;
		id->c_i = id->july;
		id->z_r = id->x / id->zoom + id->x1;
		id->z_i = id->y / id->zoom + id->y1;
	}
	if (id->fractal == 3)
	{
		id->c_r = id->x / id->zoom + id->x1;
		id->c_i = id->y / id->zoom + id->y1;
		id->z_r = 0.0;
		id->z_i = 0.0;
	}
}

void	*ft_turn(void *tab)
{
	t_indication id;

	id = *(t_indication *)tab;
	while (id.y++ < id.y_sup)
	{
		id.x = -1;
		while (++id.x < id.image_x)
		{
			ft_init(&id);
			ft_fractal(id);
		}
	}
	return (NULL);
}

void	ft_fractal(t_indication id)
{
	double tmp;

	while (id.z_r * id.z_r + id.z_i * id.z_i < 4 && id.i < id.iter &&
			id.fractal != 3)
	{
		tmp = id.z_r;
		id.z_r = id.z_r * id.z_r - id.z_i * id.z_i + id.c_r;
		id.z_i = 2.0 * id.z_i * tmp + id.c_i;
		id.i++;
	}
	while (id.z_r * id.z_r + id.z_i * id.z_i < 4 && id.i < id.iter &&
			id.fractal == 3)
	{
		tmp = id.z_r;
		id.z_r = fabs(id.z_r * id.z_r - id.z_i * id.z_i - id.c_r);
		id.z_i = 2.0 * fabs(id.z_i * tmp + id.c_i);
		id.i++;
	}
	if (id.i <= id.iter)
		pixel_put_color(id.x, id.y, &id);
}
