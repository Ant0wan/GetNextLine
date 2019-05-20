/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:39:26 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/14 09:58:07 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*string;
	int				i;
	unsigned int	cp;

	cp = n < 0 ? n * -1 : n;
	i = (n <= 0 ? 1 : 0);
	while (cp > 0)
	{
		cp = (cp - cp % 10) / 10;
		++i;
	}
	string = (char*)malloc(sizeof(char) * i + 1);
	if (!string)
		return (NULL);
	if (n <= 0)
		*string = n == 0 ? '0' : '-';
	string[i] = '\0';
	cp = n < 0 ? n * -1 : n;
	while (cp)
	{
		string[--i] = cp % 10 + 48;
		cp = (cp - cp % 10) / 10;
	}
	return (string);
}
