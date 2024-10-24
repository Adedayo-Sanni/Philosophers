/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_philo_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:29:59 by asanni            #+#    #+#             */
/*   Updated: 2024/10/24 17:30:02 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
	{
		print_msg(current_time() - philo->data->start_time, philo,
			"has taken a fork L");
		pthread_mutex_lock(philo->left_fork);
		print_msg(current_time() - philo->data->start_time, philo,
			"has taken a fork R");
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		print_msg(current_time() - philo->data->start_time, philo,
			"has taken a fork R");
		pthread_mutex_lock(philo->right_fork);
		print_msg(current_time() - philo->data->start_time, philo,
			"has taken a fork L");
		pthread_mutex_lock(philo->left_fork);
	}
}

void	philo_eat(t_philo *philo)
{
	print_msg(current_time() - philo->data->start_time, philo, "is eating");
	pthread_mutex_lock(&philo->update);
	philo->time_last_meal = current_time();
	pthread_mutex_unlock(&philo->update);
	usleep(philo->data->time_to_eat * 1000);
	philo->meals_had++;
	printf("meals had %d \n", philo->meals_had);
}

void	philo_sleep(t_philo *philo)
{
	print_msg(current_time() - philo->data->start_time, philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void	philo_thinks(t_philo *philo)
{
	print_msg(current_time() - philo->data->start_time, philo, "is thinking");
	usleep(10);
}

void	release_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}
