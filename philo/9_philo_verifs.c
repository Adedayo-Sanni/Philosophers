/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_philo_verifs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:09:26 by asanni            #+#    #+#             */
/*   Updated: 2024/10/15 20:35:43 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pegar o tempo do last meal e verificar se o tempo ultrapassou o time to die

int	is_alive(t_dinner *dinner)
{
	long int	diff;

	diff = dinner->start_time - dinner->philos->time_last_meal;
	if (diff > dinner->data->time_to_die)
		return (0);
	return (1);
}

int	is_satisfied(t_dinner *dinner)
{
	if (dinner->philos->meals_had < dinner->data->nb_meals_todo)
		return (0);
	return (1);
}
