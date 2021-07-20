#include <philosophers.h>
#include <utils.h>

static t_bool	validate_argument(char const *str)
{
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str)
		return (false);
	return (true);
}

t_bool	parser_validate(int argc, char **argv)
{
	short	count;

	if (argc != 5 && argc != 6)
		return (false);
	count = 1;
	while (*(argv + count))
	{
		if (!validate_argument(*(argv + count)))
			return (false);
		count++;
	}
	return (true);
}

void	parser_fetch(t_params *input, char **argv)
{
	input->philos = ft_strtoul(*(argv + 1));
	input->die = ft_strtoul(*(argv + 2));
	input->eat = ft_strtoul(*(argv + 3));
	input->sleep = ft_strtoul(*(argv + 4));
	input->amount = ft_strtoul(*(argv + 5));
}
