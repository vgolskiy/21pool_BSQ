/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarthas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:33:52 by tarthas           #+#    #+#             */
/*   Updated: 2020/03/16 13:27:10 by tarthas          ###   ########.fr       */
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

char **ft_fill(char **map, t_type result);
void **ft_print(char **map);
t_type ft_max(int **matrix, row_n, col_n);


#endif
