#include "libft.h"

void	assert(int expr, const char *msg)
{
	if (!expr)
	{
		ft_putendl_fd(msg, 1);
		exit(1);
	}
}
