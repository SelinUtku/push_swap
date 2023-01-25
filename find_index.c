/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:45:49 by sutku             #+#    #+#             */
/*   Updated: 2023/01/25 00:29:57 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*find_index(int argc, char **argv)
{
	int	*new;
	int	i;
	int	j;
	int	small;

	i = 0;
	new = malloc(sizeof(int) * (argc - 1));
	if (!new)
		return (NULL);
	while (i < argc - 1)
		new[i++] = 0;
	i = -1;
	while (argv[++i] != NULL)
	{
		j = -1;
		small = 0;
		while (++j < i)
		{
			if (long_atoi(argv[j]) < long_atoi(argv[i]))
				small++;
			else if (long_atoi(argv[j]) > long_atoi(argv[i]))
				new[j]++;
		}
		new[i] = small;
	}
	return (new);
}
