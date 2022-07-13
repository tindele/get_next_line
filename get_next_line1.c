/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpenzko <chpenzko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:16:12 by chpenzko          #+#    #+#             */
/*   Updated: 2022/07/13 17:31:27 by chpenzko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	
}

char	*ft_read_and_save(int fd, char	*save)
(
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
)

char	*ft_line(int fd, char save)
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
	
		
	
}