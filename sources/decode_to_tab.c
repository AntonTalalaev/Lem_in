/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:10:22 by dwiegand          #+#    #+#             */
/*   Updated: 2019/04/05 15:32:09 by dwiegand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int32_t		decode_vars(t_tqt *q, t_pinfo *p)
{
	int32_t		elem;

	elem = 0;
	while ((q->res->size(q->res)))
	{
		elem = q->res->pop(q->res);
		if (elem > 0)
		{
			(p->tab[p->i_cur][elem]) = p->value;
			p->i_cur -= 1;
		}
		else if (elem == -1)
			flag1(q, p);
		else if (elem == -4)
		{
			p->value += 1;
			p->i_cur = p->i_start;
		}
		else if (elem == -5)
			flag5(p);
		else if (elem == -6)
			flag6(p);
	}
	return (1);
}

static int32_t		starts_init(t_tqt *q, int32_t **tab)
{
	int32_t		i;
	int32_t		elem;
	int32_t		start;

	i = q->var;
	start = 0;
	elem = 0;
	while ((elem = q->res->pop(q->res)) != -4)
	{
		if (!(tab[i] = ft_memalloc(sizeof(int32_t) * q->n_rooms)))
			ft_error("lem-in: memory allocation error\n", 32);
		tab[i][elem] = 1;
		tab[i][0] = start;
		start++;
		i--;
	}
	return (i);
}

t_pinfo				*pinfo_init(int32_t var)
{
	t_pinfo		*p;

	p = NULL;
	if (!(p = (t_pinfo *)malloc(sizeof(t_pinfo))))
		ft_error("lem-in: memory allocation error\n", 32);
	p->i_start = var;
	p->i_cur = var;
	p->i_finished = 0;
	p->valid = var;
	p->value = 2;
	p->tab = NULL;
	p->i_last = 0;
	return (p);
}

int32_t				**decode_to_tab(t_tqt *q)
{
	int32_t		i;
	int32_t		**tab;
	t_pinfo		*p;

	i = 0;
	p = pinfo_init(q->var);
	if (!(tab = (int32_t **)malloc(sizeof(int32_t *) * (q->var + 1))))
		ft_error("lem-in: memory allocation error\n", 32);
	while (i < q->var + 1)
		tab[i++] = NULL;
	p->i_last = starts_init(q, tab);
	p->tab = tab;
	decode_vars(q, p);
	p->tab = NULL;
	free(p);
	p = NULL;
	return (tab);
}
