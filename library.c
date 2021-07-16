#include "library.h"

int	ft_isspace(int c)
{
	while (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (result > 2147483647 && sign == 1)
			return (-1);
		else if (result >= 2147483648 && sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}

int	ft_check_param(t_param *param, char **argv)
{
	param->number_of_philosophers = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	param->num_of_time_each_philo_must_eat = ft_atoi(argv[5]);
	return (0);
}

void	ft_print_param(t_param *param)
{
	printf("NUM = %d\n", param->number_of_philosophers);
	printf("DIE = %d\n", param->time_to_die);
	printf("EAT = %d\n", param->time_to_eat);
	printf("SLE = %d\n", param->time_to_sleep);
	printf("N_E = %d\n", param->num_of_time_each_philo_must_eat);
}

int	main(int argc, char **argv)
{
	t_param	*param;

	param = (t_param *)malloc(sizeof(t_param));
	if (argc <= 5 || argc > 6)
		printf("Error\n");
	else if (argc == 6)
	{
		ft_check_param(param, argv);
		ft_print_param(param);
	}
}
