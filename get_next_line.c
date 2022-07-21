/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpenzko <chpenzko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:14:32 by chpenzko          #+#    #+#             */
/*   Updated: 2022/07/21 14:28:26 by chpenzko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	// printf("TEST1\n");
	save = NULL;
	if (fd < 0  || BUFFER_SIZE <= 0)
		return (NULL);
	// printf("TEST2\n");
	save = ft_read_and_save(fd, save);
	
	if(!save)
		return(NULL);
	line = ft_line(save);
	save = ft_save_rest(save);
	return (line);
}

char	*ft_read_and_save(int fd, char	*save)
{
	char	*buffer;
	int		read_char;

	buffer = (char	*) malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	// printf("TEST3\n");
	read_char = 1;
	// printf("TEST4\n");
	while(read_char != 0)
	// while(!ft_strchr(save, '\n') && read_char != 0)
	{
		// printf("TEST5\n");
		read_char = read(fd, buffer, BUFFER_SIZE);
		// printf("%s",buffer);
		// printf("TEST6\n");
		if (read_char == -1)
		{
			free(buffer);
			return (NULL);
		}
	buffer[read_char] = '\0';
	// printf("%s",buffer);
	printf("Buffer len: %i\n",ft_strlen(buffer));
	save = ft_strjoin(save, buffer);
	printf("Save len: %i\n",ft_strlen(buffer));
	// printf("%s",save);
	// printf("TEST7\n");
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
	ft_strlcpy(line, save, i + 1);
	if(save[i] == '\n')
		line[i] = save[i];
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
	// char	next_line[40];
	int fd;
	int i;
	
	fd = open("text.txt",O_RDONLY);
	i = 0;
	while(i < 3)
	{
		
		printf("%s",get_next_line(fd));
		i++;
	}
	// system("leaks a.out");
	
	
	// printf()
	// next_line = get_next_line(fd);
	// printf("%s", next_line);
	// get_next_line(fd);
	printf("%s", get_next_line(fd));
}