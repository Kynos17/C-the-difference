/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 13:52:34 by marvin            #+#    #+#             */
/*   Updated: 2026/10/28 13:52:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	put_error(char *inputerror)
{
	while (*inputerror != '\0')
	{
		write(2, inputerror, 1);
		inputerror++;
	}
	return (1);
}

int    ft_atoi(char *str)
{
    int    i;
    int    sign;
    int    value;

    i = 0;
    sign = 1;
    value = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' || (str[i] >= 7 && str[i] <= 13))
            i++;
        if (str[i] == '-')
            sign *= -1;
        if (str[i] >= '0' && str[i] <= '9')
        {
            while ((str[i] >= '0' && str[i] <= '9') && str[i])
            {
                value = (value * 10) + (str[i] - '0');
                i++;
            }
            return (value * sign);
        }
        i++;
    }
    return (value);
}

void    ft_putnbr(int nb)
{
    int    towrite;

    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = nb * -1;
    }
    if (nb >= 0 && nb <= 9)
    {
        towrite = nb + '0';
        write(1, &towrite, 1);
    }
    else
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}

int ft_calc(int a, int b, char c)
{
    if (c == '+')
        return (a + b);
    else if (c == '-')
        return (a - b);
    else if (c == '*')
        return (a * b);
    else if (c == '/')
        return (a / b);
    else if (c == '%')
        return (a % b);
    else
        return (0);
}

int	ft_check_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 4)
		return (put_error("Error: usage ./a.out <int> <sign> <int>.\n"));
    if (ft_check_nbr(argv[1]) == 0)
	    return (put_error("Error: arg 1 must be a number.\n"));

}










