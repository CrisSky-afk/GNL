/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:59:31 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/05 12:14:14 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main (void)
{
	int fd = open ("arquivo.txt", O_WRONLY | O_CREAT, 0644);

	if (fd == -1)
		return (1);
	write (fd, "Hello word\n", 11);

	close (fd);
	return (0);
}
