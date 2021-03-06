/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <ysarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:16:47 by ysarsar           #+#    #+#             */
/*   Updated: 2019/12/11 18:25:19 by ysarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	number_len(int nb)
{
	int		res;
	long	n;

	res = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		res++;
		n = -nb;
	}
	else
		n = nb;
	while (n > 0)
	{
		res++;
		n = n / 10;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		num;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n;
	len = number_len(n);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (is_neg(n))
		num = -n;
	while (len >= 0)
	{
		str[len - 1] = (num % 10 + 48);
		num /= 10;
		len--;
	}
	if (is_neg(n))
		str[0] = '-';
	return (str);
}
