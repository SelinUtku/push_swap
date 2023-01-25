/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:01:48 by sutku             #+#    #+#             */
/*   Updated: 2023/01/25 03:09:01 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_swap(s_stack **stack)
// {
	
// }
int	check_errors(int argc, char **argv)
{
	int i;
	
	i = -1;
	while (++i < argc - 1)
	{
		if (long_atoi(argv[i]) < INT32_MIN || long_atoi(argv[i]) > INT32_MAX)
		{
			printf("Error : Not Int");
			return (-1);
		}
		if (is_integer(argv[i]) == -1)
		{
			printf("Error : there is character");
			return (-1);
		}
		if (is_duplicate_arr(argv + i) == -1)
		{
			printf("Error : Duplicate");
			return (-1);
		}
	}
	return (0);
}

void	print_result(s_stack *stack, s_data data)
{
	while (stack)
	{	
		printf("%d\n", stack-> value);
		stack = stack -> next;
	}
	printf("A_size : %d\nB_size : %d\nOperations : %d\n",data.A_size, data.B_size, data.operations);
}

int main (int argc, char **argv)
{
	s_stack	*stack_A;
	s_stack	*stack_B;
	s_data	data;
	char	**ptr;
	int		count;
	int		*index;

	index = NULL;
	stack_A = (s_stack *)malloc(sizeof(s_stack));
	stack_B = (s_stack *)malloc(sizeof(s_stack));
	count = 0;
	if (argc == 2)
	{
		ptr = ft_split(argv[1], 32);
		while (ptr[count])
			count++;
		if(check_errors(count + 1, ptr) == -1)
			return (0);
		index = find_index(count + 1, ptr);
		create_data(&data, count + 1);
		create_linklist(&stack_A, count + 1, ptr);
	}
	else if (argc > 1)
	{
		if (check_errors(argc, argv+1) == -1)
			return (0);
		index = find_index(argc, argv + 1);
		create_data(&data, argc);
		create_linklist(&stack_A, argc, argv + 1);
	}
	// count = 0;
	// while (count < argc -1)
	// 	printf("%d ", index[count++]);

	// count = -1;
	// while (++count < argc - 1)
	// 	printf("%d", index[count]);
	// push_swap(&stack_A);
	// swap_a(&stack_A, &data);
	// push_b(&stack_A, &stack_B, &data);
	// push_b(&stack_A, &stack_B, &data);
	// push_b(&stack_A, &stack_B, &data);
	// swap_ab(&stack_A, &stack_B, &data);
	// rev_rotate_a(&stack_A, &data);
	// rev_rotates_ab(&stack_A, &stack_B, &data);
	// rev_rotate_ab(&stack_A, &stack_B, &data);
	// find_max_a(stack_A, &data);
	// find_max_b(stack_B, &data);
	// print_result(stack_A, data);
	// print_result(stack_B, data);
	// if ((is_a_sorted(stack_A) == 1))
	// 	printf("A is sorted !!");
	// is_duplicate(stack_A);
	find_median(stack_A, &data, index);
	return (0);
}
// !!! Asil linklisti ilerletmek yerine her zaman kopyasini kullan !