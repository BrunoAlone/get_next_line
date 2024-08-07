/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:58:35 by brolivei          #+#    #+#             */
/*   Updated: 2022/12/07 15:23:33 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_junction(char *buffer, char *container)
{
	char	*dst;

	dst = ft_strjoin(buffer, container);
	free(buffer);
	return (dst);
}

char	*ft_clipping_part(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	j = 0;
	i += 1;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	free(buffer);
	return (new_buffer);
}

char	*ft_shave_line(char *buffer)
{
	char	*shaved_line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	shaved_line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		shaved_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		shaved_line[i++] = '\n';
	return (shaved_line);
}

char	*ft_get_line_gross(int fd, char *buffer)
{
	char	*container;
	int		n_bytes_lidos;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	container = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	n_bytes_lidos = 1;
	while (n_bytes_lidos > 0)
	{
		n_bytes_lidos = read(fd, container, BUFFER_SIZE);
		if (n_bytes_lidos == -1)
		{
			free(container);
			free(buffer);
			return (NULL);
		}
		container[n_bytes_lidos] = '\0';
		buffer = ft_junction(buffer, container);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(container);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_line_gross(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_shave_line(buffer);
	buffer = ft_clipping_part(buffer);
	return (line);
}

int	main()
{
	int	fd;
	char	*line;

	fd = open("ola.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	return (0);
}
