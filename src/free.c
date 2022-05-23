/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:47:53 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/23 16:59:05 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_ll(t_list **a)
{
	t_list	*tmp;

	if (!*a)
		return ;
	while ((*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
	free(*a);
	*a = NULL;
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	if (splitted)
	{
		while (splitted[i])
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
		splitted = NULL;
	}
}

char	**free_split_2(char **splitted, int k)
{
	int	i;

	i = 0;
	if (splitted)
	{
		while (i < k)
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
		splitted = NULL;
	}
	return (NULL);
}
