/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:25:53 by mbourand          #+#    #+#             */
/*   Updated: 2021/03/15 15:25:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "sort.h"
#include "operations.h"

static void	sort_chunk(t_stack *a, t_stack *b, t_chunk chunk)
{
	int first;
	int last;
	int todo;

	while (a->size)
	{
		first = find_first_in_chunk(a, &chunk);
		last = find_last_in_chunk(a, &chunk);
		if (first == -1 || last == -1)
			break ;
		todo = (ft_min(first, a->size - first) <
			ft_min(last, a->size - last) ? first : last);
		put_on_top_of_a(a, b, todo);
		print_and_launch("pb", a, b);
	}
}

static void	three_sort(t_stack *a, t_stack *b)
{
	if (a->size != 3 || is_sorted(a))
		return ;
	if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2] && a->arr[2] > a->arr[0])
		print_and_launch("sa", a, b);
	else if (a->arr[0] > a->arr[1] && a->arr[1] > a->arr[2] &&
			a->arr[2] < a->arr[0])
	{
		print_and_launch("sa", a, b);
		print_and_launch("rra", a, b);
	}
	else if (a->arr[0] > a->arr[1] && a->arr[1] < a->arr[2] &&
		a->arr[2] < a->arr[0])
		print_and_launch("ra", a, b);
	else if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2] &&
			a->arr[2] > a->arr[0])
	{
		print_and_launch("sa", a, b);
		print_and_launch("ra", a, b);
	}
	else if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2] &&
			a->arr[2] < a->arr[0])
		print_and_launch("rra", a, b);
}

static void	big_sort(t_stack *a, t_stack *b)
{
	int		size_left;
	t_chunk	chunk;

	if (is_sorted(a))
		return ;
	size_left = a->size;
	chunk.size = ft_sqrt(a->size) * 1.5f;
	while (size_left > 0)
	{
		chunk.min = find_nth_smallest(a, a->size - size_left + 1);
		chunk.max = find_nth_smallest(a,
			ft_min(a->size, a->size - size_left + chunk.size));
		sort_chunk(a, b, chunk);
		size_left -= chunk.size;
	}
	while (b->size)
	{
		put_on_top_of_b(a, b, find_biggest(b));
		print_and_launch("pa", a, b);
	}
}

static void	small_sort(t_stack *a, t_stack *b)
{
	size_t	cnt;

	if (is_sorted(a))
		return ;
	while (a->size != 3)
		print_and_launch("pb", a, b);
	three_sort(a, b);
	while (b->size)
	{
		cnt = 0;
		while (b->arr[0] > find_nth_smallest(a, cnt + 1) && cnt < a->size)
			cnt++;
		put_on_top_of_a(a, b, cnt);
		print_and_launch("pa", a, b);
		put_on_top_of_a(a, b, find_nth_smallest_index(a, 1));
	}
}

void		sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (!is_sorted(a))
			print_and_launch("sa", a, b);
	}
	else if (a->size == 3)
		three_sort(a, b);
	else if (a->size < 8)
		small_sort(a, b);
	else
		big_sort(a, b);
}
