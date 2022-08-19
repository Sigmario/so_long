/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:13:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/08/19 18:48:11 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

typedef struct s_data
{
	char	*addr;
	void	*img;
	int		endian;
	int		line_len;
	char 	**map;
	int		line_index;
	int		char_index;
	int		nb_line;
	int		bpp;
}				t_data;

void	sl_mlx_pixel_put(t_data *data, int x, int y, int color);
void	sl_get_map(t_data *data);

#endif