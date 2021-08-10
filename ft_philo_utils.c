#include "philo.h"

int	ft_check_input_num(t_philo *philo)
{
	if (philo->num_of_philos < 1 || philo->num_of_philos > 200 || \
	philo->time_to_die < 60 || philo->time_to_eat < 60 || \
	philo->time_to_sleep < 60)
		return (1);
	return (0);
}

int	ft_check_param(t_philo *philo, int argc, char **argv)
{
	if (argc == 5)
	{
		philo->num_of_philos = ft_atoi(argv[1]);
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
	}
	if (argc == 6)
	{
		philo->num_of_philos = ft_atoi(argv[1]);
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		if ((philo->num_ph_must_eat = ft_atoi(argv[5])) < 1)
		{
			printf(RED"Error: write correct argument's!\n");
			exit(0);
		}
	}
	return (0);
}
