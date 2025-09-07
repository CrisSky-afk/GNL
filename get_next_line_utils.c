/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:31:35 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/07 17:54:30 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char   *ptr_dest;
    unsigned char   *ptr_src;
    size_t          i;

    if (!dest && !src)
        return (NULL);
    ptr_dest = (unsigned char *)dest;
    ptr_src = (unsigned char *)src;
    i = 0;
    while (i < n)
    {
        ptr_dest[i] = ptr_src[i];
        i++;
    }
    return (dest);
}

/*int main (void)
{
    char str1[20] = "testando memcpy";
    char str2[sizeof(str1)];
    char *result  = ft_memcpy(str2, str1, 4);
    printf("%s\n", result);
    return (0);
}
*/