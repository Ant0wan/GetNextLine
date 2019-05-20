/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 08:17:59 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/13 21:19:27 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i] == '-' ? -1 : 1;
		++i;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		if (nbr > nbr * 10 + str[i] - 48)
			return (sign == -1 ? 0 : -1);
		nbr = nbr * 10 + str[i] - 48;
		++i;
	}
	return (nbr * sign);
}
