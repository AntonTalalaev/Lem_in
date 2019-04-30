/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:44:13 by dwiegand          #+#    #+#             */
/*   Updated: 2019/04/04 17:55:05 by dwiegand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int32_t		push_flag(t_tqt *q, int32_t flag)
{
	if (flag == -3)
		q->lev->push(q->lev, -3);
	else if (flag != -1)
		duopush(q, flag);
	else
		q->lev->push(q->lev, -2);
	return (1);
}

static int32_t		perform_flag(t_tqt *q, int32_t flag)
{
	if (flag == -3)
		q->index = next_start(q->rooms, q->index + 1);
	else if (flag == -4)
		q->index = next_start(q->rooms, 0);
	return (1);
}

static int32_t		swap_flags(int32_t cur, int32_t next)
{
	if (cur < next)
		return (cur);
	else
		return (next);
}

int32_t				check_elem(t_tqt *q)
{
	int32_t		cur;
	int32_t		next;

	cur = q->lev->pop(q->lev);
	while (cur < 1)
	{
		if ((cur == -4 && !(q->lev->size(q->lev))))
		{
			q->res->push(q->res, -4);
			return (0);
		}
		next = q->lev->pop(q->lev);
		if (next > 0)
		{
			perform_flag(q, cur);
			push_flag(q, cur);
			cur = next;
		}
		else
			cur = swap_flags(cur, next);
	}
	q->elem = cur;
	return (1);
}
