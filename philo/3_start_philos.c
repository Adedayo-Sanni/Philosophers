/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_start_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:29:49 by asanni            #+#    #+#             */
/*   Updated: 2024/10/28 14:36:03 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philos(t_dinner *dinner)
{
	int	i;

	i = 0;
	dinner->data.start_time = current_time();
	while (i < dinner->data.nb_philos)
	{
		if (pthread_create(&dinner->philos[i].self_thread, NULL,
				philos_routines, &dinner->philos[i]) != 0)
		{
			error_exit("The guests could not come", PHILO, dinner);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < dinner->data.nb_philos)
	{
		if (pthread_join(dinner->philos[i].self_thread, NULL) != 0)
		{
			error_exit("The guests wont leave", PHILO, dinner);
			return ;
		}
		i++;
	}
}

int	is_alive(t_philo *philo)
{
	long int	diff;

	diff = current_time() - philo->time_last_meal;
	if (diff >= philo->data->time_to_die)
	{
		print_msg(current_time() - philo->data->start_time, philo, "died");
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

	pthread_mutex_lock(&philo->data->monitor);
	verif = philo->data->philo_died;
	pthread_mutex_unlock(&philo->data->monitor);
	print_msg(current_time() - philo->data->start_time, philo, "died");
	return (verif);
}
