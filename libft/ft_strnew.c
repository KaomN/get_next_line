/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conguyen <conguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:41:04 by conguyen          #+#    #+#             */
/*   Updated: 2021/11/27 15:10:09 by conguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** DESCRIPTION
** ft_strnew() function allocates with malloc(3) and returns a "fresh" string
** ending with ('\0'). Each character of the string is initialized as ('\0').
*/

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	else
	{
		ft_bzero(str, sizeof(*str) * size + 1);
		return (str);
	}
}
