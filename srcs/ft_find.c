/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarthas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:49:07 by tarthas           #+#    #+#             */
/*   Updated: 2020/03/16 14:56:18 by tarthas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"


int ft_find(char **s, int row_num, int col_num, char obst, char fill)
{
	int **tmp;
	int i_row;
	int i_col;

	i_col = 0;
	i_row = 0;
	tmp = (int**)malloc(row_num * sizeof(int*));
	while (i_row < row_num)
	{
		*tmp[i_row] = (int*)malloc(sizeof(int) * col_num);
		if (*s[i_row] == obst)
			*tmp[i_row] = 0;
		*tmp[i_row] = 1;
		i_row++;
	}

	//Присваиваем 1 столбец исходной карты промежуточному массиву(надо ли если исходный массив 1 стр?)
	//i_row = 0;
	//Эту часть засунул в прерыдущий цикл, для экономии CPU
	/*while (i_row < n)
	{
		if (*s[i_row] == obst)
			*tmp[i_row] = 0;
		*tmp[i_row] = 1;
		i_row++;
	}*/

	//Присваиваем 1 строку исходной карты промежуточному массиву(надо ли если исходный массив 1 стр? Или 1 столбец?)
	while (i_col < col_num)
	{
		if (*(s[0] + i_col) == obst)
			*(tmp[0] + i_col) = 0;
		*(tmp[0] + i_col) = 1;
		i_col++;
	}
	//Заполняем промежуточный массив значениями "уголков"
	i_row = 1;
	i_col = 1;
	while (i_row < n)
	{
		while (i_col < col_num)
		{
			if (*(s[i_row] + i_col) != obst)
			{
				*(tmp[i_row] + i_col) = min(*(tmp[i_row] + i_col - 1), *(tmp[i_row - 1] + i_col), *(tmp[i_row - 1] + i_col - 1)) + 1;
			}
			else
				*(tmp[i_row] + i_col) = 0;
			i_col++;
		}
		i_row++;
	}
	//Посик максимального значения во временной матрице
	t_type result;
	result = ft_max(tmp, n, col_num);
}
