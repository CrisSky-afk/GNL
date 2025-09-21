/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:36:07 by cris_sky          #+#    #+#             */
/*   Updated: 2025/09/20 14:39:56 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX_FD 1024

char        *extract_line(char *buffer);
char        *update_buffer(char *buffer);
void		*ft_memcpy(void *dest, const void *src, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char        *read_accumulate(int fd, char *accumulated, char *temp_buffer);
char        *read_from_fd(int fd, char *saved_data);
char		*get_next_line(int fd);

#endif