/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 19:56:01 by ggane             #+#    #+#             */
/*   Updated: 2017/10/21 21:07:51 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"
#define SIZE_4_CORRECT 8
#define SIZE_4_ERRORS 3

static void		print_file_name(char *test_file)
{
	ft_putstr("Test on ");
	ft_putstr(test_file + 30);
}

int             main(int ac, char **av)
{
	if (av[1])
		print_file_name(av[1]);
	else
		ft_putstr("Test of no file ");
	if (check_errors(ac, av[1]))
		return (-1);
	else
		ft_putendl(" succeeded");
    return (0);
}
