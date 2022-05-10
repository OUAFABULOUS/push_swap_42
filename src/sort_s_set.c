/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:37:24 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/10 23:52:50 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_tab_3(int **tab, t_list **a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		(*tab)[i] = tmp->rank;
		tmp = tmp->next;
		i++;
	}
}

void	sort_3(t_list **a, t_list **b, int *ins_nb)
{
	int		*tab;

	tab = malloc(3 * sizeof(int));
	if (!tab)
		return ;
	fill_tab_3(&tab, a);
	if (tab[0] == 0 && tab[1] == 2 && tab[2] == 1)
	{
		p(a, b, ins_nb, 1);
		s(a, ins_nb);
		p(b, a, ins_nb, 0);
	}
	else if (tab[0] == 1 && tab[1] == 0 && tab[2] == 2)
		s(a, ins_nb);
	else if (tab[0] == 1 && tab[1] == 2 && tab[2] == 0)
		rr(a, ins_nb);
	else if (tab[0] == 2 && tab[1] == 0 && tab[2] == 1)
		r(a, ins_nb);
	else if (tab[0] == 2 && tab[1] == 1 && tab[2] == 0)
	{
		rr(a, ins_nb);
		rr(a, ins_nb);
		s(a, ins_nb);
	}
	free(tab);
}

static int	rank_to_ind(int rank, t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->rank == rank)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

void	sort_4(t_list **a, t_list **b, int rank, int *ins_nb)
{
	if (rank_to_ind(rank, a) == 0)
		p(a, b, ins_nb, 1);
	else if (rank_to_ind(rank, a) == 1)
	{
		s(a, ins_nb);
		p(a, b, ins_nb, 1);
	}
	else if (rank_to_ind(rank, a) == 2)
	{
		rr(a, ins_nb);
		rr(a, ins_nb);
		p(a, b, ins_nb, 1);
	}
	else if (rank_to_ind(rank, a) == 3)
	{
		rr(a, ins_nb);
		p(a, b, ins_nb, 1);
	}
}

void	sort_5(t_list **a, t_list **b, int rank, int *ins_nb)
{
	if (rank_to_ind(rank, a) == 0)
		p(a, b, ins_nb, 1);
	else if (rank_to_ind(rank, a) == 1)
	{
		s(a, ins_nb);
		p(a, b, ins_nb, 1);
	}
	else if (rank_to_ind(rank, a) == 2)
	{
		r(a, ins_nb);
		r(a, ins_nb);
		p(a, b, ins_nb, 1);
	}
	else if (rank_to_ind(rank, a) == 3)
	{
		rr(a, ins_nb);
		rr(a, ins_nb);
		p(a, b, ins_nb, 1);
	}
	else if (rank_to_ind(rank, a) == 4)
	{
		rr(a, ins_nb);
		p(a, b, ins_nb, 1);
	}
}
