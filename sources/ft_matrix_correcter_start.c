/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_correcter_start.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:05:23 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:05:25 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_matrix_correcter_start(t_lem *lem)
{
	int			i;

	ft_start_ways_cut(lem);
	i = 1;
	while (++i < lem->n_rooms)
	{
		if (lem->adj_matrix[i][0] == 1)
		{
			lem->adj_matrix[i][0] = 0;
			lem->list_of_rooms[i].n_links--;
		}
	}
}

void			ft_start_way_cut(t_lem *lem, int cur)
{
	int			next;
	int			prev;

	prev = 0;
	while (lem->list_of_rooms[cur].n_links == 2)
	{
		next = 1;
		while (next < lem->n_rooms)
		{
			if (lem->adj_matrix[cur][next] == 1 && next != prev)
			{
				if (lem->adj_matrix[next][cur] == 1)
				{
					lem->adj_matrix[next][cur] = 0;
					lem->list_of_rooms[next].n_links--;
				}
				prev = cur;
				if (next == 1)
					return ;
				cur = next;
				break ;
			}
			next++;
		}
	}
}

void			ft_start_room_cut(t_lem *lem, int cur)
{
	int			next;

	next = 2;
	while (next < lem->n_rooms)
	{
		if (lem->adj_matrix[cur][next] == 1)
		{
			if (lem->adj_matrix[0][next] == 1)
			{
				if (lem->adj_matrix[cur][next] == 1)
				{
					lem->adj_matrix[cur][next] = 0;
					lem->list_of_rooms[cur].n_links--;
				}
			}
			if (lem->adj_matrix[next][cur] == 1)
			{
				lem->adj_matrix[next][cur] = 0;
				lem->list_of_rooms[next].n_links--;
			}
		}
		next++;
	}
}

void			ft_start_ways_cut(t_lem *lem)
{
	int			i;

	i = 2;
	while (i < lem->n_rooms)
	{
		if (lem->adj_matrix[0][i] == 1)
		{
			ft_start_way_cut(lem, i);
			ft_start_room_cut(lem, i);
		}
		i++;
	}
}
