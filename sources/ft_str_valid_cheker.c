/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_valid_cheker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:03:37 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:03:39 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_src_valid_cheker() - to check valid input
** ft_input_counter() - to count rooms and ants
*/

#include "lem_in.h"

void			ft_link_format_cheker(char *p)
{
	int			i;

	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == '#')
			while (p[i] != '\n' && p[i] != '\0')
				i++;
		if (p[i] == ' ')
			ft_error("lem-in: link format error.\n", 27);
		i++;
	}
}

char			*ft_src_valid_cheker_tool(t_lem *lem)
{
	char		*p;

	ft_start_end_num_cheker(lem);
	if (*(p = lem->src) == '\n')
		ft_error("lem-in: extra line error.\n", 26);
	while (ft_isdigit(*p))
		p++;
	if (*p != '\n')
		ft_error("lem-in: num of ants is in wrong format.\n", 40);
	++p;
	while (*p == '#')
		p = ft_strchr(p, '\n') + 1;
	ft_first_room_line_cheker(p);
	return (p);
}

int				ft_check_if_first_link_line(char *a)
{
	while (*a != '\n' && *a != '\0')
	{
		if (*a == ' ')
			return (0);
		a++;
	}
	if (*a == '\n' || *a == '\0')
		return (1);
	ft_error("lem-in: ft_check_if_first_link_line error, need to check *a.\n",
			61);
	return (-1);
}

char			*ft_src_room_format_cheker(char *p)
{
	while (*p != ' ')
	{
		if (*p == '\n' || *p == '\0')
			ft_error("lem-in: room format error.\n", 27);
		p++;
	}
	if (!ft_isdigit(*(++p)))
		ft_error("lem-in: room format error.\n", 27);
	while (ft_isdigit(*p))
		p++;
	if (*p != ' ')
		ft_error("lem-in: room format error.\n", 27);
	if (!ft_isdigit(*(++p)))
		ft_error("lem-in: room format error.\n", 27);
	while (ft_isdigit(*p))
		p++;
	if (*p != '\n')
		ft_error("lem-in: room format error.\n", 27);
	return (p);
}

void			ft_src_valid_cheker(t_lem *lem)
{
	char		*p;

	p = ft_src_valid_cheker_tool(lem);
	while (*p != '\0')
	{
		if (ft_check_if_first_link_line(p) == 1)
			break ;
		p = ft_src_room_format_cheker(p);
		p++;
		while (*p == '#')
			p = ft_strchr(p, '\n') + 1;
	}
	if (*p == '\0')
		ft_error("lem-in: links error.\n", 21);
	ft_link_format_cheker(p);
}
