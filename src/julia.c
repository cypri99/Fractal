/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:18:03 by cmartini          #+#    #+#             */
/*   Updated: 2020/01/28 23:01:01 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_julia(t_main *m_struct)
{
	MX = 0.0;
	MY = 0.0;
	CR = -0.7;
	CI = 0.27015;
	ZOOM = 1;
}

static void		fractal_loop(t_main *m_struct, int x, int y, int i)
{
	while (NEW_X * NEW_X + NEW_Y * NEW_Y < 4 && i > 1)
	{
		OLD_X = NEW_X;
		OLD_Y = NEW_Y;
		NEW_X = OLD_X * OLD_X - OLD_Y * OLD_Y + CR;
		NEW_Y = 2 * OLD_X * OLD_Y + CI;
		--i;
		m_struct->pixels[y * WIDTH + x] = (i << 21) + (i << 10) + i * 8;
	}
}

static int		julia(t_main *m_struct)
{
	int	y;
	int	x;
	int	max_iter;
	int	i;

	y = -1;
	max_iter = 256;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			NEW_X = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MX;
			NEW_Y = 1.0 * (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MY;
			i = max_iter;
			fractal_loop(m_struct, x, y, i);
		}
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}

void			fractol_julia(t_main *m_struct)
{
	init_julia(m_struct);
	mlx_hook(WIN, 2, 0, key, m_struct);
	mlx_hook(WIN, 4, 0, mouse_scroll, m_struct);
	mlx_hook(WIN, 6, 0, mouse_move, m_struct);
	mlx_loop_hook(MLX, julia, m_struct);
	mlx_loop(MLX);
}
