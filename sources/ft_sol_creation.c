/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sol_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:03:28 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:03:30 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_solution_creater(t_lem *lem)
{
	int			i;

	if ((lem->sol = (t_solution *)malloc(sizeof(t_solution)
					* (lem->n_rooms * lem->n_rooms))) == NULL)
		ft_error("lem-in: memory allocation error\n", 32);
	i = lem->n_rooms * lem->n_rooms - 1;
	while (i >= 0)
	{
		lem->sol[i].n_ways = 0;
		i--;
	}
}

int				ft_get_next_way(t_lem *lem, int **var, int n_sol, int x)
{
	int32_t		weight;

	while (var[++x] != NULL)
		if (ft_z_comparison(lem, var[x][0]))
		{
			if (ft_way_comparison(lem, var[x], lem->sol[n_sol].n_ways))
			{
				weight =
					sol_weight(lem->sol[n_sol], var, lem->n_ants, var[x][1]);
				if (weight < lem->sol[n_sol].weight)
				{
					lem->sol[n_sol].weight = weight;
					return (x);
				}
				else
				{
					ft_z_comparison_correcter(lem, var[x][0]);
					ft_way_comparison_correcter(lem, lem->sol[n_sol].n_ways);
				}
			}
			else
				ft_z_comparison_correcter(lem, var[x][0]);
		}
	return (-1);
}

int				ft_get_next_solution(t_lem *lem, int **var, int n_sol, int x)
{
	while (lem->sol[n_sol].n_ways < lem->max_num_of_way)
	{
		if ((x = ft_get_next_way(lem, var, n_sol, x - 1)) == -1)
		{
			ft_memset(lem->way_cheker, 0, lem->n_rooms);
			ft_memset(lem->z_checker, 0, lem->n_start);
			return (1);
		}
		lem->sol[n_sol].adr[lem->sol[n_sol].n_ways] = x;
		lem->sol[n_sol].n_ways++;
	}
	return (1);
}

void			ft_get_start_way(t_lem *lem, int **var, int n_sol,
		int start_way)
{
	lem->sol[n_sol].weight = var[start_way][1] + lem->n_ants - 1;
	lem->sol[n_sol].len = var[start_way][1];
	lem->sol[n_sol].adr[0] = start_way;
	ft_z_comparison(lem, var[start_way][0]);
	ft_way_comparison(lem, var[start_way], lem->sol[n_sol].n_ways);
	lem->sol[n_sol].n_ways++;
	lem->fill_cheker = (lem->n_rooms - 2) - var[start_way][1] + 1;
}

int				ft_sol_creation(t_lem *lem, int32_t **var)
{
	int			n_sol;
	int			start_way;

	n_sol = 0;
	start_way = 0;
	while (var[start_way] != NULL)
	{
		if ((lem->sol[n_sol].adr =
			(int *)malloc(sizeof(int) * lem->n_rooms * lem->n_rooms)) == NULL)
			ft_error("lem-in: memory allocation error\n", 32);
		ft_get_start_way(lem, var, n_sol, start_way);
		if (var[start_way + 1] != NULL)
			ft_get_next_solution(lem, var, n_sol, start_way + 1);
		n_sol++;
		start_way++;
	}
	return (n_sol);
}
