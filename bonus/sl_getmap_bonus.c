/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_getmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:06:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/14 20:29:10 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_locate(t_data *data)
{
	int	line;
	int	i;

	line = -1;
	data->direction = 0;
	while (data->map[++line])
	{
		i = -1;
		while (data->map[line][++i])
		{
			if (data->map[line][i] == 'E')
			{
				data->e_line = line;
				data->e_char = i;
			}
			if (data->map[line][i] == 'P')
			{
				data->p_line = line;
				data->p_char = i;
			}
		}
	}
	return (0);
}

void	sl_count(t_data *data)
{
	int	line;
	int	i;

	line = 0;
	data->p_count = 0;
	data->c_count = 0;
	while (data->map[line])
	{
		i = 0;
		while (data->map[line][i])
		{
			if (data->map[line][i] == 'C')
				data->c_count++;
			i++;
		}
		line++;
	}
}

void	sl_count_line(t_data *data, int fd, char *filename)
{
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return ;
	data->nb_line = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->nb_line++;
		data->nb_char = ft_linelen(line);
		free(line);
	}
	close(fd);
}

char	**sl_getmap(t_data *data, char *filename)
{
	int	fd;

	fd = 0;
	sl_count_line(data, fd, filename);
	if (!data->nb_line)
	{
		ft_printf("Error\nIt's empty.\n");
		exit(EXIT_SUCCESS);
	}
	fd = open(filename, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->nb_line + 1));
	if (data->map == NULL)
		return (NULL);
	data->x = 0;
	while (TRUE)
	{
		data->map[data->x] = get_next_line(fd);
		if (data->map[data->x] == NULL)
			break ;
		data->x++;
	}
	close(fd);
	return (data->map);
}
