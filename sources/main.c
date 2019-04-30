/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:41:48 by dwiegand          #+#    #+#             */
/*   Updated: 2019/04/05 15:50:48 by dwiegand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			help(void)
{
	write(2, "usage:\t./lem-in [-f] [-swacro] source_file\n\
\t./lem-in [-swacro]\n\
\tno_flags - origin output. Print origin output in the following format: \
[number_of_ants][the_rooms][the_links] [Lx-y Lz-w Lr-o ...] \n\
\t\t(x, z, r represents the ants’ numbers (going from 1 to number_of_ants) \
and y, w, o represents the rooms’ names)\n\
\to - origin output. Force print of origin output, can be combined whith \
-sawr flags\n\
\tf - fd. Read input from the file, insted of stdin\n\
\tc - comments. Print src in origin output whith represented comments\n\
\tr - regect. Regect printing src - [number_of_ants][the_rooms][the_links],\
in origin output.\n\
\ts - status. Print number of steps needed to \
get n ants from the room ##start to the room ##end\n\
\tw - ways. Print ants ways in following format: \
[num of ants][length of the way][rooms names]\n\
\ta - ants. Print each ant and its way in following format: \
[ants name][rooms names]\n", 884);
	exit(1);
}

static int32_t		read_flag(char *arg)
{
	int32_t		i;
	int32_t		j;
	char		*pos;

	i = 0;
	j = 0;
	if (!(ft_strcmp(arg, "-help")))
	{
		help();
	}
	while (arg[i])
	{
		pos = ft_strchr(FLAGS, arg[i]);
		if (!(pos))
			ft_error("lem-in: bad params.\nUse ./lem-in --help for more \
info.\n", 55);
		j |= 0x01 << (int32_t)(pos - FLAGS);
		i++;
	}
	return (j);
}

static int32_t		check_flags(t_lem *l, int32_t av, char **ac)
{
	int32_t		i;

	i = 1;
	while (i < av && ac[i][0] == '-')
	{
		l->flags |= read_flag((*(ac + i) + 1));
		i++;
	}
	if (((l->flags & 0x01) && i != av - 1) || (!(l->flags & 0x01) && i != av))
		ft_error("lem-in: bad params.\nUse ./lem-in --help for more info.\n",
				55);
	return (0);
}

int32_t				main(int32_t av, char **ac)
{
	t_lem		lem;

	lem.flags = 0;
	if (av != 1)
	{
		check_flags(&lem, av, ac);
	}
	if ((lem.flags & 0x01))
	{
		ft_parsing(&lem, ac[av - 1]);
	}
	else
	{
		ft_parsing(&lem, NULL);
	}
	ft_matrix_correcter(&lem);
	encode_vars(&lem);
	ft_print(&lem);
	ft_free_all(&lem);
	return (0);
}
