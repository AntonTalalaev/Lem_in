/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way_comparison_creater.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:04:30 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:04:32 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_way_comparison_creater(t_lem *lem)
{
	if ((lem->way_cheker =
		(char *)malloc(sizeof(char) * (lem->n_rooms + 1))) == NULL)
		ft_error("lem-in: memory allocation error\n", 32);
	ft_memset(lem->way_cheker, 0, lem->n_rooms);
	if ((lem->z_checker =
		(char *)malloc(sizeof(char) * (lem->n_start + 1))) == NULL)
		ft_error("lem-in: memory allocation error\n", 32);
	ft_memset(lem->z_checker, 0, lem->n_start);
}

int			ft_z_comparison_correcter(t_lem *lem, int prev_z)
{
	lem->z_checker[prev_z] = 0;
	return (0);
}

int			ft_z_comparison(t_lem *lem, int next_z)
{
	if (lem->z_checker[next_z] == 0)
	{
		lem->z_checker[next_z] = 1;
		return (1);
	}
	else
	{
		return (0);
	}
}

int			ft_way_comparison_correcter(t_lem *lem, int n_ways)
{
	int		x;

	x = 2;
	while (x < lem->n_rooms)
	{
		if (lem->way_cheker[x] == n_ways + 1)
			lem->way_cheker[x] = 0;
		x++;
	}
	return (0);
}

int			ft_way_comparison(t_lem *lem, int *next, int n_ways)
{
	int		x;

	x = 2;
	while (x < lem->n_rooms)
	{
		if (next[x] != 0)
		{
			if (lem->way_cheker[x] == 0)
				lem->way_cheker[x] = n_ways + 1;
			else
			{
				x = -1;
				while (++x < lem->n_rooms)
					if (lem->way_cheker[x] == n_ways + 1)
						lem->way_cheker[x] = 0;
				return (0);
			}
		}
		x++;
	}
	return (1);
}
