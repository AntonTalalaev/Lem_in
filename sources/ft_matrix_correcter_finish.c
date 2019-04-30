/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_correcter_finish.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:02:43 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:02:45 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_finish_room_cut(t_lem *lem, int cur)
{
	int		index;

	index = 2;
	while (index < lem->n_rooms)
	{
		lem->adj_matrix[cur][index] = 0;
		index++;
	}
	lem->adj_matrix[cur][0] = 0;
	lem->list_of_rooms[cur].n_links = 1;
}

void		ft_finish_rooms_cut(t_lem *lem)
{
	int		index;

	index = 2;
	while (index < lem->n_rooms)
	{
		if (lem->adj_matrix[index][1] == 1)
			ft_finish_room_cut(lem, index);
		index++;
	}
}

void		ft_matrix_correcter_finish(t_lem *lem)
{
	int		i;

	i = 0;
	while (++i < lem->n_rooms)
		lem->adj_matrix[1][i] = 0;
	lem->list_of_rooms[1].n_links = 0;
	ft_finish_rooms_cut(lem);
}
