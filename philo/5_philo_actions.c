/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_philo_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:57:53 by adedayo           #+#    #+#             */
/*   Updated: 2024/10/16 19:58:58 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
	{
		print_msg(philo->data->start_time - current_time(), philo,
			"has taken a fork");
		pthread_mutex_lock(&philo->left_fork->one_fork);
		print_msg(philo->data->start_time - current_time(), philo,
			"has taken a fork");
		pthread_mutex_lock(&philo->left_fork->one_fork);
	}
	else
	{
		print_msg(philo->data->start_time - current_time(), philo,
			"has taken a fork");
		pthread_mutex_lock(&philo->left_fork->one_fork);
		print_msg(philo->data->start_time - current_time(), philo,
			"has taken a fork");
		pthread_mutex_lock(&philo->left_fork->one_fork);
	}
}

void	philo_eat(t_philo *philo)
{
	long long	time;

	time = philo->data->start_time - current_time();
	print_msg(philo->data->start_time - current_time(), philo, "is eating");
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
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->one_fork);
	pthread_mutex_unlock(&philo->right_fork->one_fork);
}
