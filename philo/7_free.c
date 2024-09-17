/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:25:24 by asanni            #+#    #+#             */
/*   Updated: 2024/09/17 20:03:31 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_dinner *dinner)
{
	if (dinner)
	{
		if (dinner->data)
		{
			free(dinner->data);
		}
		free(dinner);
	}
}

void	free_forks(t_dinner *dinner)
{
	int	i;

	if (dinner->forks)
	{
		i = 0;
		pthread_mutex_destroy(&dinner->forks[i].mutex);
		pthread_mutex_destroy(&dinner->forks[i + 1].mutex);
		free(dinner->forks);
	}
}

void	error_exit(char *msg, int status, int clean, t_dinner *dinner)
{
	printf("%s", msg);
	if (clean >= 3)
		if (dinner->data)
			free(dinner->data);
	if (clean >= 2)
		free_forks(dinner);
	if (clean >= 1)
		if (dinner->philos)
			free(dinner->philos);
	if (dinner)
		free(dinner);
	exit(status);
}

// Nível 1: Limpa os filósofos
// Nível 2: Limpa os mutexes e os garfos
// Nível 3: Limpa a estrutura de dados
