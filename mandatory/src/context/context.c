/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmumm <kmumm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:22:00 by kmumm             #+#    #+#             */
/*   Updated: 2022/10/11 08:34:11 by kmumm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "context.h"

static void get_variables(char **envp)
{
	int		i;
	char	**variable;
	
	i = 0;
	while (envp[i])
	{
		variable = (char **) easy_alloc(sizeof(char *) * 2);
		variable[0] = (char *) add_p(ft_substr(envp[i], 0, ft_strchr(envp[i], '=') - envp[i]));
		variable[1] = (char *) add_p(ft_substr(envp[i], ft_strchr(envp[i], '=') - envp[i] + 1, ft_strlen(envp[i])));
		if (g_context->variables == NULL)
			g_context->variables = (struct t_list *) add_p(ft_lstnew(variable));
		else
		{
			if (check_repeat(variable))
			ft_lstadd_front((t_list **)&(g_context->variables),
				(t_list *) add_p(ft_lstnew(variable)));
		}
		++i;
	}
}

void init_context(char **envp)
{
	g_context = (t_context *) malloc(sizeof(t_context));
	g_context->envp = envp;
	g_context->pid = 0;
	g_context->last_exit_code = 0;
	g_context->pointers = NULL;
	g_context->variables = NULL;
	g_context->commands = NULL;
	g_context->last_cmd_name = "";
	g_context->path = get_path(envp);
	get_variables(envp);
}