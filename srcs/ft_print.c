/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarthas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:04:53 by tarthas           #+#    #+#             */
/*   Updated: 2020/03/16 17:45:35 by tarthas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_print(char **map)
{
	while (*map)
	{
		while (**map != '\0')
		{
			write(1, (*map), 1);
			(*map)++;
		}
		write(1, "\n", 1);
		map++;
	}
	write(1, "\n", 1);
	return ;
}
