/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_delete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanni <asanni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:02:17 by asanni            #+#    #+#             */
/*   Updated: 2024/08/21 19:32:24 by asanni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	g_x = 2;

void*	routine()
{
	sleep(1);
	printf("valor de x = %d\n", g_x);
	return (NULL);
}

void*	routine2()
{
	g_x++;
	sleep(1);
	printf("valor de x = %d\n", g_x);
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
