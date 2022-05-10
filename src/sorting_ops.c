/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:42:11 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/09 22:28:21 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s(t_list **a, int *ins_nb)
{
	t_list	*new_first;
	t_list	*new_second;

	new_first = (*a)->next;
	new_second = *a;
	new_second->next = new_first->next;
	new_first->next = new_second;
	*a = new_first;
	write(1, "sa\n", 3);
	(*ins_nb)++;
}

void	r(t_list **a, int *ins_nb)
{
	t_list	*new_first;
	t_list	*new_last;
	t_list	*tmp;

	new_first = (*a)->next;
	new_last = *a;
	tmp = new_first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_last;
	tmp->next->next = NULL;
	*a = new_first;
	write(1, "ra\n", 3);
	(*ins_nb)++;
}

void	rr(t_list **a, int *ins_nb)
{
	t_list	*new_first;
	t_list	*new_last;

	new_first = *a;
	new_last = *a;
	while (new_first->next)
		new_first = new_first->next;
	add_elem_top(a, new_first->value);
	while (new_last->next->next)
		new_last = new_last->next;
	new_last->next = NULL;
	free(new_first);
	write(1, "rra\n", 4);
	(*ins_nb)++;
}

void	p(t_list **a, t_list **b, int *ins_nb, int ab)
{
	if (!*a)
		return ;
	add_elem_top(b, (*a)->value);
	del_elem_top(a);
	write(1, "p", 1);
	if (ab)
		write(1, "b\n", 2);
	else
		write(1, "a\n", 2);
	(*ins_nb)++;
}
