/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 20:38:04 by cmartini          #+#    #+#             */
/*   Updated: 2019/08/23 03:13:56 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void		*reverse_memcpy(void *dest, void *src, size_t len)
{
	size_t			index;
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	index = 0;
	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	dest_cast += len - 1;
	src_cast += len - 1;
	while (index < len)
	{
		*dest_cast-- = *src_cast--;
		index++;
	}
	return ((void *)dest);
}

void			*ft_memmove(void *dest, void *src, size_t len)
{
	if (dest > src)
		return (reverse_memcpy(dest, src, len));
	else
		return (ft_memcpy(dest, src, len));
}
