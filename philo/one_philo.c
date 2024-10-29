/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:19:47 by asanni            #+#    #+#             */
/*   Updated: 2024/10/29 14:46:39 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lonely_rotine(t_philo *philo)
{
	if (is_dead(philo) != 1)
	{
		print_msg(philo, "has taken a fork L");
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}
