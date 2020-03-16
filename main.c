/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarthas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 10:17:42 by tarthas           #+#    #+#             */
/*   Updated: 2020/03/16 15:55:13 by tarthas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int main(int argc, char **argv)
{
	int **tmp;

	//Проверка argc, вычисляется col_number, проверка что все строки длинной col_num
	//Считывание map в матрицу s. В итоге char **s.
	//Считывание параметров map, в итоге obst = символ препятсвия, fill = символ заполнения.
	

	while (argc - i_arg > 0)//Здесь подставлем по очереди все map
	{
		t_type res;
		res = ft_find(s, row_num, col_num, obst);
		s = ft_fill(s, res);
		ft_print(s);
	}
return (0);
}















