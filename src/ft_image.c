/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anroche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 05:05:50 by anroche           #+#    #+#             */
/*   Updated: 2017/09/10 22:07:18 by anroche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../minilibx_macos/mlx.h"

void	ft_colorize(t_indication *id)
{
	static int a;

	if (id->colour == 83)
	{
		a += 2000;
		while (id->i-- > 0 && id->i != id->iter)
			id->color += 50000 + a;
	}
	if (id->colour == 84)
		if (id->i != id->iter)
			id->color = a++;
	if (id->colour == 85)
		if (id->i != id->iter)
			id->color = id->y + id->i * 2000000;
}

void	pixel_put_color(int x, int y, t_indication *id)
{
	unsigned long long	index;
	int					*ptr;

	ft_colorize(id);
	if (x >= 0 && x < VARX && y >= 0 && y < VARY)
	{
		index = y * id->s_l + x * id->bpp / 8;
		ptr = (int*)&id->str_img[index];
		*ptr = id->color;
	}
}

void	phread(t_indication *id)
{
	t_indication	tab[8];
	pthread_t		t[8];
	int				i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&tab[i], (void*)id, sizeof(t_indication));
		tab[i].y = 100 * i;
		tab[i].y_sup = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&t[i - 1], NULL, ft_turn, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
}

void	set_image(t_indication *id)
{
	id->img = mlx_new_image(id->mlx, VARX, VARY);
	id->str_img = mlx_get_data_addr(id->img, &(id->bpp),
			&(id->s_l), &(id->endian));
	phread(id);
	mlx_string_put(id->mlx, id->win, 10, 5, 0xFF00FF, "FRACTOL");
	mlx_clear_window(id->mlx, id->win);
	mlx_put_image_to_window(id->mlx, id->win, id->img, 0, 0);
	mlx_destroy_image(id->mlx, id->img);
}
