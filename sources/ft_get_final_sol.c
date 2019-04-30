/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_final_sol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:02:13 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/05 16:48:11 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_each_way_ant_counter(t_lem *lem)
{
	int32_t		i;
	int32_t		level;
	int32_t		ants;

	level = lem->fin_sol.base_way[lem->fin_sol.n_ways - 1][1];
	ants = lem->n_ants;
	i = 0;
	while (i < lem->fin_sol.n_ways)
	{
		lem->fin_sol.base_way[i][0] = level - lem->fin_sol.base_way[i][1];
		ants -= level - lem->fin_sol.base_way[i][1];
		i++;
	}
	i = 0;
	while (i < lem->fin_sol.n_ways)
		lem->fin_sol.base_way[i++][0] += ants / lem->fin_sol.n_ways;
	i = 0;
	ants %= lem->fin_sol.n_ways;
	while (ants)
	{
		lem->fin_sol.base_way[i][0] += 1;
		ants--;
		i++;
	}
}

void		ft_base_way_creation(t_lem *lem, int n_sol, int **var)
{
	int		i;

	lem->fin_sol.base_way = NULL;
	i = 0;
	if ((lem->fin_sol.base_way = (int **)ft_memalloc(sizeof(int *) *
					lem->sol[n_sol].n_ways)) == NULL)
		ft_error("lem-in: memory allocation error\n", 32);
	while (i < lem->sol[n_sol].n_ways)
	{
		lem->fin_sol.base_way[i] = NULL;
		if ((lem->fin_sol.base_way[i] = (int *)ft_memalloc(sizeof(int) *
						(var[lem->sol[n_sol].adr[i]][1] + 3))) == NULL)
			ft_error("lem-in: memory allocation error\n", 32);
		i++;
	}
	lem->fin_sol.n_ways = lem->sol[n_sol].n_ways;
}

void		ft_final_sol_ways_restruction(t_lem *lem, int n_sol,
		int **var, int i)
{
	int		x;
	int		weight;
	int		a;

	while (i < lem->fin_sol.n_ways)
	{
		lem->fin_sol.base_way[i][1] = var[lem->sol[n_sol].adr[i]][1];
		weight = 1;
		x = 0;
		a = 2;
		while (++x < lem->n_rooms)
		{
			if (var[lem->sol[n_sol].adr[i]][x] == weight)
			{
				lem->fin_sol.base_way[i][a] = x;
				weight++;
				a++;
				if (x == 1)
					break ;
				else
					x = 0;
			}
		}
		i++;
	}
}

void		ft_final_sol_ways(t_lem *lem, int final_sol, int **var)
{
	ft_base_way_creation(lem, final_sol, var);
	ft_final_sol_ways_restruction(lem, final_sol, var, 0);
	ft_each_way_ant_counter(lem);
}

int			ft_get_final_sol(t_lem *lem, int n_sol, int **var)
{
	int		i;
	int		weight;
	int		final_sol;

	if (var[0] == NULL)
		ft_error("lem-in: no way found\n", 21);
	i = 1;
	weight = lem->sol[0].weight;
	final_sol = 0;
	while (i < n_sol)
	{
		if (weight > lem->sol[i].weight)
		{
			final_sol = i;
			weight = lem->sol[i].weight;
		}
		i++;
	}
	ft_final_sol_ways(lem, final_sol, var);
	return (final_sol);
}
