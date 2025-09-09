/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:31:39 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/09 14:05:12 by csuomins         ###   ########.fr       */
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
	char	*temp;	

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	leitor_bytes = 1;
	if (!resto)
		resto = ft_strdup("");
	if (!resto)
	{
		free(buffer);
		return (NULL);
	}
	leitor_bytes = 1;
	while (!ft_strchr(resto, '\n') && leitor_bytes != 0)
	{
		leitor_bytes = read(fd, buffer, BUFFER_SIZE);
		if (leitor_bytes == -1)
		{
			free(buffer);
			free(resto);
			return (NULL);
		}
		buffer[leitor_bytes] = '\0';
		temp = ft_strjoin(resto, buffer);
		free(resto);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
		resto = temp;
	}
	free(buffer);
	return (resto);
}

char	*get_next_line(int fd)
{
	static char		*resto;
	char			*linha;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	resto = lendo_fd(fd, resto);
	if (!resto)
		return (NULL);
	linha = extrai_linha(resto);
	resto = atualiza_resto(resto);
	return (linha);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*linha;

// 	// Abrir arquivo de teste
// 	fd = open("arquivo2.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Erro ao abrir arquivo");
// 		return (1);
// 	}

// 	// Ler linha por linha
// 	while ((linha = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", linha); // imprime a linha lida
// 		free(linha);          // libera memória da linha
// 	}

// 	// Fechar arquivo
// 	close(fd);
// 	return (0);
// }
