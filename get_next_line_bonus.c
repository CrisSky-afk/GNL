/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:38:23 by cris_sky          #+#    #+#             */
/*   Updated: 2025/09/22 12:14:25 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
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
	char	*new_buffer;
	int		i;

	i = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new_buffer = (char *)malloc(sizeof(char) * ((ft_strlen(buffer) - i) + 1));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	ft_memcpy(new_buffer, &buffer[i], ft_strlen(buffer) - i);
	new_buffer[ft_strlen(buffer) - i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*read_accumulate(int fd, char *accumulated, char *temp_buffer)
{
	int		leitor_bytes;
	char	*temp;

	leitor_bytes = 1;
	while (!ft_strchr(accumulated, '\n') && leitor_bytes != 0)
	{
		leitor_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (leitor_bytes == -1)
			return (free(accumulated), NULL);
		temp_buffer[leitor_bytes] = '\0';
		temp = ft_strjoin(accumulated, temp_buffer);
		free(accumulated);
		accumulated = temp;
		if (!temp)
			return (NULL);
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
	static char		*buffers[MAX_FD];
	char			*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffers[fd] = read_from_fd(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = extract_line(buffers[fd]);
	if (!line)
	{
		free(buffers[fd]);
		buffers[fd] = NULL;
		return (NULL);
	}
	buffers[fd] = update_buffer(buffers[fd]);
	return (line);
}
