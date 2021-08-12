#ifndef WORKER_H
# define WORKER_H

# include <table.h>

t_bool	take_forks(t_philo const *locking, t_fork *forks, pthread_mutex_t *out);

#endif
