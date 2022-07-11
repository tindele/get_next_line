/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpenzko <chpenzko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:14:32 by chpenzko          #+#    #+#             */
/*   Updated: 2022/07/11 13:35:03 by chpenzko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	int		char_count;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buffer)
		return (NULL);
	char_count = 1;
	while(!ft_strchr(save, '\n') && char_count != 0)
	{
		char_count = read(fd, buffer, BUFFER_SIZE);
		if (char_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[char_count] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char    *get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}