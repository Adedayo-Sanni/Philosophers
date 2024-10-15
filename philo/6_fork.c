/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:20:04 by adedayo           #+#    #+#             */
/*   Updated: 2024/10/15 20:42:01 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_fork(t_philo *philo, t_mutex *forks)
{
	pthread_mutex_lock(&forks->one_fork);
	//print_msg(dinner->start_time, dinner->philos->philo_id, "Has taken a fork");
}
