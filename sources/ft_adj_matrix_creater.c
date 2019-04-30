/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adj_matrix_creater.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:07 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:01:10 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_find_name_index(char *name, t_lem *lem)
{
	int			index;
	int			i;

	i = 0;
	index = 0;
	while (index < lem->n_rooms)
	{
		i = 0;
		while (name[i] && name[i] == lem->list_of_rooms[index].name[i])
			i++;
		if ((name[i] == '-' || name[i] == '\n' || name[i] == '\0')
				&& lem->list_of_rooms[index].name[i] == '\0')
			return (index);
		index++;
	}
	return (-1);
}

void			ft_add_link(t_lem *lem, char *line)
{
	int			x;
	int			y;

	if ((x = ft_find_name_index(line, lem)) == -1)
		ft_error("lem-in: index name was not found.\n", 34);
	while (*line != '-')
	{
		if (*line == ' ' || *line == '\n' || *line == '\0')
			ft_error("lem-in: links format error.\n", 28);
		line++;
	}
	line++;
	if ((y = ft_find_name_index(line, lem)) == -1)
		ft_error("lem-in: index name was not found.\n", 34);
	lem->adj_matrix[x][y] = 1;
	lem->adj_matrix[y][x] = 1;
	lem->list_of_rooms[x].n_links++;
	lem->list_of_rooms[y].n_links++;
}

void			ft_adj_matrix_creater(t_lem *lem)
{
	char		*p;

	if ((lem->adj_matrix = ft_matrix(lem->n_rooms, lem->n_rooms, 0)) == NULL)
		ft_error("lem-in: memory allocation error\n", 32);
	p = lem->src;
	while (*p == '#')
		p = (ft_strchr(p, '\n') + 1);
	while ((p = ft_strchr(p, '-')))
	{
		while (*p != '\n')
			p--;
		if (*(++p) == '#')
			while (*p != '\n' && *p != '\0')
				p++;
		else
		{
			ft_add_link(lem, p);
			while (*p != '\n' && *p != '\0')
				p++;
		}
	}
}
