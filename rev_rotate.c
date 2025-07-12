/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:26:37 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/12 16:37:50 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	rev_rotate(t_stack *a)
{
	rra(a);
	if (a->name == 'a')
		write(1, "rra\n", 4);
	else if (a->name == 'b')
		write(1, "rrb\n", 4);
}

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	i = a->size - 1;
	temp = a->array[i];
	while (i > 0)
	{
		a->array[i] = a->array[i - 1];
		i--;
	}
	a->array[0] = temp;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rra(b);
}

void	rrr_print(t_stack *a, t_stack *b)
{
	rrr(a, b);
	write(1, "rrr\n", 4);
}
