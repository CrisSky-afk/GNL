/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:31:39 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/23 19:12:28 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[i])
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

char	*read_accumulate(int fd, char *buff_read, char *new_buff)
{
	int		bytes_reader;
	char	*buffers_join;

	bytes_reader = 1;
	while (!ft_strchr(buff_read, '\n') && bytes_reader != 0)
	{
		bytes_reader = read(fd, new_buff, BUFFER_SIZE);
		if (bytes_reader == -1)
			return (free(buff_read), NULL);
		new_buff[bytes_reader] = '\0';
		buffers_join = ft_strjoin(buff_read, new_buff);
		if (!buffers_join)
			return (free(buff_read), NULL);
		free(buff_read);
		buff_read = buffers_join;
	}
	return (buff_read);
}

char	*read_from_fd(int fd, char *buffer)
{
	char	*size_buffer;

	size_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!size_buffer)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = read_accumulate(fd, buffer, size_buffer);
	free(size_buffer);
	return (buffer);
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
