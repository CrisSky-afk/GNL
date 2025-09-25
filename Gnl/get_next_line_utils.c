/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csuomins <csuomins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:43:24 by csuomins          #+#    #+#             */
/*   Updated: 2025/09/25 11:45:05 by csuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*size;
	int		len;

	len = ft_strlen((char *)s);
	size = (char *)malloc(sizeof(char) * (len + 1));
	if (!size)
		return (NULL);
	ft_memcpy(size, s, len);
	size[len] = '\0';
	return (size);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	target;

	i = 0;
	target = (unsigned char)c;
	while (str[i] != '\0')
	{
		if (str[i] == target)
			return ((char *)(str + i));
		i++;
	}
	if (target == '\0')
		return ((char *)(str + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_total;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len_total = len1 + len2;
	new_str = (char *)malloc(sizeof(char) * (len_total + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy((new_str + len1), s2, len2);
	new_str[len_total] = '\0';
	return (new_str);
}

/*int main (void) // main do memcpy
{
    char str1[20] = "testando memcpy";
    char str2[sizeof(str1)];
    char *result  = ft_memcpy(str2, str1, 4);
    printf("%s\n", result);
    return (0);
}
*/

/* int main (void) // main ft_strlen
{
    char *str1 = "Hoje é um novo dia de um novo tempo que começou";
    size_t result = ft_strlen(str1);
    printf("%li\n", result);
    return (0);
} */

// int main(void)
// {
//     char *str1 = "fazendo o teste da bagaça";
//     char *ptr = ft_strdup(str1);

//     printf("Conteúdo copiado: %s\n", ptr);   // mostra a string duplicada
//     printf("Endereço novo  : %p\n", (void *)ptr); // mostra o ponteiro novo
//     printf("Endereço original: %p\n", (void *)str1);// compara com o original

//     free(ptr); // boa prática: libera a memória alocada
//     return 0;
// }