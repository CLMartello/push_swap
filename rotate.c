/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:14:48 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/05 18:55:12 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	rotate(t_stack *a)
{
	ra(a);
	if (a->name == 'a')
		ft_putstr("ra\n");
	else if (a->name == 'b')
		ft_putstr("rb\n");
}

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	temp = a->array[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->array[i] = a->array[i + 1];
		i++;
	}
	a->array[i] = temp;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	ra(b);
	ft_putstr("rr\n");
}
