/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:31:15 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/13 15:56:04 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strtoint.h"

static int	v_length(long value)
{
	int	len;

	if (value < INT_MIN || value > INT_MAX)
		return (0);
	len = 1;
	if (value < 10)
		return (len);
	if (value < 0)
		value *= -1;
	while (value > 9)
	{
		value /= 10;
		len++;
	}
	return (len);
}

static char	*v_str(int len, int value, int kind)
{
	char	*number;

	if (kind == 0)
		number = ft_calloc((len + 2), sizeof(char));
	else
	{
		number = ft_calloc((len + 1), sizeof(char));
		len--;
	}
	if (!number)
		return (0);
	while (len >= 0)
	{
		if (len == 0 && kind == 0)
		{
			number[len] = '-';
			return (number);
		}
		number[len] = (value % 10) + '0';
		value /= 10;
		len--;
	}
	return (number);
}

char	*ft_itoa(long value)
{
	if (!v_length(value))
		return (NULL);
	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	if (value < 0)
	{
		value *= -1;
		return (v_str(v_length(value), value, 0));
	}
	return (v_str(v_length(value), value, 1));
}
