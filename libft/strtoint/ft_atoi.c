/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:43:16 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/12 18:04:37 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "strtoint.h"
/* long atoi
long	ft_atoi(const char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-') // Handle negative sign
	{
		sign = -1;
		str++;
	}
	else if (*str == '+') // Skip positive sign
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (number > (LONG_MAX / 10) || (number == (LONG_MAX / 10) && (*str - '0') > (LONG_MAX % 10)))
		{
			// Overflow detection
			return (sign == 1 ? LONG_MAX : LONG_MIN);
		}
		number = number * 10 + (*str - '0');
		str++;
	}
	return ((int)number * sign);
}
*/

int	ft_atoi(const char *str)
{
	int	number;
	int	kind;

	number = 0;
	kind = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		kind = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	if (kind % 2 == 1)
		return (-number);
	return (number);
}

