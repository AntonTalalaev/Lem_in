/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag_s_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:04:54 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/04 19:04:57 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_print_status(t_lem *lem, int i)
{
	if ((lem->flags >> 3) & 1)
	{
		if (i)
			ft_putchar('\n');
		ft_putnbr(lem->status);
		ft_putchar('\n');
		return (1);
	}
	return (0);
}
