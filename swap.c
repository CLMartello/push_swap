/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:30:03 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/05 18:50:25 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

void	swap(t_stack *a)
{
	sa(a);
	if (a->name == 'a')
		ft_putstr("sa\n");
	else if (a->name == 'b')
		ft_putstr("sb\n");
}

void	sa(t_stack *a)
{
	int	temp;

	temp = a->array[0];
	a->array[0] = a->array[1];
	a->array[1] = temp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sa(b);
	ft_putstr("ss\n");
}
