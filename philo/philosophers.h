#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct		s_param
{
	int				num_of_philos; //это число философов, а также число вилок
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep; //мили сек
	int				num_ph_must_eat;
}t_param;

typedef struct		s_philo
{
	t_param			*param;
	pthread_t		threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	sms;

	unsigned int	launch;
	int				index;
	int				title;
	int				count;
	int				dead_flag;
	unsigned long	start_time;
	// pthread_mutex_t

}t_philo;

int	ft_atoi(const char *str);

#endif
