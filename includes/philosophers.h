#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define MAX_TIMESTAMP 4294967295U

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
	unsigned int	die;
	unsigned int 	eat;
	unsigned int 	sleep;
}	t_params;

#endif
