/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:16:04 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/13 11:18:01 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	stat_strlen(char const *s)
{
	static unsigned int	len = 0;

	if (s && *s)
	{
		++len;
		return (stat_strlen(s + 1));
	}
	else if (s && !*s)
		return (len);
	return (0);
}

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*str;

	i = -1;
	if (s)
		len = stat_strlen(s);
	else
		return (NULL);
	str = (char*)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	while (++i < len && s[i] && &s[i] && f)
		str[i] = f(i, s[i]);
	str[i++] = '\0';
	return (str);
}
