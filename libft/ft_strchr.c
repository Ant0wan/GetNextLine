/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:41:16 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/22 14:27:09 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s)
		while ((s[i] || !c) && (c >= 0 && c <= 127))
		{
			if (s[i] == c)
				return ((char*)&s[i]);
			++i;
		}
	return (0);
}
