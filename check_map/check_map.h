/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:08:58 by saroca-f          #+#    #+#             */
/*   Updated: 2024/02/29 18:27:43 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_counter
{
	int		exit;
	int		collect;
	int		heroe;
}	t_counter;

typedef struct s_lst
{
	char				*line;
	struct s_lst		*next;
}	t_lst;