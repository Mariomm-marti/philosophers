#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

typedef unsigned char	t_bool;

enum e_bool
{
	false,
	true
};

typedef struct s_params
{
	unsigned int	philos;
	unsigned int	amount;
	unsigned long	die;
	unsigned long	eat;
	unsigned long	sleep;
}	t_params;

#endif
