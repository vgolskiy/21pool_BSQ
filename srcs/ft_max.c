/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarthas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:46:25 by tarthas           #+#    #+#             */
/*   Updated: 2020/03/16 16:44:52 by tarthas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

t_type	ft_max(int **matrix, int row_n, int col_n)
{
	int		i;
	int		j;
	t_type	res;
	
	i = 0;
	j = 0;
	res.x = 0;
	res.y = 0;
	res.max = 0;
	while (i < row_n)
	{
		while (j < col_n)
		{
			if (res.max < *(matrix[i] + j))
			{
				res.max = *(matrix[i] + j);
				res.x = i;
				res.y = j;
			}
			j++;
		}
		i++;
	}
	return (res);
}
