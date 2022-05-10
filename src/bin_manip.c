/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 22:28:24 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/09 20:37:41 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_bin_len(int n)
{
	int	two;
	int	i;

	two = 1;
	i = 1;
	if (!n || n == 1)
		return (1);
	while (!(n <= two))
	{
		two *= 2;
		i++;
	}
	if (n == two)
		return (i);
	else
		return (i - 1);
}
