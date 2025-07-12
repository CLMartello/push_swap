/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:19:23 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/12 17:03:57 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

int	size_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
	{
		i++;
	}
	return (i);
}

long	*array_creation(char **array, int size)
{
	long	*a;
	int		i;

	a = NULL;
	i = 0;
	a = malloc(size * sizeof(long));
	if (!a)
		return (0);
	while (i < size)
	{
		a[i] = ft_atol(array[i]);
		i++;
	}
	ft_free_mem(array, size);
	return (a);
}

static char	**parse_args(int argc, char **argv)
{
	char	**array;
	int		i;
	int		j;

	i = 1;
	j = 0;
	array = malloc((argc) * sizeof(char *));
	if (!array)
		return (NULL);
	while (i < argc)
	{
		array[j] = ft_strdup(argv[i]);
		if (!array[j])
			return (ft_free_mem(array, j));
		i++;
		j++;
	}
	array[j] = 0;
	return (array);
}

char	**parse(int argc, char **argv)
{
	char	**array;

	if (!argv[1])
		exit(EXIT_FAILURE);
	array = NULL;
	if (argc == 2)
	{
		array = ft_split(argv[1], ' ');
		if (!array)
			return (NULL);
	}
	else if (argc > 2)
	{
		array = parse_args(argc, argv);
		if (!array)
			return (NULL);
	}
	if (array[0] == 0)
	{
		ft_free_mem(array, (size_array(array)));
		msg_error();
	}
	only_digit(array, (size_array(array)));
	return (array);
}

t_stack	*initialize_stack(char name, long *array, int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = name;
	stack->array = array;
	stack->size = size;
	return (stack);
}
