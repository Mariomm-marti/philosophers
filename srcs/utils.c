#include <stddef.h>
#include <philosophers.h>

size_t	ft_strlen(char const *str)
{
	if (!str || !*str)
		return (0);
	return (1 + ft_strlen(str + 1));
}

void	ft_putstr(char const *str)
{
	write(1, str, ft_strlen(str));
}

unsigned long	ft_strtoul(char const *str, char const **endp)
{
	unsigned long	ret;

	if (!str)
		return (0);
	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	*endp = str;
	return (ret);
}
