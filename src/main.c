/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:53:09 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/10 20:56:25 by omoudni          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**tab_argv;
	int		tab_ac;
	int		ins_nb;

	a = NULL;
	b = NULL;
	ins_nb = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			tab_argv = ft_split(argv[1], " ");
			tab_ac = get_number(tab_argv);
			parse(&a, tab_ac, tab_argv, 0);
			free_split(tab_argv);
		}
		else
			parse(&a, argc, argv, 1);
		ft_sort(&a, &b, &ins_nb);
	}
	free_ll(&a);
	free_ll(&b);
	return (0);
}
