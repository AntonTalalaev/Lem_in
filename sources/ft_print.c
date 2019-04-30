/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:03:02 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:03:03 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print(t_lem *lem)
{
	int		i;

	i = 0;
	if (!(lem->flags >> 3) || lem->flags & 4)
	{
		if (!((lem->flags >> 6) & 1))
			i += ft_src_print(lem);
		if (i == 1)
			ft_putchar('\n');
		i += ft_final_print(lem);
	}
	i += ft_print_status(lem, i);
	i += ft_print_ants_struct(lem, i);
	i += ft_print_fin_ways(lem, i);
}
