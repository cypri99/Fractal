/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:15:07 by cmartini          #+#    #+#             */
/*   Updated: 2019/08/23 01:26:00 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && i < size)
		i++;
	while (s2[j] && (i + j + 1) < size)
	{
		s1[i + j] = s2[j];
		j++;
	}
	if (i < size)
		s1[i + j] = '\0';
	return ((size_t)i + ft_strlen(s2));
}
