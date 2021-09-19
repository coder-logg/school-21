#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/types.h>
# include <time.h>
# include <stdio.h>
# include <libc.h>

# define DEAD 113
# define ALL_EATEN 114

typedef enum e_errors
{
	MALLOC_ERROR = 42,
	SEM_OPEN_ERROR,
	INPUT_DATA_ERROR,
	INPUT_FORMAT_ERROR,
	PROCESS_CREATE_ERROR,
	PTHREAD_CREATE_ERROR,
	PTHREAD_DETACH_ERROR,
	SEM_WAIT_ERROR,
	SEM_POST_ERROR,
	SEM_CLOSE_ERROR
}			t_errors;

typedef struct s_input_data
{
	unsigned int	philos_nbr;
	int				times_eat;
	unsigned long	time_to_die;
	unsigned long	time_to_sleep;
	unsigned long	time_to_eat;
}				t_input_data;

typedef struct s_philo
{
	int				pid;
	unsigned long	last_eat_time;
	unsigned int	philo_id;
	int				eat_counter;
	int				flag;
	struct s_pdata	*data;
}			t_philo;

typedef struct s_pdata
{
	t_input_data	*input;
	sem_t			*forks;
	unsigned long	start_time;
	sem_t			*print_sem;
}			t_pdata;

long			ft_atoi(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
void			check_args(int argc, char **argv);
void			print_state(t_philo *phil, const char *str);
void			*life(void *arg);
unsigned long	get_time(void);
void			go_sleep(unsigned long time);
void			init(t_philo **philos, int argc, char **argv);
void			create_processes(t_philo *philos);
void			ft_error(t_errors err, t_philo *philos);
void			finish(t_philo *philos);
void			*check_state(void *ptr);
void			check_err(int function_res, t_errors may_be_err_code);
void			free_memory(t_philo *philos);

#endif
