/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:22:58 by cmartini          #+#    #+#             */
/*   Updated: 2019/08/21 20:14:30 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*x;

	if (!(x = (unsigned char *)malloc(size)))
		return (NULL);
	ft_bzero(x, size);
	return (x);
}
