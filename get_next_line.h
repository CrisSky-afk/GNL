/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cris_sky <cris_sky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:15:50 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/07 19:33:03 by cris_sky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char        *extrai_linha(char *resto);
char        *atualiza_resto(char *resto);
void        *ft_memcpy(void *dest, const void *src, size_t n);
size_t      ft_strlen(const char *s);
char        *ft_strdup(const char *s);

#endif