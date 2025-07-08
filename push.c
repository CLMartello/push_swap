/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:32:29 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/06 19:50:27 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	push(t_stack *a, t_stack *b)
{
	pa(a, b);
	if (b->name == 'a')
		ft_putstr("pa\n");
	if (b->name == 'b')
		ft_putstr("pb\n");
}

static void	silent_rotate(t_stack *a)
{
	int	i;

	i = 0;
	while (i < (a->size))
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	i = b->size;
	while (i > 0)
	{
		b->array[i] = b->array[i - 1];
		i--;
	}
	b->array[0] = a->array[0];
	b->size = b->size + 1;
	a->size = a->size - 1;
	silent_rotate(a);
}
