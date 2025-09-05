/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_r_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:23:15 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/05 12:40:05 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int main (void)
{
	char	buffer[128];
	int		bytes;
	int		i;

	bytes = read(0, buffer, sizeof(buffer));
	i = 0;
	while (bytes > 0)
	{
		while (i < bytes)
		{
			write (1, &buffer[i], 1);
			i++;
			if (buffer[i] == '\n')
				return (0);
		}
	}

	return (0);
}
