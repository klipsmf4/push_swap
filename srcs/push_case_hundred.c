/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_case_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:31:37 by klever            #+#    #+#             */
/*   Updated: 2021/09/24 19:17:44 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	len_block(int len)
{
	if (len >= 100 && len < 500)
		return (20);
	else if (len >= 500)
		return (50);
	else if (len > 5)
		return (5);
	else if (len == 4)
		return (2);
	return (0);
}

void	push_min(t_list_n **stk_a, t_list_n **stk_b, int *sort_array_b, int ref)
{
	int	len;
	int	block;
	int	pivote_a;

	pivote_a = sort_array_b[ref];
	block = 0;
	push(stk_a, stk_b, 'a');
	len = ft_lstsize_int(*stk_a) + ft_lstsize_int(*stk_b);
	if (len >= 500)
		block = 25;
	else if (len >= 100 && len < 500)
		block = 10;
	else if (len == 4)
		block = 2;
	else if (len > 5)
		block = 3;
	if (ft_lstsize_int(*stk_b) >= 2 && (*stk_b)->content
		< sort_array_b[ref - block] && ft_lstsize_int(*stk_a) >= 2
		&& (*stk_a)->content > pivote_a)
		rotate_rr(stk_a, stk_b);
	if (ft_lstsize_int(*stk_b) >= 2 && (*stk_b)->content
		< sort_array_b[ref - block])
		rotate(stk_b, 'b');
}

void	rotate_max(t_list_n **stack_a, t_list_n **stack_b,
		int *sort_array_b, int ref)
{
	int	len;
	int	block;

	block = 0;
	len = ft_lstsize_int(*stack_a) + ft_lstsize_int(*stack_b);
	if (len >= 500)
		block = 25;
	else if (len >= 100 && len < 500)
		block = 10;
	else if (len == 4)
		block = 2;
	else if (len > 5)
		block = 3;
	if (ft_lstsize_int(*stack_b) >= 2 && (*stack_b)->content
		< sort_array_b[ref - block])
		rotate_rr(stack_a, stack_b);
	else
		rotate(stack_a, 'a');
}

void	push_hundred(t_list_n **stk_a, t_list_n **stk_b, int len, int *s_array)
{
	int	i;
	int	block_inc;
	int	pivote_a;

	block_inc = len_block(len);
	i = block_inc;
	pivote_a = s_array[i];
	while (ft_lstsize_int(*stk_a) > 0)
	{
		while (ft_lstsize_int(*stk_b) < i)
		{
			if (pivote_a > (*stk_a)->content || i == len)
				push_min(stk_a, stk_b, s_array, i);
			else
				rotate_max(stk_a, stk_b, s_array, i);
		}
		i += block_inc;
		if (i < len)
			pivote_a = s_array[i];
		else
		{
			pivote_a = s_array[len - 1];
			i = len;
		}
	}
}
