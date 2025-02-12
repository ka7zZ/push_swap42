/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtoint.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:35:19 by aghergut          #+#    #+#             */
/*   Updated: 2025/02/12 18:04:58 by aghergut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRTOINT_H
# define STRTOINT_H

# include "../strings/strings.h"
# include <limits.h>

//int to str
char	*ft_itoa(int n);
//str to int
int		ft_atoi(const char *str);

#endif