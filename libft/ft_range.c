/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:07:33 by cmartini          #+#    #+#             */
/*   Updated: 2019/01/17 15:13:00 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*k;
	int	i;

	if (min >= max)
	{
		k = NULL;
		return (k);
	}
	if (!(k = (int*)malloc(sizeof(int) * (max - min) + 1)))
		return (NULL);
	i = 0;
	while (max > min)
	{
		k[i] = min;
		i++;
		min++;
	}
	return (k);
}
