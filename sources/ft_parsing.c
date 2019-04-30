/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:02:52 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/05 16:50:28 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_src_valid_cheker() - to check valid input
** ft_input_counter() - to count rooms and ants
*/

#include "lem_in.h"

void			ft_parsing(t_lem *lem, char *filename)
{
	char		*p;

	p = ft_get_src(lem, filename);
	ft_src_valid_cheker(lem);
	ft_input_counter(lem, lem->src);
	ft_list_of_rooms_creater(lem);
	ft_adj_matrix_creater(lem);
	lem->src = p;
}

char			*ft_skip_comment(char *str)
{
	while (*str == '#' && !ft_strnstr(str, "##start", 7) &&
			!ft_strnstr(str, "##end", 5))
		str = ft_strchr(str, '\n') + 1;
	return (str);
}

void			ft_input_counter(t_lem *lem, char *p)
{
	if ((lem->n_ants = ft_atoi(lem->src)) < 1)
		ft_error("error: number of ants error.\n", 29);
	lem->n_rooms = 0;
	while ((p = ft_strchr(p, ' ')))
	{
		while (*p != '\n')
			p--;
		p++;
		if (*p == '#' || *p == 'L')
		{
			while (*p != '\n' && *p != '\0')
				p++;
			(*p == '\n') ? p++ : 0;
			continue ;
		}
		lem->n_rooms++;
		while (*p != '\n' && *p != '\0')
			p++;
	}
}

char			*ft_get_src(t_lem *lem, char *filename)
{
	char	line[1024];
	int		i;
	int		fd;
	char	*tmp;

	if ((lem->src = ft_strdup("")) == NULL)
		ft_error("lem-in: memory allocation error\n", 32);
	if (filename == NULL)
		fd = 0;
	else
	{
		if ((fd = open(filename, O_RDONLY)) == -1)
			ft_error("lem-in: invalid file descriptor.\n", 33);
	}
	while ((i = read(fd, line, 1024)) > 0)
	{
		line[i] = '\0';
		if ((tmp = ft_strjoin(lem->src, line)) == NULL)
			ft_error("lem-in: memory allocation error\n", 32);
		ft_memdel((void **)&lem->src);
		lem->src = tmp;
	}
	lem->src = ft_skip_comment(lem->src);
	return (tmp);
}
