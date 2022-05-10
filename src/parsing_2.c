/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:58:53 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/10 15:11:26 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_doubles(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		to_compare;

	tmp1 = *a;
	while (*a && (*a)->next)
	{
		tmp2 = *a;
		to_compare = (*a)->value;
		*a = (*a)->next;
		while (*a)
		{
			if ((*a)->value == to_compare)
			{
				*a = tmp1;
				return (1);
			}
			*a = (*a)->next;
		}
	*a = tmp2;
	*a = (*a)->next;
	}
	*a = tmp1;
	return (0);
}

int	ft_is_sorted(t_list **a)
{
	t_list	*tmp;
	int		i;
	int		l_len;

	tmp = *a;
	i = 1;
	l_len = ft_lst_len(*a);
	(*a)->l_len = l_len;
	while (*a && (*a)->next && (*a)->value < (*a)->next->value)
	{
		i++;
		*a = (*a)->next;
	}
	if (i == l_len)
	{
		*a = tmp;
		return (1);
	}
	else
	{
		*a = tmp;
		return (0);
	}
}

void	parse(t_list **a, int argc, char **argv, int j)
{
	int	params[2];

	params[0] = -1;
	params[1] = 0;
	while (++(params[0]) < argc)
	{
		ft_advanced_atoi(argv[params[0]], a, &(params[1]));
		if (params[1])
		{
			if (!j)
				free_split(argv);
			free_ll(a);
			exit(1);
		}
	}
	if (ft_is_sorted(a))
		return ;
	if (ft_check_doubles(a) || ft_lst_len(*a) == 1)
	{
		err_atoi(&params[1]);
		if (!j)
			free_split(argv);
		free_ll(a);
		exit(1);
	}
}
