#include <validate.h>
#include <utils.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_params	params;

	if (!parser_validate(argc, argv))
	{
		ft_putstr("Error: invalid parameters\n");
		return (1);
	}
	parser_fetch(&params, argv);
}
