/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:15:50 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/22 22:16:24 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUFFER_SIZE 4096

char    *extract_line(char *buffer);
char        *update_buffer(char *buffer);
void        *ft_memcpy(void *dest, const void *src, size_t n);
size_t      ft_strlen(const char *s);
char        *ft_strdup(const char *s);
char        *ft_strchr(const char *str, int c);
char        *ft_strjoin(char const *s1, char const *s2);
char        *read_accumulate(int fd, char *accumulated, char *temp_buffer);
char        *read_from_fd(int fd, char *saved_data);
char        *get_next_line(int fd);

#endif
