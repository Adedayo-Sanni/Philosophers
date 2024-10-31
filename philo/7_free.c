/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:25:24 by asanni            #+#    #+#             */
/*   Updated: 2024/10/31 12:29:56 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_philos(t_dinner *dinner)
{
	int	i;

	i = dinner->data.nb_philos - 1;
	while (i >= 0)
	{
		pthread_mutex_destroy(&dinner->philos[i].update);
		i--;
	}
	pthread_mutex_destroy(&dinner->philos->eat);
	free(dinner->philos);
	dinner->philos = NULL;
}

void	free_forks(t_dinner *dinner)
{
	int	i;

	i = dinner->data.nb_philos;
	while (i != 0)
	{
		i--;
		pthread_mutex_destroy(&dinner->forks[i]);
	}
	free(dinner->forks);
	pthread_mutex_destroy(&dinner->data.check);
	pthread_mutex_destroy(&dinner->data.monitor);
	pthread_mutex_destroy(&dinner->data.message);
}

void	error_exit(char *msg, int clean, t_dinner *dinner)
{
	printf("%s", msg);
	if (clean >= 2)
		free_forks(dinner);
	if (clean >= 1)
		if (dinner->philos)
			free(dinner->philos);
	if (dinner)
		free(dinner);
	return ;
}

// Nível 1: Limpa os filósofos
// Nível 2: Limpa os mutexes e os garfos
// Nível 3: Limpa a estrutura de dados
