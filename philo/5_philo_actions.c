/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_philo_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:57:53 by adedayo           #+#    #+#             */
/*   Updated: 2024/10/15 20:48:27 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->philo_id % 2 == 1)
	{
		lock_fork(philo, philo->left_fork);
		lock_fork(philo, philo->right_fork);
	}
	else
	{
		lock_fork(philo, philo->right_fork);
		lock_fork(philo, philo->left_fork);
	}
}

void	eat(t_dinner *dinner)
{
}

void	sleep(t_dinner *dinner)
{
}

void	think(t_dinner *dinner)
{
}

void	release_fork(t_dinner *dinner, int fork_nbr)
{
	pthread_mutex_unlock(&dinner->forks[fork_nbr]);
}
