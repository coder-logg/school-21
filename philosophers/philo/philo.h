#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

#define ERR_MSG "Usage: ./philo number_of_philosophers time_to_die"\
" time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

typedef enum e_errors
{
	MALLOC_ERROR,
	INPUT_DATA_ERROR,
	INPUT_FORMAT_ERROR,
	MUTEX_INIT_ERROR,
	PTHREAD_CREATE_ERROR
}			t_errors;

typedef enum e_pstates
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	ALL_EATEN
}			t_pstates_enum;

typedef struct s_input_data
{
	unsigned long int	philos_nbr;
	unsigned long int	time_to_die;
	unsigned long int	time_to_sleep;
	unsigned long int	time_to_eat;
	unsigned long int	times_eat;
}				t_input_data;

typedef	struct s_philosopher
{
	pthread_t			thread_id;
	t_pstates_enum		state;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*msg_mutex;
	unsigned long int	last_eat_time;
	unsigned int		philo_id;
	unsigned long int	birth_time;
	unsigned int        eat_counter;
	t_input_data		*input;
}			t_philosopher;


typedef	struct s_pdata
{
	t_input_data		*input;
	pthread_mutex_t		*forks;
	pthread_mutex_t		msg_mutex;
	t_philosopher		*philos;
}			t_pdata;

long	ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
int		check_args(int argc, char **argv);
void	*life(void *arg);
long long int	get_time(void);
void    go_sleep(unsigned long int time_period, t_philosopher *phil);
void	print_msg(t_philosopher *phil);
int init_pdata(t_pdata *data, int argc, char **argv);
void	create_threads(t_pdata *data);
void	print_err_msg(t_errors err);



#endif
