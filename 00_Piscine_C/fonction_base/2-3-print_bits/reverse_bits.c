/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 23:00:21 by yarypert          #+#    #+#             */
/*   Updated: 2016/07/26 23:34:55 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

void    print_bits(unsigned char octet)
{
    int val;
    val = 1;
    while(val != 128)
    {
        if(octet / val == 1)
        {
            ft_putchar('1');
            octet = octet - val;
        }
        else
            ft_putchar('0');

        val = val * 2;
    }
}

int    main(void)
{
    print_bits(79);
}
