/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant_arr_creation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:16 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:01:19 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_ant_arr_creation(t_lem *lem)
{
	int		i;

	lem->fin_sol.ant = NULL;
	if ((lem->fin_sol.ant = ft_memalloc(sizeof(t_ant) *
					(lem->n_ants))) == NULL)
		ft_error("lem-in: memory allocation error\n", 32);
	i = 0;
	while (i < lem->n_ants)
	{
		lem->fin_sol.ant[i].step = 2;
		lem->fin_sol.ant[i].way = NULL;
		i++;
	}
}

void		ft_get_arr_ant(t_lem *lem)
{
	int		i;
	int		n_ant;

	i = -1;
	while (++i < lem->fin_sol.n_ways)
		lem->fin_sol.base_way[i][lem->fin_sol.base_way[i][1] + 3] =
			lem->fin_sol.base_way[i][0];
	ft_ant_arr_creation(lem);
	n_ant = 0;
	while (n_ant < lem->n_ants)
	{
		i = 0;
		while (n_ant < lem->n_ants && i < lem->fin_sol.n_ways)
		{
			if (lem->fin_sol.base_way[i][0] != 0)
			{
				lem->fin_sol.ant[n_ant].way = lem->fin_sol.base_way[i];
				lem->fin_sol.ant[n_ant].way[0]--;
				n_ant++;
			}
			i++;
		}
	}
}
