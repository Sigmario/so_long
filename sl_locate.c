/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_locate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:56:21 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/29 21:16:51 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_player_position(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	while (data->map[line])
	{
		i = 0;
		while (data->map[line][i])
		{
			if (data->map[line][i] == 'P')
			{
				data->p_line = line;
				data->p_char = i;
				return (0);
			}
			i++;
		}
		line++;
	}
	return (0);
}

int	sl_exit_position(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	while (data->map[line])
	{
		i = 0;
		while (data->map[line][i])
		{
			if (data->map[line][i] == 'E')
			{
				data->e_line = line;
				data->e_char = i;
				return (0);
			}
			i++;
		}
		line++;
	}
	return (0);
}
