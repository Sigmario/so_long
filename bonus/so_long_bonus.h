/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:13:59 by julmuntz          #+#    #+#             */
/*   Updated: 2022/09/11 20:39:46 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define UP 1001
# define LEFT 2002
# define DOWN 3003
# define RIGHT 4004

# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data
{
	void	*mlx;
	void	*window;

	char	**map;
	int		x;
	int		nb_line;
	int		nb_char;
	int		w;
	int		h;

/*//////////TMP//////////////*/
	void	*img_a;
/*//////////TMP//////////////*/
	void	*img_s;
	void	*img_0;
	void	*img_1;
	void	*img_z;
	void	*img_e;
	void	*img_c;
	void	*img_p;
	void	*img_u_p;
	void	*img_l_p;
	void	*img_d_p;
	void	*img_r_p;
	void	*img_dig;

	int		e_line;
	int		e_char;
	int		p_line;
	int		p_char;

	int		c_count;
	int		p_count;

	int		direction;

	int		u_check;
	int		l_check;
	int		d_check;
	int		r_check;

}			t_data;

char		**sl_getmap(t_data *data, char *path);
int			sl_errors(t_data data);
int			sl_invalid_extension(char *filename);
int			sl_invalid_chars(t_data data);
int			sl_find_images(t_data *data);
int			sl_images(t_data *data);
int			sl_locate(t_data *data);
void		sl_count(t_data *data);
int			sl_key(int key, t_data *data);
int			sl_cross(t_data *data);
void		sl_up(t_data *data);
void		sl_left(t_data *data);
void		sl_down(t_data *data);
void		sl_right(t_data *data);
int			sl_quit(t_data *data);
void		sl_free(t_data *data);
void		sl_free_map(t_data *data);
void		sl_free_image(t_data *data);
void		sl_score(t_data *data);

#endif