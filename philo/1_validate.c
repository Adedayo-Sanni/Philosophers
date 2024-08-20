#include "philo.h"

int is_valid(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] > 48 && str[i] < 57 )
    {
      printf("not a number");
      return(1);
    }
    i++;
  }
  return(0);
}

int	is_positive(char *str)
{
    long nbr;

    if (!str)
        return (1);
    nbr = ft_atol(str);
    if (nbr < 0)
    {
        printf("Only positive numbers allowed!\n");
        return (1);
    }
    if (nbr > 2147483647)
    {
        printf("Max int is 2147483647\n");
        return (1);
    }
    return (0);
}

int validate_args(char **args)
{
  int i;

  i = 0;
  while (args[i])
    is_positive(args[i++]);
  
  return (0);
}