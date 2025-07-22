/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:29:13 by salsoysa          #+#    #+#             */
/*   Updated: 2025/04/30 13:29:17 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rr(t_ps **stack_a, t_ps **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(stack_a, stack_b, 0);
	}
}

static void	r(t_ps **stack_a, t_ps **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(stack_a, stack_b, 0);
	}
}

static void	rot_a(t_ps **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ft_ra(stack, 0);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			ft_rra(stack, 0);
		}
	}
}

static void	rot_b(t_ps **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ft_rb(stack, 0);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			ft_rrb(stack, 0);
		}
	}
}

void	ft_move(t_ps **stack_a, t_ps **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rr(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		r(stack_a, stack_b, &cost_a, &cost_b);
	rot_a(stack_a, &cost_a);
	rot_b(stack_b, &cost_b);
	ft_pa(stack_a, stack_b, 0);
}
