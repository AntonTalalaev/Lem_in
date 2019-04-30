/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:43 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:01:46 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_free_sol(t_lem *lem, int n_sol)
{
	int		i;

	i = 0;
	while (i < n_sol)
	{
		ft_memdel((void **)&lem->sol[i].adr);
		i++;
	}
	ft_memdel((void **)&lem->sol);
}

void		ft_free_list_of_rooms(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->n_rooms)
	{
		ft_memdel((void **)&lem->list_of_rooms[i].name);
		i++;
	}
	ft_memdel((void **)&lem->list_of_rooms);
}

void		ft_free_fin_sol(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->fin_sol.n_ways)
	{
		ft_memdel((void **)&lem->fin_sol.base_way[i]);
		i++;
	}
	free(lem->fin_sol.base_way);
	free(lem->fin_sol.ant);
}

void		ft_free_matrix(t_lem *lem)
{
	int		i;

	i = 0;
	while (i < lem->n_rooms)
	{
		ft_memdel((void **)&lem->adj_matrix[i]);
		i++;
	}
	free(lem->adj_matrix);
}

void		ft_free_all(t_lem *lem)
{
	ft_free_list_of_rooms(lem);
	ft_free_fin_sol(lem);
	ft_memdel((void **)&lem->src);
	ft_free_matrix(lem);
	ft_memdel((void **)&lem->z_checker);
	ft_memdel((void **)&lem->way_cheker);
}
