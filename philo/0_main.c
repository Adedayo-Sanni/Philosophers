/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:08:43 by asanni            #+#    #+#             */
/*   Updated: 2024/08/21 17:08:43 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dinner	*dinner;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\nThe program should be run as follows:"
			"\n./philo number_of_philosophers time_to_die time_to_eat"
			" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (validate_args(argv) == 1)
		return (1);
	else
	{
		dinner = calloc(1, sizeof(t_dinner));
		if (!dinner)
			error_exit("Sorry, we are closed", 0, dinner);
		init_dinner(dinner, argv, argc);
	}
	cleanup(dinner);
	return (0);
}

//continuar playlist do codevault
// não tentar implementar várias mutex ao mesmo tempo
// faz um e testa. Rodou liso? Pode ir para outro mutex
