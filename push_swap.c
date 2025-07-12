/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 20:33:30 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/12 16:19:38 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

int	main(int argc, char *argv[])
{
	char	**array;
	long	*i_array;
	int		size;
	t_stack	*a;
	t_stack	*b;

	array = parse(argc, argv);
	size = size_array(array);
	i_array = array_creation(array, size);
	error(i_array, size);
	size_and_sort(i_array, size);
	a = initialize_stack('a', i_array, size);
	i_array = malloc(size * sizeof(long));
	if (!i_array)
		return (0);
	b = initialize_stack('b', i_array, 0);
	if (a->size > 2)
		move(a, b);
	else
		swap(a);
	free(a->array);
	free(b->array);
	free(a);
	free(b);
	return (0);
}
