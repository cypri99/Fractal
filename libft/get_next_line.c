/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:07:36 by cmartini          #+#    #+#             */
/*   Updated: 2019/09/21 08:13:25 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_first_part(char *data)
{
	int		i;
	char	*firstpart;

	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	firstpart = ft_strsub(data, 0, i);
	return (firstpart);
}

char		*get_second_part(char *data)
{
	char	*ptr;

	if (ft_strchr(data, '\n'))
	{
		ptr = ft_strdup(ft_strchr(data, '\n') + 1);
		free(data);
		data = ptr;
	}
	else
		ft_bzero(data, ft_strlen(data));
	return (data);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*data[MAX_SIZE];
	int			bytes_read;

	if (!line || fd < 0 || (bytes_read = read(fd, buf, 0)) < 0)
		return (-1);
	if (!data[fd])
		data[fd] = ft_strnew(BUFF_SIZE + 1);
	while ((bytes_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(data[fd], buf);
		ft_strdel(&data[fd]);
		data[fd] = tmp;
		if (ft_strchr(data[fd], '\n'))
			break ;
	}
	*line = get_first_part(data[fd]);
	if (!ft_strcmp(data[fd], ""))
		return (0);
	data[fd] = get_second_part(data[fd]);
	return (1);
}
