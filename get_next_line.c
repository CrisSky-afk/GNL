/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:31:39 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/08 14:37:21 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*extrai_linha(char *resto)
{
	int		i;
	char	*nova_linha;

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

char	*atualiza_resto(char *resto)
{
	char	*novo_resto;
	int		i;

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
	novo_resto = (char *)malloc(sizeof(char) * ((ft_strlen(resto) - i) + 1));
	if (!novo_resto)
		return (NULL);
	ft_memcpy(novo_resto, &resto[i], ft_strlen(resto) - i);
	novo_resto[ft_strlen(resto) - i] = '\0';
	free(resto);
	return (novo_resto);
}

char	*lendo_fd(int fd, char *resto)
{
	char	*buffer;
	int		leitor_bytes;	

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	leitor_bytes = 1;
	while (!ft_strchr(resto, '\n') && leitor_bytes != 0)
	{
		leitor_bytes = read(fd, buffer, BUFFER_SIZE);
		if (leitor_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[leitor_bytes] = '\0';
		resto = ft_strjoin(resto, buffer);
		if (!resto)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (resto);
}

char	*get_next_line(int fd)
{
	static char		*resto;
	char			*linha;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	resto = lendo_fd(fd, resto);
	if (!resto)
		return (NULL);
	linha = extrai_linha(resto);
	resto = atualiza_resto(resto);
	return (linha);
}

// int main (void)
// {
//     char *str1 = ft_strdup("hoje\né\num\nnovo\ndia\nde\num\nnovo\ntempo");
//     char *linha;
//     char *resto = str1;

//     linha = extrai_linha(resto);
//     printf("%s", linha);
//     free(linha);

//     resto = atualiza_resto(resto);
//     printf("%s", resto);  // apenas pra ver o que sobrou
//     free(resto);

// }

// int main(void)
// {
//     char *str1 = ft_strdup("hoje\né\num\nnovo\ndia\nde\num\nnovo\ntempo");
//     char *resto = str1;
//     char *linha;

//     while (resto)  // enquanto ainda houver resto
//     {
//         linha = extrai_linha(resto);
//         if (!linha)   // se não conseguir extrair, sai do loop
//             break;

//         printf("%s", linha);  // imprime a linha (com \n, se houver)
//         free(linha);

//         resto = atualiza_resto(resto);  // atualiza o resto
//     }

//     return 0;
// }

// int main(void)
// {
//     char *str = ft_strdup("hoje\né\num\nnovo\ndia\nde\num\nnovo\ntempo");
//     char *resto;
//     char *linha;

//     printf("=== Teste 1: extrai uma linha e imprime resto ===\n");
//     resto = ft_strdup(str); // duplicando a string para não alterar a original
//     linha = extrai_linha(resto);
//     printf("Linha extraída: %s", linha);  // imprime só a primeira linha
//     free(linha);

//     resto = atualiza_resto(resto);
//     printf("Resto depois da atualização:\n%s", resto); // imprime todo o resto de uma vez
//     free(resto);

//     printf("\n=== Teste 2: extrai todas as linhas em loop ===\n");
//     resto = ft_strdup(str);
//     while (resto)
//     {
//         linha = extrai_linha(resto);
//         if (!linha)
//             break;

//         printf("Linha extraída no loop: %s", linha);
//         free(linha);

//         resto = atualiza_resto(resto);
//     }

//     free(str);
//     return 0;
// }

