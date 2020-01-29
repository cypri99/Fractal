/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cypri99@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:18:27 by cmartini          #+#    #+#             */
/*   Updated: 2019/08/07 20:34:57 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (!n)
		return (0);
	while ((*s1 && *s2 && *s1 == *s2) && --n)
	{
		++s1;
		++s2;
	}
	return (unsigned char)(*s1) - (unsigned char)(*s2);
}
