/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre-f <eandre-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 05:47:35 by eandre-f          #+#    #+#             */
/*   Updated: 2022/07/08 16:59:12 by eandre-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char **acc)
{
	size_t	c;
	char	*s;
	char	*r;

	if (*acc == NULL)
		return (NULL);
	c = (size_t)(ft_strchr(*acc, '\n') - *acc) + 1;
	s = ft_substr(*acc, 0, c);
	r = ft_substr(*acc, c, ft_strlen(*acc));
	ft_strupd(acc, r);
	if (*acc[0] == '\0')
		ft_strupd(acc, NULL);
	return (s);
}

static void	read_line(int fd, char **acc, char *buffer, int *read_bytes)
{
	*read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (*read_bytes > 0)
	{
		if (*acc == NULL)
			*acc = ft_strdup("");
		buffer[*read_bytes] = '\0';
		ft_strupd(acc, ft_strjoin(*acc, buffer));
		while (*read_bytes > 0 && ft_strchr(buffer, '\n') == NULL)
		{
			*read_bytes = read(fd, buffer, BUFFER_SIZE);
			buffer[*read_bytes] = '\0';
			ft_strupd(acc, ft_strjoin(*acc, buffer));
		}
	}
}

static t_list	*get_node(t_list **lst, int fd)
{
	t_list	*node;
	t_list	*new;

	node = *lst;
	if (node != NULL)
		while (node != NULL && node->fd != fd)
			node = node->next;
	if (node != NULL)
		return (node);
	new = (t_list *) malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = NULL;
	new->fd = fd;
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		node = *lst;
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	return (new);
}

static void	free_acc(t_list **lst)
{
	t_list	*node;
	t_list	*temp;

	node = *lst;
	while (node != NULL && node->content == NULL)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	*lst = node;
	while (node != NULL)
	{
		temp = node->next;
		if (temp != NULL && temp->content == NULL)
		{
			node->next = temp->next;
			free(temp);
		}
		else
			node = temp;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*acc = NULL;
	t_list			*node;
	char			*buffer;
	char			*line;
	int				read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_node(&acc, fd);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_line(fd, &node->content, buffer, &read_bytes);
	line = get_line(&node->content);
	free(buffer);
	free_acc(&acc);
	return (line);
}
