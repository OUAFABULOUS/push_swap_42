/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:15:18 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/09 20:37:41 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_construct_tab(t_list **a, int **tab, int l_len)
{
	t_list	*tmp;
	int		i;

	i = 0;
	*tab = malloc(l_len * sizeof(int));
	if (!*tab)
		return ;
	tmp = *a;
	while (tmp)
	{
		(*tab)[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static	void	ft_sort_tab(int **tab, int l_len)
{
	int	i;
	int	j;
	int	k;
	int	min;

	i = 0;
	while (i < l_len - 1)
	{
		min = (*tab)[i];
		j = i + 1;
		while (j < l_len)
		{
			if ((*tab)[j] < min)
			{
				min = (*tab)[j];
				k = j;
			}
			j++;
		}
		if (min != (*tab)[i])
			ft_swap(&((*tab)[i]), &((*tab)[k]));
		i++;
	}
}

static void	ft_index_ll(t_list **a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *a;
	while (*a)
	{
		(*a)->index = i;
		i++;
		*a = (*a)->next;
	}
	*a = tmp;
}

void	rank_ll(t_list **a)
{
	int		*tab;
	int		i;
	t_list	*tmp;
	int		l_len;

	l_len = ft_lst_len(*a);
	(*a)->l_len = l_len;
	ft_construct_tab(a, &tab, l_len);
	ft_sort_tab(&tab, l_len);
	tmp = *a;
	while (*a)
	{
		i = 0;
		while (i < l_len)
		{
			if (tab[i] == (*a)->value)
				(*a)->rank = i;
			i++;
		}
		*a = (*a)->next;
	}
	*a = tmp;
	if (tab)
		free(tab);
	ft_index_ll(a);
}
