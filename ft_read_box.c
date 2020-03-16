/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <mskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 15:21:06 by mskinner          #+#    #+#             */
/*   Updated: 2020/03/16 22:33:47 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
#include <stdlib.h>
#include <errno.h>
#include "ft_box_struct.h"
#include <unistd.h>
#include <stdio.h>

int		ft_size(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_error(char *file_name, int n)
{
	write(1, file_name, ft_size(file_name));
	if (n == 13)
		write(2, ": Permission denied\n", 20);
	if (n == 21)
		write(2, ": Is a directory\n", 17);
	else if (n == 2)
		write(2, ": No such file or directory\n", 28);
	return ;
}

t_box	ft_get_struct(char *file_name)
{
	char	buf;
	int		fd;
	int		n;
	int		q;
	char	sym[3];
	t_box	res;

	n = 0;
	q = 0;
	fd = open(file_name, O_RDONLY);
	while ((read(fd, &buf, 1)) && (buf != 10))
	{
		if ((buf >= 48) && (buf <= 57))
			n = n * 10 + (buf - '0');
		else if (n > 0)
			sym[q++] = buf;
	}
	res.n = n;
	res.empty = sym[0];
	res.sep = sym[1];
	res.fill = sym[2];	
	return (res);
}

char	*ft_strcpy(char *orig, char buf, int qty)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc((qty + 1) * sizeof(char));
	while (orig[i] != '\0')
	{
		res[i] = orig[i];
		i++;
	}
	res[i++] = buf;
	res[i] = '\0';
	free(orig);
	return (res);
}

char	**ft_get_box(char *file_name, int n)
{
	char	buf;
	int		fd;
	int		qty;
	int		rows;
	char	**res;

	rows = 0;
	res = (char **)malloc((n + 1) * sizeof(char *));
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1) && (rows <= n + 1))
	{
		if (buf == 10)
		{
			rows++;
			res[rows - 1] = (char *)malloc(1 * sizeof(char));
			qty = 1;
			continue ;
		}
		if (rows > 0)
			res[rows - 1] = ft_strcpy(res[rows - 1], buf, qty++);
	}
	if ((rows < n) || (rows > n + 1))
		return (0);
	res[rows - 1] = 0;
	return (res);
}

int		main(int ac, char **av)
{
	char	**box;
	int		i;
	t_box	res;


	i = 0;
	res = ft_get_struct(av[1]);
	printf("%d", res.n);
	printf("%c", res.empty);
	printf("%c", res.sep);
	printf("%c", res.fill);
	printf("%c", '\n');	
	res.box = ft_get_box(av[1], res.n);
	while (res.box[i])
	{
		printf("%s", res.box[i]);
		printf("%c", '\n');
		i++;
	}
	return (0);
}