/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvenkman.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvenkman <cvenkman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:05:25 by cvenkman          #+#    #+#             */
/*   Updated: 2021/11/10 22:16:56 by cvenkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}