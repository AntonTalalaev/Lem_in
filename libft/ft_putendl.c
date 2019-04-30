/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:36:00 by dwiegand          #+#    #+#             */
/*   Updated: 2018/11/29 15:36:30 by dwiegand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl(char const *s)
{
	if (s != NULL)
	{
		while (*s)
			write(1, s++, 1);
		write(1, "\n", 1);
	}
}