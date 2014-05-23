/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 16:42:14 by ytailor           #+#    #+#             */
/*   Updated: 2014/02/09 15:02:02 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_serveur.h"

t_list		*ft_create_elem(char c)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new->c = c;
	new->next = NULL;
	new->last = new;
	return (new);
}

t_list		*ft_add_elem(char c, t_list *list)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*new;

	tmp = list;
	tmp2 = list;
	new = ft_create_elem(c);
	if (tmp == NULL)
		return (new);
	tmp = tmp->last;
	tmp2->last = new;
	tmp->next = new;
	return (list);
}

void		ft_print_list(const t_list *list)
{
	while (list)
	{
		ft_putchar(list->c);
		list = list->next;
	}
	ft_putchar('\n');
}
