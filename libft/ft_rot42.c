/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:58:01 by cmartini          #+#    #+#             */
/*   Updated: 2019/01/18 15:59:50 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ((str[i] - 97 + 42) % 26) + 97;
		else if (str[i] > 'z')
			str[i] = str[i] - 'z' + 'a' - 1;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ((str[i] - 65 + 42) % 26) + 65;
		else if (str[i] > 'Z')
			str[i] = str[i] - 'Z' + 'A' - 1;
		i++;
	}
	return (str);
}
