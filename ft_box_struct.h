/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 15:26:24 by mskinner          #+#    #+#             */
/*   Updated: 2020/03/16 17:22:23 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOX_STRUCT_H
# define FT_BOX_STRUCT_H

typedef struct	s_box
{
	char 		**box;
	int			n;
	char		empty;
	char		sep;
	char		fill;
}				t_box;

#endif