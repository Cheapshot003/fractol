/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otietz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:51:35 by otietz            #+#    #+#             */
/*   Updated: 2022/10/21 02:00:43 by otietz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list1;
	t_list	*begin;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	list1 = ft_lstnew(f(lst->content));
	if (list1 == 0)
		return (0);
	begin = list1;
	lst = lst->next;
	while (lst)
	{
		list1->next = ft_lstnew(f(lst->content));
		if (list1->next == 0)
		{
			ft_lstclear(&begin, del);
			return (0);
		}
		list1 = list1->next;
		lst = lst->next;
	}
	list1->next = 0;
	return (begin);
}
