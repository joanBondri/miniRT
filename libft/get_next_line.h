/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbondri <jbondri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 09:55:42 by jbondri           #+#    #+#             */
/*   Updated: 2021/01/28 12:15:05 by jbondri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1000

int		is_n(char c);
char	*create_newline(char ***line);
int		assign(char ***line, char *x);
int		recurs(int fd, char **line);
int		get_next_line(int fd, char **line);
#endif
