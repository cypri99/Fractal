/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:15:14 by cmartini          #+#    #+#             */
/*   Updated: 2019/08/23 01:40:46 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	int		b_index;
	int		b_save;
	int		l_index;
	int		l_len;
	char	*cast;

	b_save = 0;
	b_index = 0;
	l_len = ft_strlen(little);
	cast = (char *)big;
	if (!*little)
		return (cast);
	while (cast[b_index])
	{
		l_index = 0;
		b_index = b_save;
		while (cast[b_index++] == little[l_index])
		{
			if (l_index + 1 == l_len)
				return (cast += (b_index - 1 - l_index));
			l_index++;
		}
		b_save++;
	}
	return (NULL);
}
