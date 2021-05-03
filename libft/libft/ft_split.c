#include "libft.h"

static size_t	substr_num(char const *str, char c, size_t *del_poss)
{
	size_t	str_num;
	size_t	i;

	str_num = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (str[i + 1] != c || (i > 0 && str[i - 1] != c))
				*(del_poss++) = i;
		}
		if (str[i] != c && c != 0 && str[i + 1] == c)
			str_num++;
		i++;
	}
	*(del_poss) = 0;
	return (str_num);
}

static char	add(char **res, size_t r_index, char *s, size_t s_len)
{
	res[r_index] = (char *)malloc(s_len + 1);
	if (res[r_index] != NULL)
	{
		ft_strlcpy(res[r_index], s, s_len + 1);
		res[r_index][s_len] = 0;
		return (0);
	}
	while (r_index > 0)
	{
		free(res[r_index - 1]);
		r_index--;
	}
	free(res);
	return (1);
}

static void	*put_res(size_t *del_poss, char *s_trimed, char **res, int arr[])
{
	size_t	r_index;
	size_t	i;

	r_index = 0;
	i = 0;
	if (add(res, r_index++, s_trimed, del_poss[i++]))
		return (res = NULL);
	while ((int)r_index < arr[1] - 1 && del_poss[i] != 0)
	{
		if (*(s_trimed + del_poss[i] - 1) != arr[0] && add(res, r_index++,
				s_trimed + del_poss[i - 1] + 1,
				del_poss[i] - del_poss[i - 1] - 1))
			return (res = NULL);
		i++;
	}
	if (del_poss[i] == 0)
		--i;
	if (add(res, r_index, s_trimed + del_poss[i] + 1,
			ft_strlen(s_trimed) - del_poss[i]))
		return (res = NULL);
	res[arr[1]] = NULL;
	return (res);
}

// arr = [ c, sub_str_num ]
static char	**make_res(size_t *del_poss, char c, char *s_trimed)
{
	size_t	sub_str_num;
	char	**res;
	int		arr[2];

	arr[0] = (int)c;
	sub_str_num = substr_num(s_trimed, c, del_poss);
	arr[1] = sub_str_num;
	res = (char **)malloc(sizeof(char *) * (sub_str_num + 1));
	if (res != NULL)
	{
		if (sub_str_num == 1)
		{
			add(res, 0, s_trimed, ft_strlen(s_trimed));
			res[1] = NULL;
		}
		else
			put_res(del_poss, s_trimed, res, arr);
	}
	free(s_trimed);
	free(del_poss);
	return (res);
}

// arr = [ strimed_len, sub_str_num ]
char	**ft_split(char const *s, char c)
{
	size_t	strimed_len;
	size_t	*del_poss;
	char	**res;
	char	*s_trimed;
	char	c_arr[2];

	c_arr[0] = c;
	c_arr[1] = 0;
	s_trimed = ft_strtrim(s, c_arr);
	if (s_trimed == NULL)
		return (NULL);
	if (*s_trimed == '\0')
	{
		res = (char **)malloc(sizeof(char *));
		res[0] = NULL;
		free(s_trimed);
		return (res);
	}
	strimed_len = ft_strlen(s_trimed);
	del_poss = (size_t *)malloc((strimed_len / 2 + 2) * sizeof(size_t));
	if (del_poss != NULL)
		res = make_res(del_poss, c, s_trimed);
	else
		res = NULL;
	return (res);
}
