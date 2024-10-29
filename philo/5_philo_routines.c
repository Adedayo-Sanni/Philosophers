/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_philo_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:51:10 by asanni            #+#    #+#             */
/*   Updated: 2024/10/29 14:26:13 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// aqui chamar e implementar todas as ações dos filos
//essa função será o 3 parametro da thread join

void	*philos_routines(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	if (philo->data->nb_philos == 1)
		lonely_rotine(philo);
	else
	{
		while (is_satisfied(philo) == 1 && is_dead(philo) != 1)
		{
			take_fork(philo);
			philo_eat(philo);
			release_fork(philo);
			philo_sleep(philo);
			philo_thinks(philo);
		}
	}
	return (NULL);
}
