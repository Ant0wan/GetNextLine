/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:57:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/20 11:18:07 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	i = -1;
	cpy = (char*)ft_memalloc(sizeof(*cpy) * len + 1);
	if (!cpy || !s)
		return (NULL);
	while (++i < len)
		cpy[i] = s[start + i];
	cpy[i] = '\0';
	return (cpy);
}
