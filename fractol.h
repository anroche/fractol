/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anroche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 17:26:32 by anroche           #+#    #+#             */
/*   Updated: 2018/02/24 16:34:20 by anroche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <pthread.h>
# include <stdio.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

# define VARX	800
# define VARY	800

typedef struct		s_indication
{
	int				color;
	void			*mlx;
	void			*win;
	void			*img;
	char			*str_img;
	int				bpp;
	int				s_l;
	int				endian;

	long double		x;
	long double		y;
	long double		y_sup;

	double			x1;
	double			x2;
	double			y1;
	double			y2;

	double			image_x;
	double			image_y;
	unsigned int	bloc;
	int				iter;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	int				i;
	double			zoom;
	int				fractal;
	double			julx;
	double			july;
	int				pause;
	int				colour;
}					t_indication;

void				phread(t_indication *id);
void				ft_colorize(t_indication *id);
void				pixel_put_color(int x, int y, t_indication *id);
void				set_image(t_indication *id);
void				ft_fractol(int index);
void				*ft_turn(void *tab);
void				ft_fractal(t_indication id);
int					ft_key_func(int keycode, t_indication *id);
int					mouse_zoom(int key, int x, int y, t_indication *id);
void				ft_ini(t_indication *id);
void				ft_init(t_indication *id);
void				ft_iter(int keycode, t_indication *id);
int					ft_fractolize(int x, int y, t_indication *id);
void				ft_change(int nb, t_indication *id);

#endif
