#include "philosophers.h"

int	ft_check_param(t_param *param, int argc, char **argv)
{
	if (argc == 5)
	{
		param->num_of_philos = ft_atoi(argv[1]);
		param->time_to_die = ft_atoi(argv[2]);
		param->time_to_eat = ft_atoi(argv[3]);
		param->time_to_sleep = ft_atoi(argv[4]);
	}
	else if (argc == 6)
	{
		param->num_of_philos = ft_atoi(argv[1]);
		param->time_to_die = ft_atoi(argv[2]);
		param->time_to_eat = ft_atoi(argv[3]);
		param->time_to_sleep = ft_atoi(argv[4]);
		param->num_ph_must_eat = ft_atoi(argv[5]);
	}
	if (param->num_of_philos < 1 || param->num_of_philos > 200 || \
		param->time_to_die < 60 || param->time_to_eat < 60 || \
		param->time_to_sleep < 60 || param->num_ph_must_eat < 1)
		return (1);
	return (0);
}

void	ft_print_param(t_param *param)
{
	printf("NUM = %d\n", param->num_of_philos);
	printf("DIE = %d\n", param->time_to_die);
	printf("EAT = %d\n", param->time_to_eat);
	printf("SLE = %d\n", param->time_to_sleep);
	printf("N_E = %d\n", param->num_ph_must_eat);
}

unsigned int	ft_life_time(void)
{
	struct timeval	clock_time;

	gettimeofday(&clock_time, NULL);
	return ((clock_time.tv_usec / 1000) + (clock_time.tv_sec * 1000));
}

void	ft_usleep(int ms)
{
	unsigned long	time;

	time = get_time() + ms;
	while ((get_time() < time))
		usleep(10);
}

void	ft_mutex_init(t_philo *ph)
{
	int i;

	i = 0;

	while (i < ph->param->num_of_philos)
	{
		//pthread_mutex_init(&ph->forks[i], NULL);
	}

}


void	*ft_philo_live(void *philo)
{
	//t_param *param;
	t_philo *ph;

	ph = (t_philo *)philo;

	if (ph->index % 2)
		ft_usleep(ph->param->time_to_eat / 2);
	while (ph->count != ph->param->time_to_die)
	{
		pthread_mutex_lock(&ph->forks[ph->index]);
		printf("%li\t%i\thas taken a fork\n", get_time() - ph->start_time, ph->title);
		pthread_mutex_lock(&ph->forks[(ph->index + 1) % ph->param->num_of_philos]);
		printf("%li\t%i\thas taken a fork\n", get_time() - ph->start_time, ph->title);

		//ph.time-life = get_time();
		ph->count++;
		//status eat
		printf("%li\t%i\tis eating\n", get_time() - ph->start_time, ph->title);
		ft_usleep(ph->param->time_to_eat);


	}
	return (NULL);
}

void ft_philo_init(t_philo *ph, t_param *param)
{
	int i = 0;
	while(i < param->num_of_philos)
	{
		ph[i].index = i;
		ph[i].title = i + 1;
		ph->launch = ft_life_time(); //расчет времени
		ph[i].param = param;
		ph[i].dead_flag = 0;
		ph[i].count = 0;
		i++;
	}
}

void	*ft_print_status(t_philo *ph)
{
	(void)ph;
	printf("has taken a fork\n");
	printf("is eating\n");
	printf("is sleeping\n");
	printf("is thinking\n");
	printf("died\n");
	return (NULL);
}

void ft_init_zero(t_param *param)
{
	param->num_of_philos = 0;
	param->time_to_eat = 0;
	param->time_to_sleep = 0;
	param->time_to_die = 0;
	param->num_ph_must_eat = 0;
}

int	main(int argc, char **argv)
{
	t_param	param;
	t_philo *ph;


	//param = (t_param *)malloc(sizeof(t_param));
	//ph->launch = 0;
	ft_init_zero(&param);
	if (argc == 5 || argc == 6)
	{

		if (ft_check_param(&param, argc, argv))
			return (printf("Error: argument!\n"));

		ph = malloc(sizeof(t_philo) * param.num_of_philos);
		//ph->forks = malloc(sizeof(pthread_mutex_t) * param.num_of_philos);

		ft_philo_init(ph, &param);
		//ft_mutex_init(ph);

		int i = 0;
		while (i < param.num_of_philos)
		{
			ph[i].index = i;
			ph[i].title = i + 1;
			ph->launch = ft_life_time(); //расчет времени
			ph[i].param = &param;
			ph[i].dead_flag = 0;
			ph[i].count = 0;
			pthread_create(&ph[i].threads, NULL, ft_philo_live, (void *)&ph[i]);
			i++;
		}

		i = 0;
		while (1)
		{
			if (ph[i].dead_flag)
			{
				while(i < param.num_of_philos)
				{
					pthread_detach(ph[i].threads);
					i++;
				}
				break;
			}
			pthread_join(ph[i].threads, NULL);
			i++;
		}

		//ft_mutex_init(param);
		//ft_print_param(param);
	}
	else
		printf("Error: argument!\n");
	return (0);
}

