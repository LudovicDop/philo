/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <ldoppler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:41:20 by ldoppler          #+#    #+#             */
/*   Updated: 2024/03/27 10:43:12 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_my_args(char **argv, int argc)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < argc - 1)
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j] >= '0' && argv[i][j] <= '9')
			{
				j++;
			}
			if (argv[i][j] != '\0')
				return (2);
			i++;
		}
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	ret;
	int	i;
	int	is_neg;

	is_neg = 1;
	i = 0;
	ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_neg = is_neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + str[i] - '0';
		i++;
	}
	return (ret * is_neg);
}