/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:45:57 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/13 11:17:37 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*str;

	i = -1;
	if (s)
		len = ft_strlen(s);
	else
		return (NULL);
	str = (char*)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	while (s[++i] && &s[i] && f)
		str[i] = f(s[i]);
	str[i++] = '\0';
	return (str);
}
