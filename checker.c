/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:16:39 by clumertz          #+#    #+#             */
/*   Updated: 2025/07/12 19:25:41 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_ps.h"

static void	error_free(t_stack *a, t_stack *b, char *cmd)
{
	write(1, "Error\n", 6);
	free(cmd);
	free(a->array);
	free(b->array);
	free(a);
	free(b);
	exit(EXIT_SUCCESS);
}

void	verify_size(t_stack *a, t_stack *b)
{
	char	*cmd;

	if (a->size == 1)
	{
		cmd = get_next_line(1);
		if (cmd == NULL)
		{
			write(1, "OK\n", 3);
			free(cmd);
		}
		else
			error_free(a, b, cmd);
	}
}

void	do_operations(t_stack *a, t_stack *b, char *cmd)
{
	if ((ft_strcmp(cmd, "sa\n")) == 0)
		sa(a);
	else if ((ft_strcmp(cmd, "sb\n")) == 0)
		sa(b);
	else if ((ft_strcmp(cmd, "ss\n")) == 0)
		ss(a, b);
	else if ((ft_strcmp(cmd, "pa\n")) == 0)
		pa(b, a);
	else if ((ft_strcmp(cmd, "pb\n")) == 0)
		pa(a, b);
	else if ((ft_strcmp(cmd, "ra\n")) == 0)
		ra(a);
	else if ((ft_strcmp(cmd, "rb\n")) == 0)
		ra(b);
	else if ((ft_strcmp(cmd, "rr\n")) == 0)
		rr(a, b);
	else if ((ft_strcmp(cmd, "rra\n")) == 0)
		rra(a);
	else if ((ft_strcmp(cmd, "rrb\n")) == 0)
		rra(b);
	else if ((ft_strcmp(cmd, "rrr\n")) == 0)
		rrr(a, b);
	else
		error_free(a, b, cmd);
}

void	get_commands(t_stack *a, t_stack *b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		do_operations(a, b, cmd);
		free(cmd);
	}
	if ((confirm_sort(a->array, a->size)) == 1)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

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
	a = initialize_stack('a', i_array, size);
	i_array = malloc(size * sizeof(long));
	if (!i_array)
		return (0);
	b = initialize_stack('b', i_array, 0);
	get_commands(a, b);
	free(a->array);
	free(b->array);
	free(a);
	free(b);
	return (0);
}
