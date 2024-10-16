/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_start_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:46:08 by adedayo           #+#    #+#             */
/*   Updated: 2024/10/16 18:00:19 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// função para comecar os filos
// aqui chamo a pthread join com a rotina deles

void	start_philos(t_dinner *dinner)
{
	int	i;

	i = 0;
	dinner->data->start_time = current_timestamp();
	while (i < dinner->data->nb_philos)
	{
		if (pthread_create(&dinner->philos[i].self_thread, NULL,
				philos_routines, &dinner->philos[i]) != 0)
		{
			error_exit("The guests could not come", 1, PHILO, dinner);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < dinner->data->nb_philos)
	{
		if (pthread_join(dinner->philos[i].self_thread, NULL) != 0)
		{
			error_exit("The guests wont leave", 1, PHILO, dinner);
			return ;
		}
		i++;
	}
}

/*Criação de threads: Aqui, uma nova thread é criada para cada filósofo.
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
