#ifndef PHILO_LIBRARY_H
#define PHILO_LIBRARY_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>


typedef struct s_param
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_of_time_each_philo_must_eat;
}t_param;

typedef struct s_ph
{
    t_param param;
}t_ph;

#endif //PHILO_LIBRARY_H
