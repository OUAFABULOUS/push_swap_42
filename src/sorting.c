/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:49:22 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/10 23:38:22 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_s_set_5(t_list **a, t_list **b, int *ins_nb, int *np)
{
	sort_5(a, b, 0, ins_nb);
	rank_ll(a);
	*np = 1;
}

static void	sort_s_set_4(t_list **a, t_list **b, int *ins_nb, int *np)
{
	sort_4(a, b, 0, ins_nb);
	rank_ll(a);
	*np = 1;
}

void	sort_s_set(t_list **a, t_list **b, int *ins_nb)
{
	int	need_push[2];

	need_push[0] = 0;
	need_push[1] = 0;
	if ((*a)->l_len == 2)
	{
		s(a, ins_nb);
		return ;
	}
	rank_ll(a);
	if (ft_lst_len(*a) == 5)
		sort_s_set_5(a, b, ins_nb, &(need_push[1]));
	if (ft_lst_len(*a) == 4)
		sort_s_set_4(a, b, ins_nb, &(need_push[0]));
	if (ft_lst_len(*a) == 3)
		sort_3(a, b, ins_nb);
	if (need_push[0] || need_push[1])
		p(b, a, ins_nb, 0);
	if (need_push[1])
		p(b, a, ins_nb, 0);
}

void	sort_b_set(t_list **a, t_list **b, int *ins_nb)
{
	int	len_bin;
	int	a_len;
	int	b_len;
	int	i;
	int	j;

	len_bin = get_bin_len((*a)->l_len);
	a_len = ft_lst_len(*a);
	i = -1;
	while (++i < len_bin)
	{
		rank_ll(a);
		j = -1;
		while (++j < a_len)
		{
			if (!((((*a)->rank) >> i) & 1))
				p(a, b, ins_nb, 1);
			else
				r(a, ins_nb);
		}
		j = -1;
		b_len = ft_lst_len(*b);
		while (++j < b_len)
			p(b, a, ins_nb, 0);
	}
}

void	ft_sort(t_list **a, t_list **b, int *ins_nb)
{
	int	l_len;

	l_len = ft_lst_len(*a);
	if (ft_is_sorted(a))
		return ;
	if (l_len <= 5)
		sort_s_set(a, b, ins_nb);
	else
		sort_b_set(a, b, ins_nb);
}
