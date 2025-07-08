/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:39:20 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/08 18:54:15 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	msg_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	error(long *a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (a[i] > INT_MAX || a[i] < INT_MIN)
		{
			free(a);
			msg_error();
		}
		i++;
	}
	duplicate(a, size);
	confirm_sort(a, size);
}

void	duplicate(long *a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] == a[j])
			{
				free(a);
				msg_error();
			}
			j++;
		}
		i++;
	}
}

void	only_digit(char **a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (a[i][j] != '\0')
		{
			if ((a[i][j] == '-' || a[i][j] == '+') && j == 0)
				j++;
			if (a[i][j] >= '0' && a[i][j] <= '9')
			{
				while (a[i][j] >= '0' && a[i][j] <= '9')
					j++;
			}
			else
			{
				free(a);
				msg_error();
			}
		}
		i++;
	}
}

int	confirm_sort(long *a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	free(a);
	msg_error();
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int a[] = {0, 1, 2, -3, 4, 5};
	int size = sizeof(a) / 4;
	int i = 0;

	printf("%d\n", confirm_sort(a, size));
}*/
