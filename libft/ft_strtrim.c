/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:04:41 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/10 16:32:26 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*cpy;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == '\t' || *s == ' ' || *s == '\n')
		++s;
	while (s[i])
		++i;
	i = i == 0 ? 0 : --i;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		--i;
	cpy = ft_strsub(s, 0, i + 1);
	return (cpy);
}
