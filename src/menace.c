/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menace.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:33:02 by cmartini          #+#    #+#             */
/*   Updated: 2020/01/28 23:07:33 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_menace(t_main *m_struct)
{
	NEW_X = 0.0;
	NEW_Y = 0.0;
	OLD_X = 0.0;
	OLD_Y = 0.0;
}

static void		fractal_loop(t_main *m_struct, int x, int y, int i)
{
	while (NEW_X * NEW_X + NEW_Y * NEW_Y < 4 && i > 1)
	{
		OLD_X = NEW_X;
		OLD_Y = NEW_Y;
		NEW_X = OLD_X * OLD_X - OLD_Y * OLD_Y - fabs(CR * CR);
		NEW_Y = 2 * fabs(OLD_X * OLD_Y) - fabs(CI * CI);
		--i;
		m_struct->pixels[y * WIDTH + x] = (i << 22) + (i << 10) + i * 8;
	}
}

static int		menace(t_main *m_struct)
{
	int y;
	int x;
	int max_iter;
	int i;

	y = -1;
	max_iter = 256;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			CR = 1.5 * (x - WIDTH * 3 / 4) / (0.5 * ZOOM * WIDTH) + MX;
			CI = 1.0 * (y - HEIGHT) / (0.5 * ZOOM * HEIGHT) + MY;
			i = max_iter;
			init_menace(m_struct);
			fractal_loop(m_struct, x, y, i);
		}
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}

void			fractol_menace(t_main *m_struct)
{
	MX = -0.5;
	MY = 0.0;
	ZOOM = 1.0;
	init_menace(m_struct);
	mlx_hook(WIN, 2, 0, key, m_struct);
	mlx_hook(WIN, 4, 0, mouse_scroll, m_struct);
	mlx_hook(WIN, 6, 0, mouse_move, m_struct);
	mlx_loop_hook(MLX, menace, m_struct);
	mlx_loop(MLX);
}
