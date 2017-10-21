/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:06:25 by ggane             #+#    #+#             */
/*   Updated: 2017/10/21 17:27:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*image_id;
	char		*memory_area;
	int			bpp;
	int			size_line;
	int			**coordinates;
}				t_data;

/*
** check_errors.c
*/

int				check_errors(int ac, char **av);

/*
** check_errors_utils.c
*/

int				is_not_fdf_extension(char *map_name);
int				is_invalid_characters(char *map_copy);
int				print_error_msg(char *error_msg);

/*
** file_manipulation_utils.c
*/

char			*copy_map_a_string(char *map_name);
int				get_map_fd(char *map_name);

#endif
