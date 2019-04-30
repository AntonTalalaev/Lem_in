/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:03:19 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:03:21 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			ft_put_space(int a)
{
	if (a < 10)
		ft_putstr("    ");
	if (a > 9 && a < 100)
		ft_putstr("   ");
	if (a > 99 && a < 1000)
		ft_putstr("  ");
	if (a > 999 && a < 10000)
		ft_putstr(" ");
}

static void			ft_put_line(void)
{
	ft_putstr("-------|----------------------------------------");
	ft_putstr("------------------------------------------------");
	ft_putstr("------------------------------------------------\n");
}

static void			ft_put_way(t_lem *lem, int a)
{
	int				x;
	int				new_line;

	x = 2;
	new_line = 0;
	while (x < lem->fin_sol.ant[a].way[1] + 2)
	{
		if (new_line > 100)
		{
			ft_putstr("\n       |  ");
			new_line = 0;
		}
		new_line +=
			ft_strlen(lem->list_of_rooms[lem->fin_sol.ant[a].way[x]].name);
		ft_putstr(lem->list_of_rooms[lem->fin_sol.ant[a].way[x]].name);
		ft_putstr(" ");
		x++;
	}
}

int					ft_print_ants_struct(t_lem *lem, int i)
{
	int				a;

	if (((lem->flags >> 5) & 1) != 1)
		return (0);
	if (i)
		ft_putchar('\n');
	a = 0;
	ft_putstr("Ants ways:\n name  |  way \n");
	ft_put_line();
	while (a < lem->n_ants)
	{
		ft_put_space(a);
		ft_putnbr(a + 1);
		ft_putstr("  |  ");
		ft_put_way(lem, a);
		ft_putchar('\n');
		ft_put_line();
		a++;
	}
	return (1);
}
