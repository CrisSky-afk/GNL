/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:31:39 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/22 22:03:31 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ARRUME O CABEÇALHO ANTES DE ENVIAR;

#include "get_next_line.h"

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, i);
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_buffer(char *buffer)
{
	char		*new_buffer;
	int			i;
	int			buffer_len;
	int			remaining_len;

	i = 0;
	if (!buffer || !buffer[i])
		return (free(buffer), NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	buffer_len = ft_strlen(buffer);
	remaining_len = buffer_len - i;
	if (remaining_len == 0)
		return (free(buffer), NULL);
	new_buffer = (char *)malloc(sizeof(char) * (remaining_len + 1));
	if (!new_buffer)
		return (free(buffer), NULL);
	ft_memcpy(new_buffer, &buffer[i], remaining_len);
	new_buffer[remaining_len] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*read_accumulate(int fd, char *accumulated, char *temp_buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(accumulated, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(accumulated), NULL);
		temp_buffer[bytes_read] = '\0';
		temp = ft_strjoin(accumulated, temp_buffer);
		if (!temp)
			return (free(accumulated), NULL);
		free(accumulated);
		accumulated = temp;
	}
	return (accumulated);
}

char	*read_from_fd(int fd, char *saved_data)
{
	char	*read_buffer;

	read_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	if (!saved_data)
		saved_data = ft_strdup("");
	saved_data = read_accumulate(fd, saved_data, read_buffer);
	free(read_buffer);
	return (saved_data);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_from_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = update_buffer(buffer);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*linha;

// 	// Abrir arquivo de teste
// 	fd = open("1-brouette.txt", O_RDONLY);
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
