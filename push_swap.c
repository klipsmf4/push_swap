/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:06:03 by kbarahon          #+#    #+#             */
/*   Updated: 2021/09/24 18:49:48 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_list_n **stack_a, t_list_n **stack_b)
{
	int	len;
	int	*s_array;

	s_array = NULL;
	len = ft_lstsize_int(*stack_a);
	if (!check_a(*stack_a, len))
	{	
		if (len == 2)
			if ((*stack_a)->content > (*stack_a)->next->content)
				swap_stack(*stack_a, 'a');
		if (len == 3)
			push_swap_case_three(stack_a);
		else if (len == 5)
			push_swap_case_five(stack_a, stack_b);
		else if (len == 4)
			push_swap_case_four(stack_a, stack_b);
		else if (len > 5)
		{
			s_array = fill_array_int(*stack_a);
			ft_sort_array(s_array, ft_lstsize_int(*stack_a));
			push_hundred(stack_a, stack_b, len, s_array);
			push_stack_a(stack_a, stack_b);
			free(s_array);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_list_n	*stack_a;
	t_list_n	*stack_b;
	char		**split_argument;
	int			i;
	int			j;

	i = 1;
	j = 0;
	split_argument = NULL;
	while (i < argc)
	{
		j = 0;
		split_argument = check_number_argv(argv[i]);
		if (fill_stack(&stack_a, split_argument))
			print_error();
		while (split_argument[j])
			free(split_argument[j++]);
		free(split_argument);
		i++;
	}
	if (argc > 1)
		push_swap(&stack_a, &stack_b);
	return (0);
}
