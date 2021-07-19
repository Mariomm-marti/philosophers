#include <philosophers.c>
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
	count = 0;
	while (*(argv + count))
	{
		if (validate_argument(*(argv + count)))
			return (false);
		count++;
	}
	return (true);
}
