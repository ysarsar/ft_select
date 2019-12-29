/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 18:37:58 by ysarsar           #+#    #+#             */
/*   Updated: 2019/12/29 22:19:06 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_select.h"

static  void        check_args(int ac)
{
    if (ac < 2)
    {
        ft_putendl("./ft_select: usage: ./ft_select [arg1] [arg2] ...");
        exit(1);
    }
}

static int lent_list(t_lst *list)
{
    int count;

    count = 0;
    while (list)
    {
        count++;
        list = list->next;
    }
    return (count);
}

static  void    ft_select_arg(t_lst **list, int index)
{
    t_lst   *curr;
    int     i;

    i = 0;
    curr = *list;
    while (curr)
    {
        if (index == i)
        {
            if (!curr->color)
                curr->color = ft_strdup("\033[7m");
            else
                curr->color = NULL;
            break;
        }
        curr = curr->next;
        i++;
    }
}

int     main(int ac, char **av)
{
    t_lst   *list;
    int     fd;
    int     r;
    int     index;
    
    index = 1;
    r = 0;
    check_args(ac);
    fd = init_term();
    list = init_list(av);
    display(list, fd, 1);
    while (read(0, &r, 4) > 0)
    {

        if (r == K_LEFT && index > 1)
            index--;
        if (r == K_RIGHT && index < lent_list(list) - 1)
            index++;
        if (r == K_ESC)
            break ;
        if (r == K_SP)
            ft_select_arg(&list, index);
        display(list, fd,index);
        r = 0;
    }
    tputs(tgetstr("te", NULL), 0, fd_putchar);   
    tputs(tgetstr("ve", NULL), 0, fd_putchar);
    return (0);
}