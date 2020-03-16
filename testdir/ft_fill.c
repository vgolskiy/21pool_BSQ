/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarthas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:31:28 by tarthas           #+#    #+#             */
/*   Updated: 2020/03/16 19:07:31 by tarthas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_bsq.h"

char	**ft_fill(char **s, t_type result, char fill)
{
	int		i;
	int		j;

	i = result.x;
	//j = result.y;
	while (i > result.x - result.max)
	{
		j = result.y;
		while (j > result.y - result.max)
		{
			*(s[i] + j) = fill;
			char c = *(s[i] + j);
			//c = 'o';
			printf("%d %d\n", i, j);
			printf("%s\n", s[i] + j);
			write(1, &c, 1);
			write(1, "\n", 1);
			j--;
		}
		i--;
	}
	return (s);
}
