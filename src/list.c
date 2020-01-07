/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:47:16 by ysarsar           #+#    #+#             */
/*   Updated: 2020/01/07 01:12:08 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static	void	list_push(t_lst	**head, t_lst *new)
{
	t_lst	*current;

	if (!(*head))
		*head = new;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	
}

static	t_lst	*create_node(char *av)
{
	t_lst	*list;

	list = NULL;
	if (!(list = (t_lst *)ft_memalloc(sizeof(t_lst))))
		return (list);
	list->color = NULL;
	list->name = ft_strdup(av);
	list->next = NULL;
	return (list);
}

void			init_list(t_term *term, char **av)
{
	int		i;

	i = 1;
	term->list = NULL;
	while (av[i])
	{
		list_push(&term->list, create_node(av[i]));
		i++;
	}
}

void			ft_remove_node(t_term *term, int index)
{
	t_lst	*tmp;
	t_lst	*cur;
	int		i;

	cur = term->list;
	i = 0;
	while (cur)
	{
		if (index == i + 1)
		{
			tmp = cur->next;
			cur->next = (!tmp) ? NULL : tmp->next;
			free(tmp->color);
			ft_strdel(&tmp->name);
			free(tmp);
			break ;
		}
		cur = cur->next;
		i++;
	}
}