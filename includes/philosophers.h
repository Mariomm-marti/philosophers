#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define MAX_TIMESTAMP 4294967295U

typedef enum e_bool
{
	false,
	true
}	t_bool;

enum e_philostatus
{
	THINKING,
	EATING,
	SLEEPING
};

typedef struct s_philo
{
	unsigned int		id;
	enum e_philostatus	status;
	struct s_philo		*next;
}	t_philo;

typedef struct s_params
{
	unsigned int	philos;
	unsigned int	amount;
	unsigned int	die;
	unsigned int 	eat;
	unsigned int 	sleep;
}	t_params;

#endif
