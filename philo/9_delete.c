/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_delete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:02:17 by asanni            #+#    #+#             */
/*   Updated: 2024/08/30 20:01:31 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//int	= 0;

void	*routine(void *a)
{
	int	i;
	int	thread;
	int	x;

	i = 0;
	x = 0;
	thread = *((int *)a);
	while (i < 1000000)
	{
		x += 5;
		printf("thread %d valor de x = %d\n", thread, x);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	pthread_
	int			n1;
	int			n2;

	n1 = 1;
	n2 = 2;
	pthread_create(&t1, NULL, &routine, &n1);
	pthread_create(&t2, NULL, &routine, &n2);
	sleep(5);
	return (0);
}

// neste documento eu tenho 1 """mini philosopher"""
// aqui a var x é o garfo (que tds as threads tentam acessar ao mesmo tempo)
// a rotina é o jantar que contém os garfos e controla a ação dos philos
// as threads são os filosofos, que estão tentando pegar o garfo para jantar
