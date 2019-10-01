/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_db_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:47:28 by anjansse          #+#    #+#             */
/*   Updated: 2019/09/25 12:47:47 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_db_tab(char **av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] != NULL)
		ft_strdel(&av[i++]);
	free(av);
	av = NULL;
}
