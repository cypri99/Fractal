/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:34:07 by cmartini          #+#    #+#             */
/*   Updated: 2020/01/28 23:06:18 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr("\nWrong input, either use:\n\n");
	ft_putstr("./fractol 1 (for Mandelbrot)\n");
	ft_putstr("./fractol 2 (for Julia)\n");
	ft_putstr("./fractol 3 (for Tree)\n");
	ft_putstr("./fractol 4 (for Rosae)\n");
	ft_putstr("./fractol 5 (for Bloup)\n\n");
	exit(-1);
}

void	starter(t_main *m_struct)
{
	if (m_struct->e == 1)
		fractol_mandel(m_struct);
	else if (m_struct->e == 2)
		fractol_julia(m_struct);
	else if (m_struct->e == 3)
		fractol_tricorn(m_struct);
	else if (m_struct->e == 4)
		fractol_juliamx(m_struct);
	else if (m_struct->e == 5)
		fractol_menace(m_struct);
	else
		usage();
}

void	quit(t_main *m_struct)
{
	mlx_clear_window(m_struct->mlx, m_struct->win);
	mlx_destroy_window(m_struct->mlx, m_struct->win);
	exit(0);
}

int		main(int ac, char **av)
{
	t_main	m_struct;

	if (ac == 2 && (av[1][0] == '1' || av[1][0] == '2' || av[1][0] == '3'
		|| av[1][0] == '4' || av[1][0] == '5'))
	{
		m_struct.e = ft_atoi(&av[1][0]);
		m_struct.mlx = mlx_init();
		m_struct.win = mlx_new_window(m_struct.mlx, WIDTH, HEIGHT,
			"*~* F R A C T A L *~*");
		m_struct.img = mlx_new_image(m_struct.mlx, WIDTH, HEIGHT);
		m_struct.pixels = (uint32_t*)mlx_get_data_addr(m_struct.img,
			&(BPP), &(SL), &(ENDIAN));
		m_struct.mode = 1;
		starter(&m_struct);
		mlx_put_image_to_window(m_struct.mlx, m_struct.win, m_struct.img, 0, 0);
		mlx_loop(m_struct.mlx);
	}
	else
		usage();
	return (0);
}
