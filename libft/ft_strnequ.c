/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 22:07:54 by cmartini          #+#    #+#             */
/*   Updated: 2019/08/22 03:44:05 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*cpy1;
	char	*cpy2;

	if (s1 && s2)
	{
		cpy1 = (char *)s1;
		cpy2 = (char *)s2;
		while ((*cpy1 && *cpy2) && (n > 0))
		{
			if (*cpy1 != *cpy2)
				return (0);
			cpy1++;
			cpy2++;
			n--;
		}
		if ((*cpy1 != *cpy2) && (n > 0))
			return (0);
	}
	return (1);
}
