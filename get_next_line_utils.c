/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:31:35 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/07 19:32:04 by cris_sky         ###   ########.fr       */
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

size_t ft_strlen(const char *s)
{
    size_t  i;
    
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(const char *s)
{
    char    *size;
    int     len;

    len = ft_strlen((char *)s);
    size = (char *)malloc(sizeof(char) * (len + 1));
    if (!size)
        return (NULL);
    ft_memcpy(size, s, len);
    size[len] = '\0';
    return(size);
}

/*int main (void) // main do memcpy
{
    char str1[20] = "testando memcpy";
    char str2[sizeof(str1)];
    char *result  = ft_memcpy(str2, str1, 4);
    printf("%s\n", result);
    return (0);
}
*/

/* int main (void) // main ft_strlen
{
    char *str1 = "Hoje é um novo dia de um novo tempo que começou";
    size_t result = ft_strlen(str1);
    printf("%li\n", result);
    return (0);
} */

// int main(void)
// {
//     char *str1 = "fazendo o teste da bagaça";
//     char *ptr = ft_strdup(str1);

//     printf("Conteúdo copiado: %s\n", ptr);   // mostra a string duplicada
//     printf("Endereço novo  : %p\n", (void *)ptr); // mostra o ponteiro novo
//     printf("Endereço original: %p\n", (void *)str1);// compara com o original

//     free(ptr); // boa prática: libera a memória alocada
//     return 0;
// }