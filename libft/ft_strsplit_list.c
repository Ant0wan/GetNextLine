/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:58:26 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/19 18:13:50 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_words(const char *s, char c)
{
	size_t	i;
	size_t	p;
	size_t	words_nb;

	p = 0;
	i = 0;
	words_nb = 0;
	while (s[i])
	{
		p = 0;
		if (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			p++;
			i++;
		}
		if (p != 0)
			words_nb += 1;
	}
	return (words_nb);
}

static char		*mallnwrite(char const *s, size_t *l, char c)
{
	size_t	k;
	char	*string;

	k = 0;
	while (s[*l] == c && s[*l])
		++*l;
	while (s[*l + k] != c && s[*l + k] && s[*l])
		++k;
	string = (char*)malloc(sizeof(string) * k + 1);
	if (!string)
		return (NULL);
	string[k] = '\0';
	k = 0;
	while (s[*l + k] != c && s[*l + k] && s[*l])
	{
		string[k] = s[*l + k];
		++k;
	}
	*l += k;
	return (string);
}

t_list			*ft_strsplit_list(char const *s, char c)
{
	size_t	nb;
	size_t	index;
	size_t	l;
	t_list	*lst;
	t_list	*beg_lst;

	if (s)
		nb = nb_words(s, c);
	else
		return (NULL);
	index = 0;
	l = 0;
	lst = ft_lstnew(mallnwrite(s, &l, c), 0);
	if (!lst)
		(NULL);
	beg_lst = lst;
	while (++index < nb)
	{
		lst->next = ft_lstnew(mallnwrite(s, &l, c), 0);
		lst = lst->next;
	}
	return (beg_lst);
}
