/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_to_tab_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:22:38 by dwiegand          #+#    #+#             */
/*   Updated: 2019/04/05 17:35:01 by dwiegand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int32_t		move(t_pinfo *p, int32_t from, int32_t to)
{
	int32_t		diff;

	diff = (from > to) ? (-1) : (1);
	while (from != to)
	{
		p->tab[from] = p->tab[from + diff];
		from += diff;
	}
	return (1);
}

static int32_t		*copy_array(const int32_t *array, int32_t size, int32_t ign)
{
	int32_t		i;
	int32_t		*copy;

	i = 0;
	if (!(copy = (int32_t *)ft_memalloc(sizeof(int32_t) * size)))
		ft_error("lem-in: memory allocation error\n", 32);
	while (i < size)
	{
		if (array[i] != ign || i == 0)
			copy[i] = array[i];
		i++;
	}
	return (copy);
}

int32_t				flag1(t_tqt *q, t_pinfo *p)
{
	int32_t		*copy;

	copy = NULL;
	copy = copy_array(p->tab[p->i_cur + 1], q->n_rooms, p->value);
	move(p, p->i_last, p->i_cur);
	p->tab[p->i_cur] = copy;
	p->i_last -= 1;
	return (1);
}

int32_t				flag5(t_pinfo *p)
{
	int32_t		*copy;

	if (!p->tab[p->i_cur][1])
		p->tab[p->i_cur][1] = p->value;
	copy = p->tab[p->i_cur];
	move(p, p->i_cur, p->i_last);
	p->tab[p->i_finished] = copy;
	p->i_finished += 1;
	p->i_last += 1;
	return (1);
}

int32_t				flag6(t_pinfo *p)
{
	free(p->tab[p->i_cur]);
	move(p, p->i_cur, p->i_last);
	p->valid -= 1;
	p->i_last += 1;
	return (0);
}
