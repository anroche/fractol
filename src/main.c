/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anroche <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 22:09:44 by anroche           #+#    #+#             */
/*   Updated: 2017/09/20 17:47:00 by anroche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../fractol.h"
#include "../minilibx_macos/mlx.h"

void	ft_err(void)
{
	ft_putstr("1/ Ecrire : Mandelbrot");
	ft_putstr("\n2/ Ecrire : Julia");
	ft_putstr("\n3/ Ecrire : Ship");
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Mandelbrot"))
			ft_fractol(1);
		if (!ft_strcmp(av[1], "Julia"))
			ft_fractol(2);
		if (!strcmp(av[1], "Ship"))
			ft_fractol(3);
		ft_err();
	}
	else
		ft_err();
	return (0);
}
