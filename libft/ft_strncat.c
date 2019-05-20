/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:27:40 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/08 15:41:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s1[i])
		++i;
	while (s2[k] && k < n)
	{
		s1[i + k] = s2[k];
		++k;
	}
	s1[k + i] = '\0';
	return (s1);
}
