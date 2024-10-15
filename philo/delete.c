/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:02:17 by asanni            #+#    #+#             */
/*   Updated: 2024/10/15 17:11:09 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	g_x = 2;
//int	= 0;

void	*routine(void *a)
{
	sleep(1);
	printf("valor de x = %d\n", g_x);
	return (NULL);
}
	int	i;
	int	thread;
	int	g_x;

void*	routine2()
{
	g_x++;
	sleep(1);
	printf("valor de x = %d\n", g_x);
	i = 0;
	g_x = 0;
	thread = *((int *)a);
	while (i < 100)
	{
		g_x++;
		printf("thread %d valor de x = %d\n", thread, g_x);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	int			n1;
	int			n2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	n1 = 1;
	n2 = 2;
	pthread_create(&t1, NULL, &routine, &n1);
	pthread_create(&t2, NULL, &routine, &n2);
	sleep(5);
	return (0);
}
// neste documento eu tenho 1 """"mini philosopher""""
// aqui a var g_x é o garfo (que tds as threads tentam acessar ao mesmo tempo)
// a rotina é o jantar que contem os garfos e controla a ação dos philo
// as threads são os filosofos, que estão tentando pegar o garfo para jantar
