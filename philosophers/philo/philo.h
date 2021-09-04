#ifndef PHILO_H
# define PHILO_H

# define LIVE 15
# define DEAD 10
# define ALL_EATEN 11

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <stdio.h>
# include <libc.h>

typedef enum e_errors
{
	MALLOC_ERROR = 42,
	INPUT_DATA_ERROR,
	INPUT_FORMAT_ERROR,
	MUTEX_INIT_ERROR,
	PTHREAD_CREATE_ERROR
}			t_errors;

//typedef enum e_pstates
//{
//	EATING = 10,
//	SLEEPING,
//	THINKING,
//	DEAD,
//	ALL_EATEN
//}			t_pstates_enum;

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
	int		state;
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

long				ft_atoi(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
int					check_args(int argc, char **argv);
void 				print_status(t_philosopher *phil, const char *str,
								  const char *color,int state);
void				*life(void *arg);
unsigned long int	get_time(void);
void				go_sleep(unsigned long int time_period, t_philosopher *phil);
int					init_pdata(t_pdata *data, int argc, char **argv);
int					create_threads(t_pdata *data);
int					print_err_msg(t_errors err);
void				finish(t_pdata *data);

#endif
