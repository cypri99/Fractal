/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:21:38 by cmartini          #+#    #+#             */
/*   Updated: 2020/01/28 23:27:32 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <inttypes.h>

# define HEIGHT 550
# define WIDTH 900
# define ESC 53
# define PLUS 24
# define MINUS 27
# define K_RETURN 36
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123
# define SCROLL_IN 4
# define SCROLL_OUT 5
# define SPACE 49

# define ZOOM		m_struct->zoom
# define MX			m_struct->m_x
# define MY			m_struct->m_y
# define CR			m_struct->c_re
# define CI			m_struct->c_im
# define NEW_X		m_struct->zx
# define NEW_Y		m_struct->zy
# define OLD_X		m_struct->tmpzx
# define OLD_Y		m_struct->tmpzy
# define MODE		m_struct->mode

# define MLX		m_struct->mlx
# define WIN		m_struct->win
# define IMG		m_struct->img

# define BPP		m_struct.bits_per_pixel
# define SL			m_struct.size_line
# define ENDIAN		m_struct.endian

typedef struct		s_main
{
	void			*mlx;
	void			*win;
	int				e;
	void			*img;
	uint32_t		*pixels;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	double			c_re;
	double			c_im;
	double			x_new;
	double			zoom;
	double			m_x;
	double			m_y;
	double			zx;
	double			zy;
	double			tmpzx;
	double			tmpzy;
	int				mode;
}					t_main;

void                usage(void);
void				starter(t_main *m_struct);
int					key(int key, t_main *m_struct);
int					key2(int key, t_main *m_struct);
void				quit(t_main *m_struct);
void				fractol_mandel(t_main *m_struct);
void				fractol_menace(t_main *m_struct);
void				fractol_julia(t_main *m_struct);
void				fractol_juliamx(t_main *m_struct);
void				save_file(t_main *m_struct);
void				fractol_tricorn(t_main *m_struct);
int					mouse_scroll(int key, int x, int y, t_main *m_struct);
int					mouse_move(int x, int y, t_main *m_struct);

#endif
