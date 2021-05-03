#include "printf.h"
t_pattern	*new_pattern()
{
	t_pattern *res;

	res = malloc(sizeof(t_pattern));
	ft_memset(res, 0, sizeof(t_pattern) - 1);
	return (res);
}

//void	set_data(void *data, void *field)
//{
//	*field = *data;
//}

void	init_pattern(t_pattern *pattern_to_init, int init_data_arr[5],  size_t init_arr_size)
{
	if (pattern_to_init == NULL)
		return ;
	if (init_arr_size < 5 || init_data_arr == NULL)
	{
		if (init_data_arr == NULL)
			init_arr_size = 0;
		while (init_arr_size != 5)
			init_data_arr[init_arr_size++] = 0;
	}
	pattern_to_init->flag = init_data_arr[0];
	pattern_to_init->width = init_data_arr[1];
	pattern_to_init->accuracy = init_data_arr[2];
	pattern_to_init->size = init_data_arr[3];
	pattern_to_init->type = init_data_arr[4];

}

int main()
{
	t_pattern * tp = new_pattern();
	int a[] = {5, 6, 7};
	init_pattern(tp, a, 3);
//	sum(int, 13, 98);
}
