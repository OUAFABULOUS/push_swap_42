/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:53:09 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/23 16:39:37 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_number(char **argv)
{
	int	ac;

	ac = 0;
	if (!argv)
		return (0);
	while (argv[ac])
		ac++;
	return (ac);
}

static void	init_param(t_list **a, t_list **b, int *ins_nb)
{
	*a = NULL;
	*b = NULL;
	*ins_nb = 0;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**tab_argv;
	int		tab_ac;
	int		ins_nb;

	init_param(&a, &b, &ins_nb);
	if (argc > 1)
	{
		if (argc == 2)
		{
			tab_argv = ft_split(argv[1], " ");
			tab_ac = get_number(tab_argv);
			if (tab_ac)
				parse(&a, tab_ac, tab_argv, 0);
			free_split(tab_argv);
		}
		else
			parse(&a, argc, argv, 1);
		if (!(argc == 2 && !tab_ac))
			ft_sort(&a, &b, &ins_nb);
	}
	free_ll(&a);
	free_ll(&b);
	return (0);
}
