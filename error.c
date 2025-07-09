/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:39:20 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/09 21:41:58 by clumertz         ###   ########.fr       */
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
	if (size == 1)
	{
		free(a);
		exit(EXIT_FAILURE);
	}
	if ((confirm_sort(a, size)) == 1)
	{
		free(a);
		msg_error();
	}
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
				ft_free_mem(a, size);
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
//	free(a);
//	msg_error();
	return (1);
}
