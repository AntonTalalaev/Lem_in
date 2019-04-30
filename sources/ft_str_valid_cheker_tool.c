/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_valid_cheker_tool.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:03:47 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/05 17:11:50 by dwiegand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_first_room_line_cheker(char *p)
{
	char		*a;

	a = p;
	while (*a != '\n')
	{
		if (*a == ' ')
			break ;
		a++;
	}
	if (*a == '\n')
		ft_error("lem-in: room format error.\n", 27);
}

void			ft_start_end_num_cheker(t_lem *lem)
{
	char		*p;

	p = lem->src;
	if (ft_strnstr(p, "##start", 7) || ft_strnstr(p, "##end", 5))
		ft_error("lem-in: num of ants error.\n", 27);
	if ((p = ft_strstr(p, "\n##start")) == NULL)
		ft_error("lem-in: start room error.\n", 26);
	p++;
	if ((p = ft_strstr(p, "\n##start")) != NULL)
		ft_error("lem-in: start room error.\n", 26);
	p = lem->src;
	if ((p = ft_strstr(p, "\n##end")) == NULL)
		ft_error("lem-in: end room error.\n", 24);
	p++;
	if ((p = ft_strstr(p, "\n##end")) != NULL)
		ft_error("lem-in: end room error.\n", 24);
}
