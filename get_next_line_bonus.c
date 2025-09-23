/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:38:23 by cris_sky          #+#    #+#             */
/*   Updated: 2025/09/23 11:57:46 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char	*new_buffer;
	int		i;
	int		buffer_len;
	int		remaining_len;

	i = 0;
	if (!buffer || !buffer[i])
		return (free(buffer), NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
		buffer_len = ft_strlen(buffer);
		remaining_len = buffer_len - i;
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
