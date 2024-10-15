/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_philo_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:17:48 by adedayo           #+#    #+#             */
/*   Updated: 2024/10/15 20:35:55 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// aqui chamar e implementar todas as ações dos filos
//essa função será o 3 parametro da thread join

void	*philos_routines(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	while (is_alive == 1 && is_satisfied == 0)
	{
		take_fork()

		// Filósofo come

		// Filósofo solta os garfos

		// Filósofo dorme
		
		// Filósofo pensa

		// confirmar a ordem das ações
	}
	return (NULL);
}

// lembrar de implementar uma lógica 
//para metade pegar o garfo e metade não
// por ex: dar um sleep no impares
