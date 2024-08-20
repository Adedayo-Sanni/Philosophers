#include "philo.h"


int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\nThe program should be run as follows:\n./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (validate_args(argv) == 1)
	{
		printf("Invalid arguments!");
		return (1);
	}
	//função que vai dar inicio a tudo
	return(0)
}