/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:50:06 by cmartini          #+#    #+#             */
/*   Updated: 2019/08/19 22:22:18 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)dest;
	while (len-- > 0)
		*ptr++ = (unsigned char)val;
	return (dest);
}
