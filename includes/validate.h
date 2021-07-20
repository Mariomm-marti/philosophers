#ifndef VALIDATE_H
# define VALIDATE_H

# include <philosophers.h>

t_bool	parser_validate(int argc, char **argv);
void	parser_fetch(t_params *input, char **argv);

#endif
