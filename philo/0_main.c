#include "philo.h"


// int	main(int argc, char **argv)
// {
// 	if (argc < 5 || argc > 6)
// 	{
// 		printf("Wrong number of arguments\nThe program should be run as follows:\n./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
// 		return (1);
// 	}
// 	if (validate_args(argv) == 1)
// 	{
// 		printf("Invalid arguments!");
// 		return (1);
// 	}
// 	//função que vai dar inicio a tudo
// 	return(0);
// }

void* routine()
{
	printf("teste de thread\n");
	sleep(3);
	printf("final do teste de thread\n");
	return (NULL);
}

int main(void)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
//continuar playlist do codevault