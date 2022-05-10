/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:55:22 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/10 14:35:42 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	err_atoi(int *error)
{
	write(1, "Error\n", 6);
	*error = 1;
	return (1);
}

static int	ft_is_digit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

static int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_advanced_atoi(char *str, t_list **a, int *error)
{
	long unsigned int	res;
	int					params[3];

	res = 0;
	params[0] = 1;
	params[1] = 0;
	params[2] = 0;
	if (ft_is_sign(str[params[1]]))
	{
		if (str[params[1]] == '-')
			params[0] *= -1;
		(params[1])++;
	}
	while (str[params[1]] && ++(params[2]))
	{
		if (!ft_is_digit(str[params[1]]))
			return (err_atoi(error));
		res = res * 10 + (str[params[1]] - 48);
		(params[1])++;
	}
	if (params[2] > 10 || ((res > IMAX && params[0] == 1)
			|| (res > IMIN && params[0] == -1)))
		return (err_atoi(error));
	add_elem_last(a, (int)(res * params[0]));
	return (0);
}
