/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:57:29 by ysarsar           #+#    #+#             */
/*   Updated: 2019/12/29 22:06:04 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_select.h"

static  int     maxlen(t_lst *list)
{
    int     max_len;

    max_len = 0;
    while (list)
    {
        if (ft_strlen(list->name) > max_len)
            max_len = ft_strlen(list->name);
        list = list->next;
    }
    return (max_len);
}

static  void    print_list(t_lst *list, int index)
{
    char *under;

    under = tgetstr("us", NULL);
    if (index == 0)
    {
        ft_putstr_fd(list->color, 2);
        ft_putstr_fd(list->name, 2);
        ft_putstr_fd("\033[0m", 2);
    }
    else
    {
        ft_putstr_fd(under, 2);
        ft_putstr_fd("\033[1;31m", 2);
        ft_putstr_fd(list->color, 2);
        ft_putstr_fd(list->name, 2);
        ft_putstr_fd("\033[0m", 2);
    }
    
}

void            display(t_lst *list, int fd, int index)
{
    t_win   win;
    int     x;
    int     y;
    int     max_len;
    int     i;

    x = 0;
    i = 0;
    y = 0;
    ioctl(fd, TIOCGWINSZ, &win);
    max_len = maxlen(list);
    tputs(tgetstr("cl", NULL), 0, fd_putchar);
    while (list)
    {
        if (x + max_len + 1 >= win.ws_col)
        {
            x = 0;
            y++;
        }
        if (index == i)
            print_list(list, 1);
        else
            print_list(list, 0);
        tputs(tgoto(tgetstr("cm", NULL), x, y), 0, fd_putchar);
        x = x + max_len + 1;
        list = list->next;
        i++;
    }
}
