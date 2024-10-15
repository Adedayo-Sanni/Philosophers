/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:20:04 by adedayo           #+#    #+#             */
/*   Updated: 2024/10/15 17:05:35 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_fork(t_dinner *dinner, int fork_nbr)
{
	pthread_mutex_lock(&dinner->forks[fork_nbr]);
	print_msg(dinner->start_time, dinner->philos->philo_id, "Has taken a fork");
}
