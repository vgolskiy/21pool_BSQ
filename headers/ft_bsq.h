/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarthas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:33:52 by tarthas           #+#    #+#             */
/*   Updated: 2020/03/16 19:26:01 by tarthas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
#define FT_BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct s_type {
	int x;
	int y;
	int max;
}				t_type;

void ft_fill(char **map, t_type result, char fill);
void ft_print(char **map);
t_type ft_max(int **matrix, int row_n, int col_n);
t_type  ft_find(char **s, int row_num, int col_num, char obst);
int ft_min(int a, int b, int c);

#endif
