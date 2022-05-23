/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:57:21 by omoudni           #+#    #+#             */
/*   Updated: 2022/05/23 17:01:43 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>

# define IMAX 2147483647UL
# define IMIN 2147483648UL

typedef struct s_list
{
	int				value;
	int				index;
	int				rank;
	int				l_len;
	struct s_list	*next;
}				t_list;

//---parsing.c---:
int		err_atoi(int *error);
int		ft_advanced_atoi(char *str, t_list **a, int *error);

//---lst_ops.c---:
void	add_elem_last(t_list **a, int value);
int		ft_lst_len(t_list *a);
void	add_elem_top(t_list **a, int value);
void	del_elem_top(t_list **a);

//---parsing_2.c---:
int		ft_check_doubles(t_list **a);
int		ft_is_sorted(t_list **a);
void	parse(t_list **a, int argc, char **argv, int j);

//---free.c---:
void	free_ll(t_list **a);
void	free_split(char **splitted);
char	**free_split_2(char **splitted, int k);

//---sorting_ops.c---:
void	s(t_list **a, int *ins_nb);
void	r(t_list **a, int *ins_nb);
void	rr(t_list **a, int *ins_nb);
void	p(t_list **a, t_list **b, int *ins_nb, int ab);

//---sorting.c---:
void	sort_s_set(t_list **a, t_list **b, int *ins_nb);
void	sort_b_set(t_list **a, t_list **b, int *ins_nb);
void	ft_sort(t_list **a, t_list **b, int *ins_nb);

//---ranking.c---:
void	rank_ll(t_list **a);

//---sort_s_set.c---:
void	sort_3(t_list **a, t_list **b, int *ins_nb);
void	sort_4(t_list **a, t_list **b, int rank, int *ins_nb);
void	sort_5(t_list **a, t_list **b, int rank, int *ins_nb);

//---bin_manip.c:---:
int		get_bin_len(int n);

//---ft_split.c---:
char	**ft_split(char const *str, char *charset);

#endif
