/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_philo_verifs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:09:26 by asanni            #+#    #+#             */
/*   Updated: 2024/10/16 19:40:58 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pegar o tempo do last meal e verificar se o tempo ultrapassou o time to die

int	is_alive(t_philo *philo)
{
	long int	diff;

	diff = philo->data->start_time - philo->time_last_meal;
	if (diff > philo->data->time_to_die)
		return (0);
	return (1);
}

int	is_satisfied(t_philo *philo)
{
	if (philo->meals_had < philo->data->nb_meals_todo)
		return (0);
	return (1);
}
