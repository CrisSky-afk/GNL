/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:31:39 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/07 17:52:01 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *extrai_linha(char *resto)
{
    int i;
    char *nova_linha;

    i = 0;
    if (!resto[i])
        return (NULL);
    while (resto[i] != '\0' && resto[i] != '\n')
        i++;
    nova_linha = (char *)malloc(sizeof(char) * (i + 2)); // +2 para \n e \0
    if (!nova_linha)
        return (NULL);
    ft_memcpy(nova_linha, resto, i);
    if (resto[i] == '\n')
    {
        nova_linha[i] = '\n';
        i++;
    }
    nova_linha[i] = '\0';
    return (nova_linha);
}

char *atualiza_resto(char *resto)
{
    char    *novo_resto;
    int     i;

    i = 0;
    if (!resto[i])
    {
        free(resto);
        return (NULL);
    }
    while (resto[i] != '\0' && resto[i] != '\n')
        i++;
    if (resto[i] == '\n')
        i++;
    novo_resto = (char *)malloc(sizeof(char) * (i + 1));
    if (!novo_resto)
        return (NULL);
    ft_memcpy(novo_resto, resto, i);
    novo_resto[i] = '\0';
    return (novo_resto);
}


int main (void)
{
    char *str1 = "hoje\né\num\nnovo\ndia\nde\num\nnovo\ntempo";
    char *str2 = extrai_linha(str1);
    printf("%s\n", str2);
    return (0);
}