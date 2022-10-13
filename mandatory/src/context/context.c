/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:22:00 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/13 22:23:31 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"

static void	get_variables(char **envp)
{
	int		i;
	char	**variable;

	i = 0;
	while (envp[i])
	{
		variable = (char **) easy_alloc(sizeof(char *) * 2);
		variable[0] = (char *) add_p(ft_substr(envp[i], 0,
					ft_strchr(envp[i], '=') - envp[i]));
		variable[1] = (char *) add_p(ft_substr(envp[i],
					ft_strchr(envp[i], '=') - envp[i] + 1, ft_strlen(envp[i])));
		if (g_con->variables == NULL)
			g_con->variables = (struct t_list *) add_p(ft_lstnew(variable));
		else
		{
			if (check_repeat(variable))
			{
				ft_lstadd_front((t_list **)&(g_con->variables),
					(t_list *) add_p(ft_lstnew(variable)));
			}
		}
		++i;
	}
}

void	init_context(char **envp)
{
	g_con = (t_context *) malloc(sizeof(t_context));
	g_con->envp = envp;
	g_con->pid = 0;
	g_con->last_exit_code = 0;
	g_con->pointers = NULL;
	g_con->variables = NULL;
	g_con->coms = NULL;
	g_con->last_cmd_name = "";
	g_con->path = get_path(envp);
	get_variables(envp);
}
