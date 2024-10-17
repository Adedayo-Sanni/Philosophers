/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_philo_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:57:53 by adedayo           #+#    #+#             */
/*   Updated: 2024/10/17 19:45:45 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
	{
		print_msg(philo->data->start_time - current_time(), philo,
			"has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_msg(philo->data->start_time - current_time(), philo,
			"has taken a fork");
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		print_msg(philo->data->start_time - current_time(), philo,
			"has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_msg(philo->data->start_time - current_time(), philo,
			"has taken a fork");
		pthread_mutex_lock(philo->left_fork);
	}
}

void	philo_eat(t_philo *philo)
{
	print_msg(philo->data->start_time - current_time(), philo, "is eating");
	pthread_mutex_lock(philo->time_last_meal);
	philo->time_last_meal = current_time();
	pthread_mutex_unlock(philo->time_last_meal);
	usleep(philo->data->time_to_eat * 1000);
}

void	philo_sleep(t_philo *philo)
{
	print_msg(philo->data->start_time - current_time(), philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void	philo_thinks(t_philo *philo)
{
	print_msg(philo->data->start_time - current_time(), philo, "is thinking");
	usleep(10);
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
