/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:55:23 by sutku             #+#    #+#             */
/*   Updated: 2023/02/01 12:37:59 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a, t_data *data)
{
	t_stack	*first;
	t_stack	*second;
	int		value1;
	int		value2;

	if (data -> size_a > 1)
	{
		first = *stack_a;
		second = (*stack_a)-> next;
		value1 = first -> value;
		value2 = second -> value;
		first -> value = value2;
		second -> value = value1;
		data -> operations++;
	}
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b, t_data *data)
{
	t_stack	*first;
	t_stack	*second;
	int		value1;
	int		value2;

	if (data -> size_b > 1)
	{
		first = *stack_b;
		second = (*stack_b)-> next;
		value1 = first -> value;
		value2 = second -> value;
		first -> value = value2;
		second -> value = value1;
		data -> operations++;
	}
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
	t_stack	*first;
	t_stack	*second;
	int		value1;
	int		value2;

	if (data -> size_a > 1 && data -> size_b > 1)
	{
		first = *stack_a;
		second = (*stack_a)-> next;
		value1 = first -> value;
		value2 = second -> value;
		first -> value = value2;
		second -> value = value1;
		first = *stack_b;
		second = (*stack_b)-> next;
		value1 = first -> value;
		value2 = second -> value;
		first -> value = value2;
		second -> value = value1;
		data -> operations++;
	}
}
