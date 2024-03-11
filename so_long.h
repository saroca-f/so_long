/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:57:34 by saroca-f          #+#    #+#             */
/*   Updated: 2024/03/05 17:46:31 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include "./check_map/check_map.h"
# include "./structs.h"
# include "./printf/ft_printf.h"

//maps control
void		check_map(t_lst **line, int size, char **mat_map);
bool		check_map_elements(t_lst *line, int size);
void		error_map_elements(t_lst **lst);
void		error_map_size(t_lst **lst);
void		error_map_borders(t_lst **lst);
void		error_pasable(t_lst **lst, char **map);
void		error_imagen(t_game *gm);
bool		pass_cont(t_coord *p, t_counter *count, char **map, t_coord *size);
t_counter	*elements_counter(t_lst *line, int size);

//game
void		game_start(char **map);
t_game		game_define(char **map);
void		frame(t_game *gm);
void		ft_key(struct mlx_key_data key_data, void *param);
void		put_counter(t_game *game);
void		person_print(int j, int i, t_game *gm);

//mover_cases
void		void_case(int j, int i, t_game *game);
void		c_case(int j, int i, t_game *game);
void		e_case(int j, int i, t_game *game);
void		x_case(t_game *game);
void		p_to_right(t_game *gm);
void		p_to_left(t_game *gm);
void		p_to_up(t_game *gm);
void		p_to_down(t_game *gm);

//get_next_line
char		*ft_strchr(char *s, int c);
size_t		ft_strlen_2(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*static_maker(char *static_str, int fd);
char		*make_line(char *static_str, int i);
char		*new_static_maker(char *static_str);
char		*get_next_line(int fd);

//split
char		**ft_split(char const *s, char c, char const *s0);
size_t		ft_strlen2(const char *str);

//utils
t_coord		size_map(char **map);
size_t		ft_strlen(char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
int			line_size(int fd);
char		**mat_constructor(t_lst *map, int size);
char		*ft_itoa(int n);

//lst utils
void		do_map(t_lst **map, char *argv);
int			ft_lstsize(t_lst *lst);

//Memory control
void		free_lst(t_lst **map);
void		free_mat(char **mat);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

#endif