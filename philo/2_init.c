/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:48:32 by asanni            #+#    #+#             */
/*   Updated: 2024/09/17 20:04:30 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_dinner(t_dinner *dinner, char **argv, int argc)
{
	dinner->data = calloc(1, sizeof(t_data));
	if (!dinner->data)
		error_exit("Erro ao alocar memória", 1, DATA, dinner);
	start_data(dinner, argv, argc);
}

void	start_data(t_dinner *dinner, char **argv, int argc)
{
	dinner->data->nb_philos = ft_atol(argv[1]);
	dinner->data->time_to_die = ft_atol(argv[2]);
	dinner->data->time_to_eat = ft_atol(argv[3]);
	dinner->data->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		dinner->data->nb_meals_todo = ft_atol(argv[5]);
}

// void	start_philos(t_dinner *dinner)
// {
// }
