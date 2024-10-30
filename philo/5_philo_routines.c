/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_philo_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:51:10 by asanni            #+#    #+#             */
/*   Updated: 2024/10/30 14:55:42 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lonely_rotine(t_philo *philo)
{
	if (is_dead(philo) != 1)
	{
		print_msg(philo, "has taken a fork L");
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

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
