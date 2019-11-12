#include "libft.h"

void	error_exit(const char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(1);
}

void	assert(int expr, const char *msg)
{
	if (!expr)
		error_exit(msg);
}
