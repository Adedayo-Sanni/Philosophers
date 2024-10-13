/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedayo <adedayo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 23:20:04 by adedayo           #+#    #+#             */
/*   Updated: 2024/10/13 00:00:55 by adedayo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void  lock_fork(t_dinner *dinner, int fork_nbr)
{
  pthread_mutex_lock(&dinner->forks[fork_nbr]);
  print_msg(dinner->time, dinner->philos->philo_id, "Has taken a fork");
}
