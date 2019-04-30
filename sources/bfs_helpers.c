/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:44:08 by dwiegand          #+#    #+#             */
/*   Updated: 2019/04/03 19:44:09 by dwiegand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int32_t			next_start(t_matrix *rooms, int32_t from)
{
	while (from < rooms->size_y && (!(rooms->matrix[from][0])))
		from++;
	if (from == rooms->size_y)
	{
		write(1, "next_start: error\n", 18);
		return (-1);
	}
	return (from);
}

void			duopush(t_tqt *q, int32_t n)
{
	q->res->push(q->res, n);
	q->lev->push(q->lev, n);
}

int32_t			deadlock(t_tqt *q, int32_t value)
{
	q->rooms->matrix[q->index][0] -= 1;
	q->res->push(q->res, value);
	return (0);
}

int32_t			check_room(int32_t *rooms, int32_t cur, int32_t prew)
{
	if (!rooms[cur])
	{
		rooms[cur] = rooms[prew] + 1;
		return (1);
	}
	return (0);
}
