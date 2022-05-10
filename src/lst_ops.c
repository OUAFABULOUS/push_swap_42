/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:20:57 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/09 20:37:41 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lst_len(t_list *a)
{
	int		len;
	t_list	*tmp;

	tmp = a;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_list	*create_elem(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_elem_last(t_list **a, int value)
{
	t_list	*tmp;

	tmp = *a;
	if (!*a)
		*a = create_elem(value);
	else
	{
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = create_elem(value);
		*a = tmp;
	}
}

void	del_elem_top(t_list **a)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
}

void	add_elem_top(t_list **a, int value)
{
	t_list	*tmp;

	if (!*a)
		*a = create_elem(value);
	else
	{
		tmp = create_elem(value);
		tmp->next = *a;
		*a = tmp;
	}
}
