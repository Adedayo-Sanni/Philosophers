/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_supervisor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:13 by asanni            #+#    #+#             */
/*   Updated: 2024/10/29 14:46:21 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor_routine(void *arg)
{
	t_dinner	*dinner;
	int			i;

	dinner = (t_dinner *)arg;
	while (1)
	{
		i = 0;
		while (i < dinner->data.nb_philos)
		{
			if (is_alive(&dinner->philos[i]) == 0)
			{
				pthread_mutex_lock(&dinner->data.monitor);
				dinner->data.stop = 1;
				pthread_mutex_unlock(&dinner->data.monitor);
				return (NULL);
			}
			i++;
		}
	}
}

int	is_alive(t_philo *philo)
{
	long int	diff;

	pthread_mutex_lock(&philo->update);
	diff = current_time() - philo->time_last_meal;
	pthread_mutex_unlock(&philo->update);
	if (diff >= philo->data->time_to_die)
	{
		print_msg(philo, "died");
		philo->data->philo_died = 1;
		return (0);
	}
	return (1);
}

int	is_satisfied(t_philo *philo)
{
	if (philo->meals_had == philo->data->nb_meals_todo)
		return (0);
	return (1);
}

int	is_dead(t_philo *philo)
{
	int	verif;

	pthread_mutex_lock(&philo->data->check);
	verif = philo->data->stop;
	pthread_mutex_unlock(&philo->data->check);
	return (verif);
}
