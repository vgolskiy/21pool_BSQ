/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimirgolskiy <vladimirgolskiy@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 15:21:06 by mskinner          #+#    #+#             */
/*   Updated: 2020/03/17 13:40:37 by vladimirgol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>  
#include <stdlib.h>
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

t_box	ft_get_struct(char *file_name)
{
	char	buf;
	int		fd;
	int		n;
	int		q;
	char	sym[4];
	t_box	res;

	n = 0;
	q = 0;
	fd = open(file_name, O_RDONLY);
	while ((read(fd, &buf, 1)) && (buf != 10))
	{
		if ((buf >= 48) && (buf <= 57))
			n = n * 10 + (buf - '0');
		else if ((n > 0) && (q <= 4))
			sym[q++] = buf;
	}
	if ((n != 0) && (ft_size(sym) == 3))
	{
		res.n = n;
		res.empty = sym[0];
		res.sep = sym[1];
		res.fill = sym[2];
	}
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

int		ft_map_check(char **s, int n)
{
	int i;

	i = 1;
	while (i < n - 1)
	{
		if (ft_size(s[i-1]) != ft_size(s[i]))
			return (1);
		i++;
	}
	return (0);
}

char	**ft_get_box(char ** res, char *file_name, int n)
{
	char	buf;
	int		fd;
	int		qty;
	int		rows;

	rows = 0;
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
	if (ft_map_check(res, n))
		return (0);
	res[rows - 1] = 0;
	return (res);
}

void	ft_files_in(int ac, char **av)
{
	char	**box;
	int		i;
	int		j;
	t_box	res;
	int		fd;

	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd < 0)
			write(2, "map error\n", 10);
		else
		{
			res = ft_get_struct(av[i]);
			if (res.n == 0)
				write(2, "map error\n", 10);
			else
			{
				box = (char **)malloc((res.n + 1) * sizeof(char *));
				res.box = ft_get_box(box, av[i], res.n);
				if (!res.box)
					write(2, "map error\n", 10);
				else
				{
					printf("%d", res.n);
					printf("%c", res.empty);
					printf("%c", res.sep);
					printf("%c", res.fill);
					printf("%c", '\n');
					j = 0;
					while (res.box[j])
					{
						printf("%s", res.box[j]);
						printf("%c", '\n');
						j++;
					}
				}
			}
		}
		i++;
	}
	return ;
}

int		main(int ac, char **av)
{
	ft_files_in(ac, av);
	return (0);
}
