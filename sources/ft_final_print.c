/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:33 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:01:36 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_ant(t_lem *lem, int n_ant, int step)
{
	ft_putchar('L');
	ft_putnbr(n_ant + 1);
	ft_putchar('-');
	ft_putstr(lem->list_of_rooms[lem->fin_sol.ant[n_ant].way[step]].name);
	if (lem->fin_sol.ant[n_ant].way[step] == 1)
		lem->fin_sol.ant[n_ant].step = -1;
	else
		lem->fin_sol.ant[n_ant].step++;
}

void		ft_print_ants(t_lem *lem, int start, int end)
{
	int		n_ant;

	n_ant = start;
	while (n_ant < end)
	{
		if (lem->fin_sol.ant[n_ant].step != -1)
		{
			ft_print_ant(lem, n_ant, lem->fin_sol.ant[n_ant].step);
			ft_putchar(' ');
		}
		n_ant++;
	}
}

int			ft_get_next_ants(t_lem *lem, int end)
{
	int		i;

	i = 1;
	if (end >= lem->n_ants)
		return (lem->n_ants);
	while (i < lem->fin_sol.n_ways && (i + end) < lem->n_ants)
	{
		if (lem->fin_sol.ant[i + end].way[2] == lem->fin_sol.ant[end].way[2])
			return (i + end);
		i++;
	}
	if (i + end >= lem->n_ants)
		return (lem->n_ants);
	return (i + end);
}

int			ft_final_print(t_lem *lem)
{
	int		start;
	int		end;
	int		i;

	i = lem->status;
	lem->status = -1;
	start = 0;
	end = lem->fin_sol.n_ways;
	while (start != end)
	{
		lem->status++;
		while (start != end && lem->fin_sol.ant[start].step == -1)
			start++;
		ft_print_ants(lem, start, end);
		end = ft_get_next_ants(lem, end);
		if (--i)
			ft_putchar('\n');
	}
	return (1);
}

int			ft_src_print(t_lem *lem)
{
	char	*p;
	int		i;

	if (lem->flags & 2)
		ft_putstr(lem->src);
	else
	{
		p = lem->src;
		while (*p != '\0')
		{
			p = ft_skip_comment(p);
			i = 0;
			while (p[i] != '\n' && p[i] != '\0')
				i++;
			if (p[i] != '\0')
				write(1, p, i + 1);
			else
			{
				write(1, p, i);
				return (1);
			}
			p += (i + 1);
		}
	}
	return (1);
}
