/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:22:41 by smackere          #+#    #+#             */
/*   Updated: 2022/09/23 04:24:10 by kmumm            ###   ########.fr       */
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
			f_one(((char **)temp->content)[0]);
			f_one(((char **)temp->content)[1]);
			f_one(temp->content);
			temp->content = (struct t_list *) variable;
			return (NULL);
		}
		temp = temp->next;
	}
	return (temp);
}

char	*handle_extra(char *postfix, char *res)
{
	char	*tmp_res;
	char	*buffer;

	if (!postfix)
		return (res);
	if (postfix[0] == '?')
	{
		tmp_res = (char *) add_p(
				ft_strjoin(res, ft_itoa(g_context->last_exit_code)));
	}
	else if (postfix[0] == '\0' || postfix[0] == '.')
		tmp_res = (char *) add_p(ft_strjoin(res, "$"));
	if (postfix[0] == '.')
	{
		buffer = tmp_res;
		tmp_res = (char *) add_p(ft_strjoin(tmp_res, postfix));
		f_one(buffer);
	}
	f_one(res);
	return (tmp_res);
}

char	*replace_one(char *postfix, char *res)
{
	t_list	*variables;
	char	*tmp_res;

	variables = (t_list *)g_context->variables;
	tmp_res = res;
	while (variables != NULL)
	{
		if (ft_strncmp(((char **)variables->content)[0], postfix,
			ft_strlen(((char **)variables->content)[0])) == 0)
		{
			tmp_res = (char *) add_p(ft_strjoin(res,
						((char **)variables->content)[1]));
			break ;
		}
		variables = variables->next;
	}
	tmp_res = handle_extra(postfix, res);
	return (tmp_res);
}

char	*get_postfix(char **left)
{
	char	*right;
	char	*postfix;
	int		flag;

	right = *left + 1;
	flag = 1;
	if (*right == '\0' || *right == ' ' || *right == '\t'
		|| *right == '\n' || *right == '?')
	{
		++right;
		flag = 0;
	}
	while (flag && *right != '\0' && *right != ' ' && *right != '\t'
		&& *right != '\n' && *right != '$')
		++right;
	postfix = (char *) add_p(ft_substr(*left + 1, 0, right - *left));
	printf("postfix: %s\n", postfix);
	*left = right;
	return (postfix);
}
