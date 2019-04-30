/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwiegand <dwiegand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 13:05:03 by mwunsch           #+#    #+#             */
/*   Updated: 2019/04/01 17:20:01 by mwunsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strnchr_index(const char *s, unsigned char c, int len)
{
	int		index;

	index = 0;
	while (index < len)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return (index);
		s++;
		index++;
	}
	return (-1);
}
