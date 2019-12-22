/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 23:05:40 by ysarsar           #+#    #+#             */
/*   Updated: 2019/12/22 23:39:03 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_term		*stock_list(char **av)
{
	t_term	*curr;
	t_term	*tmp;
	int		i;

	i = 0;
	while (av[i])
		i++;
	if (!(curr = (t_term *)ft_memalloc(sizeof(t_term) * i + 1)))
		return (NULL);
	tmp = curr;
	curr->next = NULL;
	i = 1;
	while (av[i])
	{
		curr->arg = ft_strdup(av[i]);
		curr->color = NULL;
		curr->id = i;
		if (!(curr->next = (t_term *)ft_memalloc(sizeof(t_term))))
			return (NULL);
		curr = curr->next;
		i++;
	}
	curr = NULL;
	return (tmp);
}