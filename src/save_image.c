/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:39:16 by cmartini          #+#    #+#             */
/*   Updated: 2020/01/28 23:27:51 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"
#include <fcntl.h>

char	*get_name(void)
{
	char	*buffer;
	int		b;

	buffer = malloc(200);
	b = read(0, buffer, 199);
	buffer[b - 1] = '\0';
	return (buffer);
}

void	convert_rgb(t_main *m_struct)
{
	int	i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		m_struct->pixels[i] =
		(m_struct->pixels[i] & 255) << 16 |
		(m_struct->pixels[i] & 65280) |
		(m_struct->pixels[i] & 16711680) >> 16;
		i++;
	}
}

void	save_file(t_main *m_struct)
{
	char	*filename;
	char	*str;

	if (!(open("images", O_RDONLY | O_DIRECTORY)))
		system("mkdir images");
	ft_putstr("Input file name :");
	filename = get_name();
	str = ft_strjoin(ft_strdup("echo "), "images/");
	str = ft_strjoin(str, filename);
	system(str);
	free(str);
	str = ft_strjoin(ft_strdup("images/"), filename);
	str = ft_strjoin(str, ".jpg");
	convert_rgb(m_struct);
	stbi_write_jpg(str, WIDTH, HEIGHT, 4,
	m_struct->pixels, 500);
	free(filename);
	free(str);
}
