/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpenzko <chpenzko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:14:32 by chpenzko          #+#    #+#             */
/*   Updated: 2022/07/29 13:14:03 by chpenzko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_and_save(fd, save);
	line = ft_line(save);
	save = ft_save_rest(save);
	if (line[0] != '\0')
		return (line);
	free (save);
	free (line);
	return (NULL);
}

char	*ft_read_and_save(int fd, char	*save)
{
	char	*buffer;
	int		read_char;

	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_char = 1;
	while (read_char != 0)
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
	line = (char *) malloc ((i + 2) * sizeof (char));
	if (!line)
	{
		return (NULL);
	}
	ft_strlcpy(line, save, i + 1);
	if (save[i] == '\n')
		line[i] = save[i];
	line[++i] = '\0';
	return (line);
}

char	*ft_save_rest(char	*save)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] != '\n')
	{
		free (save);
		return (NULL);
	}	
	rest = (char *) malloc (sizeof(char) * (ft_strlen(save) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (save[i] != '\0')
		rest[j++] = save[i++];
	rest[j] = '\0';
	free (save);
	if (rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

// // int main()
// {
// 	int fd;
// 	int i;
// 	static int j;
// 	fd = open("text.txt",O_RDONLY);
// 	// fd = open("./Tester/files/multiple_line_with_nl",O_RDONLY);
// 	i = 0;
// 	j = 0;
// 	char *string;
// 		// get_next_line(fd);
// 		string = get_next_line(fd);
// 		printf("Zeile 1: %s\n", string);
// 		free(string);
// 		string = get_next_line(fd);
// 		printf("Zeile 2: %s\n", string);
// 		free(string);
// 		string = get_next_line(fd);
// 		printf("Zeile 3: %s\n", string);
// 		free(string);
// 		string = get_next_line(fd);
// 		printf("Zeile 4: %s\n", string);
// 		free(string);
// 		string = get_next_line(fd);
// 		printf("Zeile 5: %s\n", string);
// 		free(string);
// 		// string = get_next_line(fd);
// 		// printf("Zeile 6: %s\n", string);
// 		// free(string);
// 		// string = get_next_line(fd);
// 		// printf("Zeile 7: %s\n", string);
// 		// free(string);
// 		// string = get_next_line(fd);
// 		// printf("Zeile 8: %s\n", string);
// 		// free(string);
// 		// string = get_next_line(fd);
// 		// printf("Zeile 9: %s\n", string);
// 		// free(string);
// 	system("leaks a.out");
// }