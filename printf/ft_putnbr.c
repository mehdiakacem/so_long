/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:22:13 by makacem           #+#    #+#             */
/*   Updated: 2022/01/06 14:07:04 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		n = -n;
		ret += ft_putchar('-');
	}
	if (n >= 10)
	{
		ret += ft_putnbr(n / 10);
		ret += ft_putnbr(n % 10);
	}
	else if (n >= 0 && n <= 9)
		ret += ft_putchar(n + '0');
	return (ret);
}
