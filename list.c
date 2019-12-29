/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:41:29 by ysarsar           #+#    #+#             */
/*   Updated: 2019/12/29 21:53:11 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_select.h"

t_lst       *init_list(char **av)
{
    int     i;
    t_lst   *head;
    t_lst   *list;

    list = NULL;
    if (!(head = (t_lst *)ft_memalloc(sizeof(t_lst))))
        return (list);
    head->next = NULL;
    list = head;
    i = 1;
    while (av[i])
    {
        list->name = ft_strdup(av[i]);
        list->color = NULL;
        if (!av[i + 1])
            break;
        if (!(list->next = (t_lst *)ft_memalloc(sizeof(t_lst))))
            return (NULL);
        list = list->next;
        i++;
    }
    list->next = NULL;
    return (head);
}