/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_start_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:29:49 by asanni            #+#    #+#             */
/*   Updated: 2024/10/24 20:08:27 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philos(t_dinner *dinner)
{
	int	i;

	i = 0;
	dinner->data.start_time = current_time();
	while (i < dinner->data.nb_philos)
	{
		if (pthread_create(&dinner->philos[i].self_thread, NULL,
				philos_routines, &dinner->philos[i]) != 0)
		{
			error_exit("The guests could not come", PHILO, dinner);
			return ;
		}
		i++;
	}
	// monitor vem aqui
	i = 0;
	while (i < dinner->data.nb_philos)
	{
		if (pthread_join(dinner->philos[i].self_thread, NULL) != 0)
		{
			error_exit("The guests wont leave", PHILO, dinner);
			return ;
		}
		i++;
	}
}

int	is_alive(t_philo *philo)
{
	long int	diff;

	diff = current_time() - philo->time_last_meal;
	if (diff >= philo->data->time_to_die)
	{
		print_msg(current_time() - philo->data->start_time, philo, "died");
		philo->data->philo_died = 1;
		return (0);
	}
	return (1);
}

int	is_satisfied(t_philo *philo)
{
	if (philo->meals_had == philo->data->nb_meals_todo)
		return (0);
	return (1);
}

int	is_dead(t_philo *philo)
{
	int	verif;

	pthread_mutex_lock(&philo->data->monitor);
	verif = philo->data->philo_died;
	pthread_mutex_unlock(&philo->data->monitor);
	return (verif);
}

/* Criação de threads: Aqui, uma nova thread é criada para cada filósofo.
pthread_create é chamado, passando o endereço da thread do 
filósofo atual (dinner->philos[i].self_thread), um segundo argumento como NULL 
(para usar os atributos padrão da thread), o endereço da função que a thread deve 
executar (philos_routines), e um ponteiro para a estrutura do filósofo (&dinner->philos[i]).
 Se pthread_create falhar, ele retornará um valor diferente de zero.

 A função pthread_join é utilizada em programação multithread em C para esperar que uma 
 thread específica termine sua execução. 
- Sincronização: pthread_join bloqueia a thread que a chama até que a thread especificada 
(o primeiro argumento) termine. Isso permite que você sincronize a execução entre threads.
- Recuperação de Resultados: Se a thread que você está aguardando retornar um valor 
(via pthread_exit), você pode capturar esse valor no segundo argumento da função, 
que deve ser um ponteiro para o local onde o valor será armazenado. 
Se não for necessário, você pode passar NULL.
- Limpeza de Recursos: Chamar pthread_join permite que o sistema limpe os recursos utilizados 
pela thread terminada. Se pthread_join não for chamado para uma thread terminada, 
ela permanecerá em um estado "zumbi" até que seus recursos sejam liberados.
*/
