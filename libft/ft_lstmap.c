/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartini <cmartini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 23:03:00 by cmartini          #+#    #+#             */
/*   Updated: 2019/08/23 01:31:36 by cmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*tmp;

	if (!lst)
		return (NULL);
	head = f(lst);
	lst = lst->next;
	tmp = head;
	while (lst)
	{
		tmp->next = f(lst);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (head);
}
