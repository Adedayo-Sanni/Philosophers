/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_philo_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:29:59 by asanni            #+#    #+#             */
/*   Updated: 2024/10/31 12:51:32 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (is_dead(philo) != 1)
	{
		if (philo->philo_id % 2 == 1)
		{
			pthread_mutex_lock(philo->left_fork);
			print_msg(philo, "has taken a fork");
			pthread_mutex_lock(philo->right_fork);
			print_msg(philo, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(philo->right_fork);
			print_msg(philo, "has taken a fork");
			pthread_mutex_lock(philo->left_fork);
			print_msg(philo, "has taken a fork");
		}
	}
}

void	philo_eat(t_philo *philo)
{
	if (is_dead(philo) != 1)
	{
		update_last_meal(philo);
		print_msg(philo, "is eating");
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_lock(&philo->eat);
		philo->meals_had++;
		pthread_mutex_unlock(&philo->eat);
	}
}

void	philo_sleep(t_philo *philo)
{
	if (is_dead(philo) != 1)
	{
		print_msg(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
	}
}

void	philo_thinks(t_philo *philo)
{
	if (is_dead(philo) != 1)
	{
		print_msg(philo, "is thinking");
		usleep(200);
	}
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
