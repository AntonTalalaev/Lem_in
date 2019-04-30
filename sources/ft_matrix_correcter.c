/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_correcter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:02:33 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:02:35 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_cut_lists(t_lem *lem)
{
	int		x;
	int		a;
	int		index;

	index = 2;
	while (index < lem->n_rooms)
	{
		a = index;
		while (lem->list_of_rooms[a].n_links == 1)
			if (a != 0 && a != 1)
			{
				if ((x = ft_strnchr_index(lem->adj_matrix[a], 1, lem->n_rooms))
						== -1)
					ft_error("lem-in: index not found\n", 24);
				lem->adj_matrix[a][x] = 0;
				lem->list_of_rooms[a].n_links = 0;
				if (lem->adj_matrix[x][a] == 1)
				{
					lem->adj_matrix[x][a] = 0;
					lem->list_of_rooms[x].n_links--;
				}
				a = x;
			}
		index++;
	}
}

void		ft_cut_cycles(t_lem *lem)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < lem->n_rooms)
	{
		if (lem->adj_matrix[y][x] == 1)
		{
			lem->adj_matrix[y][x] = 0;
			lem->list_of_rooms[y].n_links--;
		}
		x++;
		y++;
	}
}

void		ft_start_finish_counter(t_lem *lem)
{
	int		x;

	lem->n_start = 0;
	lem->n_finish = 0;
	x = 0;
	while (x < lem->n_rooms)
	{
		if (lem->adj_matrix[0][x] == 1)
			lem->n_start++;
		if (lem->adj_matrix[1][x] == 1)
			lem->n_finish++;
		x++;
	}
	if (lem->n_start == 0)
		ft_error("lem-in: no links with start room.\n", 34);
	if (lem->n_finish == 0)
		ft_error("lem-in: no links with end room.\n", 32);
}

void		ft_matrix_correcter(t_lem *lem)
{
	ft_cut_cycles(lem);
	ft_cut_lists(lem);
	ft_start_finish_counter(lem);
	ft_matrix_correcter_finish(lem);
	ft_matrix_correcter_start(lem);
}
