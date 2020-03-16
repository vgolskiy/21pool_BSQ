/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarthas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:31:28 by tarthas           #+#    #+#             */
/*   Updated: 2020/03/16 12:41:02 by tarthas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **ft_fill(char **map, t_type result)
{
	int i;
	int j;
	
	i = result.x - result.max;
	j = result.y - result.max;
	while (i < result.x)
	{
		while (j < result.y)
		{
			*(s[i] + j) = fill;
			j++;
		}
		i++;
	}
}
