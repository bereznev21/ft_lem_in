#include "lem_in.h"

int		ft_srch_min(int *len_table)
{
	int min;
	int i;
	int	i_min;

	i = -1;
	i_min = 0;
	min = len_table[0];
	while (len_table[++i] != -1)
	{
		if (len_table[i] < min)
		{
			min = len_table[i];
			i_min = i;
		}
	}
	return (i_min);
}

int		ft_srch_max(int *len_table, int len)
{
	int max;
	int i;

	i = -1;
	max = len_table[0];
	while (i < len && len_table[i] != -1)
	{
		if (len_table[i] > max)
			max = len_table[i];
		i++;
	}
	return (max);
}
