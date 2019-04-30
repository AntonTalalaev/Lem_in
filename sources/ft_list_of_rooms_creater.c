/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_of_rooms_creater.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:01:54 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:01:58 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_add_room(t_lem *lem, char *line, int index)
{
	int			i;

	i = 0;
	while (line[i] != ' ')
		i++;
	if ((lem->list_of_rooms[index].name = ft_strnew(i)) == NULL)
		ft_error("lem-in: memory allocation error\n", 32);
	ft_strncpy(lem->list_of_rooms[index].name, line, i);
	lem->list_of_rooms[index].x = ft_atoi(&line[++i]);
	while (ft_isdigit(line[i]))
		i++;
	lem->list_of_rooms[index].y = ft_atoi(&line[i]);
	while (line[i] != '\n')
		i++;
	lem->list_of_rooms[index].n_links = 0;
	return (i + 1);
}

int				ft_add_start_end_room(t_lem *lem, char *p)
{
	int			index;
	int			a;

	a = 0;
	index = -1;
	if (ft_strncmp(p, "##end", 5) == 0)
	{
		index = 1;
	}
	else
	{
		if (ft_strncmp(p, "##start", 7) == 0)
			index = 0;
	}
	while (p[a] != '\n')
		a++;
	a++;
	if (index == -1)
		return (a);
	return (ft_add_room(lem, &p[a], index) + a);
}

void			ft_list_of_rooms_creater_rooms_adder(t_lem *lem, int index,
		int a, char *p)
{
	while (*p != '\0')
	{
		if (*p == '#' || *p == 'L')
		{
			if (*p == '#' && *(p + 1) == '#')
			{
				p += ft_add_start_end_room(lem, p);
				continue ;
			}
			while (*p != '\n' && *p != '\0')
				p++;
			(*p == '\n') ? p++ : 0;
		}
		else
		{
			a = -1;
			while (p[++a] != ' ')
				if (p[a] == '\n' || p[a] == '\0')
					return ;
			p += ft_add_room(lem, p, index++);
		}
	}
}

void			ft_list_of_rooms_creater(t_lem *lem)
{
	int			index;
	int			a;
	char		*p;

	a = 0;
	if ((lem->list_of_rooms = (t_room_name *)malloc(sizeof(t_room_name) *
					lem->n_rooms)) == NULL)
		ft_error("lem-in: memory allocation error\n", 32);
	p = ft_strchr(lem->src, '\n') + 1;
	index = 2;
	ft_list_of_rooms_creater_rooms_adder(lem, index, a, p);
}
