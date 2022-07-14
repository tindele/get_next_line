/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpenzko <chpenzko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:14:32 by chpenzko          #+#    #+#             */
/*   Updated: 2022/07/14 14:33:10 by chpenzko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0  || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_and_save(fd, save);
	if(!save)
		return(NULL)
	line = ft_line(save);
	save = ft_save_rest(save);
	return (line);
}

char	*ft_read_and_save(int fd, char	*save)
{
	char	*buffer;
	int		read_char;

	buffer = (char	*) malloc ((BUFFER_SIZE + 1) * sizeof(char))
	if (!buffer)
		return (NULL);
	read_char = 1;
	while(!ft_strchr(save, '\n') && read_char != 0)
	{
		read_char = read(fd, buffer, BUFFER_SIZE);
		if (read_char == -1)
		{
			free(buffer);
			return (NULL);
		}
	buffer[read_char] = '\0';
	save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*ft_line(char *save)
{
	int		i;
	char	*line;

	if (!save)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = (char	*) malloc((i + 2)  * sizeof(char));
	if (!line)
	{
		return (NULL);
	}
	line = ft_strlcpy(line, save, i + 1);
	if(save[i] == '\n')
		line[i] == save[i];
	line[++i] = '\0';
	return (line);
}

char	*ft_save_rest(char	*save)
{
	int 	i;
	int		j;
	char	*rest;
	
	i = 0;
	if (!save)
		return (NULL);
	while(save[i] && save[i] != '\n')
		i++;
	if(save[i] != '\n')
	{
		free (save);
		return (NULL);
	}	
	rest = (char	*) malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if(!rest)
		return (NULL);
	i++;
	j = 0;
	while(save[i] != '\0')
	{
		rest[j++] = save[i++];
	}
	rest[j] = '\0';
	free (save);
	return (rest);
}

int main()
{
	char	next_line[40];

	next_line = get_next_line(text.txt);
	printf("%s", next_line);
}