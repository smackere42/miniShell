/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smackere <smackere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:22:41 by smackere          #+#    #+#             */
/*   Updated: 2022/09/22 04:13:53 by smackere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	var_iteration(int flag, char *command)
{
	int		i;
	int		j;
	char	sym;

	i = 0;
	j = 0;
	while (command[i] != '\0')
	{
		sym = command[i];
		if ((ft_isdigit(sym) || ft_isalpha(sym)) && j == 0)
			++i;
		else if (sym == '=' && j == 0)
			j = i;
		else if (sym == '\n' || sym == '\t' || sym == ' ')
			return (0);
		else
			++i;
	}
	if (flag == 1)
		return (i);
	if (flag == 2)
		return (j);
	else
		return (0);
}

t_list	*list_iteration(t_list *temp, int i, int j, char **variable)
{
	while (temp != NULL)
	{
		if (ft_strncmp(((char **)temp->content)[0], variable[0], j - i)
			== 0)
		{
			free(((char **)temp->content)[0]);
			free(((char **)temp->content)[1]);
			free(temp->content);
			temp->content = (struct t_list *) variable;
			return (NULL);
		}
		temp = temp->next;
	}
	return (temp);
}

char	*var_replace_counter(t_list *var, char *r, char *tmp, char *res)
{
	while (var != NULL)
	{
		if (ft_strncmp(((char **)var->content)[0], tmp,
			ft_strlen(tmp)) == 0)
		{
			r = (char *) easy_addp(ft_strjoin(res,
						((char **)var->content)[1]));
			free(res);
			res = r;
			break ;
		}
		var = var->next;
	}
	return (res);
}

char	*string_move(char *right)
{
	while (*right != '\0' && *right != ' ' && *right != '\t'
		&& *right != '\n' && *right != '$')
	++right;
	return (right);
}
