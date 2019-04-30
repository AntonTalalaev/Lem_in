/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:02:29 by dwiegand          #+#    #+#             */
/*   Updated: 2019/04/04 17:54:50 by dwiegand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int32_t		bfs_algo2(t_lem *l, t_tqt *q, int32_t room)
{
	int32_t		i;
	int32_t		n;

	i = 0;
	n = 0;
	if ((l->list_of_rooms[room].n_links == 1
		&& (l->adj_matrix[room][1])) || room == 1)
		return (deadlock(q, -5));
	while (i < l->n_rooms)
	{
		if (l->adj_matrix[room][i])
			if ((check_room(q->rooms->matrix[q->index], i, room)))
			{
				if (n)
					duopush(q, -1);
				duopush(q, i);
				n++;
			}
		i++;
	}
	if (!n)
		return (deadlock(q, -6));
	q->var += n - 1;
	q->rooms->matrix[q->index][0] += n - 1;
	return (n);
}

static int32_t		bfs_algo(t_lem *l, t_tqt *q)
{
	q->index = 0;
	q->elem = q->lev->pop(q->lev);
	while (q->lev->size(q->lev))
	{
		bfs_algo2(l, q, q->elem);
		if (!(check_elem(q)))
			break ;
	}
	return (0);
}

static int32_t		tab_del(int32_t ***tab, int32_t y)
{
	int32_t		i;

	i = 0;
	if (tab && *tab)
	{
		while (i < y)
		{
			if (*((*tab) + i))
			{
				free(*((*tab) + i));
				*((*tab) + i) = NULL;
			}
			i++;
		}
		free(*tab);
		*tab = NULL;
		return (1);
	}
	return (0);
}

static int32_t		find_starts(t_lem *l, t_tqt *q)
{
	int32_t		i;
	int32_t		j;

	i = 0;
	j = 0;
	while (i < l->n_rooms)
	{
		if ((l->adj_matrix[0][i]))
		{
			q->rooms->matrix[j][i] = 1;
			q->rooms->matrix[j][0] = 1;
			q->var += 1;
			if (j)
				q->lev->push(q->lev, -3);
			duopush(q, i);
			j++;
		}
		i++;
	}
	duopush(q, -4);
	return (1);
}

int32_t				encode_vars(t_lem *l)
{
	int32_t		**res;
	t_tqt		s;

	s.res = queue_create(l->n_rooms * l->n_rooms);
	s.lev = queue_create(l->n_rooms * l->n_rooms);
	s.rooms = matrix_create(l->n_start, l->n_rooms);
	s.index = 0;
	s.var = 0;
	s.elem = 0;
	s.n_rooms = l->n_rooms;
	find_starts(l, &s);
	bfs_algo(l, &s);
	queue_delete(&s.lev);
	matrix_delete(&(s.rooms));
	res = decode_to_tab(&s);
	queue_delete(&s.res);
	ft_var_parser(l, res);
	tab_del(&res, s.var + 1);
	return (0);
}
