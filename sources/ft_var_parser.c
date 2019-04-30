/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:04:04 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:04:05 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_fill_cheker(t_lem *lem, int len)
{
	if (lem->fill_cheker - (len - 1) < 0)
		return (0);
	lem->fill_cheker = lem->fill_cheker - len + 1;
	return (1);
}

int32_t			sol_weight(t_solution p, int32_t **var, int32_t ants,
		int32_t elem)
{
	int32_t		i;
	int32_t		weight;

	i = 0;
	while (i < p.n_ways)
	{
		ants -= elem - var[p.adr[i]][1];
		i++;
	}
	weight = elem + (ants / (p.n_ways + 1))
		+ ((!ants || (ants % (p.n_ways + 1))) ? (1) : (0)) - 1;
	return (weight);
}

void			ft_get_max_num_of_way(t_lem *lem)
{
	lem->max_num_of_way = lem->n_ants;
	if (lem->max_num_of_way > lem->n_start)
		lem->max_num_of_way = lem->n_start;
	if (lem->max_num_of_way > lem->n_finish)
		lem->max_num_of_way = lem->n_finish;
}

void			ft_var_parser(t_lem *lem, int32_t **var)
{
	int			n_sol;

	ft_get_max_num_of_way(lem);
	ft_solution_creater(lem);
	ft_way_comparison_creater(lem);
	n_sol = ft_sol_creation(lem, var);
	ft_get_final_sol(lem, n_sol, var);
	lem->status = lem->fin_sol.base_way[0][0] + lem->fin_sol.base_way[0][1] - 1;
	ft_get_arr_ant(lem);
	ft_free_sol(lem, n_sol);
}
