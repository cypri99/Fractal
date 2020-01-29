/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:26:26 by cmartini          #+#    #+#             */
/*   Updated: 2020/01/28 23:02:13 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key(int key, t_main *m_struct)
{
	if (key == ESC)
		quit(m_struct);
	else if (key == K_RETURN)
		save_file(m_struct);
	else if (key == PLUS)
	{
		if (ZOOM <= 20)
			ZOOM += 1.15;
		else
			ZOOM *= 2;
	}
	else if (key == MINUS)
	{
		if (ZOOM <= 20)
			ZOOM -= 1.15;
		else
			ZOOM *= 2;
	}
	else
		key2(key, m_struct);
	return (0);
}

int		key2(int key, t_main *m_struct)
{
	if (key == ARROW_UP)
		MY -= 0.5;
	else if (key == ARROW_DOWN)
		MY += 0.5;
	else if (key == ARROW_LEFT)
		MX -= 0.5;
	else if (key == ARROW_RIGHT)
		MX += 0.5;
	else if (key == SPACE)
		MODE = (MODE == 1) ? 0 : 1;
	return (0);
}

int		mouse_scroll(int key, int x, int y, t_main *m_struct)
{
	(void)x;
	(void)y;
	if (key == SCROLL_IN)
	{
		if (ZOOM <= 20)
			ZOOM += 1.15;
		else
			ZOOM *= 2;
	}
	else if (key == SCROLL_OUT)
	{
		if (ZOOM <= 20)
			ZOOM -= 1.15;
		else
			ZOOM *= 2;
	}
	return (0);
}

int		mouse_move(int x, int y, t_main *m_struct)
{
	if (MODE == 1)
	{
		CR -= (double)(x * 0.00001);
		CI += (double)(y * 0.00001);
	}
	else if (MODE == 0)
	{
		CR += (double)(x * 0.00001);
		CI -= (double)(y * 0.00001);
	}
	return (0);
}
