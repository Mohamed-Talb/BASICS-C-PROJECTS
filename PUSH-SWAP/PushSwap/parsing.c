
#include "pushswap.h"

static void	inptaddback(t_stack **Root, int content, t_flags *params)
{
	t_stack	*new_node;
	t_stack	*curr;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		lstclear(Root);
		exit(1);
	}
	(1) && (new_node->data = content, new_node->next = NULL);
	if (!*Root)
	{
		*Root = new_node;
		return ;
	}
	curr = *Root;
	while (curr->next)
	{
		if (curr->data == content)
			return (params->doubleflag = true, free(new_node));
		curr = curr->next;
	}
	if (curr->data == content)
		return (params->doubleflag = true, free(new_node));
	curr->next = new_node;
}

static int	handlestr(t_stack **Root, char *av, t_flags *params)
{
	char	**ptr;
	int		j;
	int		x;

	j = 0;
	ptr = ft_split(av, ' ');
	while (ptr[j])
	{
		x = ft_atoi(ptr[j], params);
		inptaddback(Root, x, params);
		if (params->charflag == true || params->doubleflag == true)
		{
			lstclear(Root);
			while (ptr[j])
			{
				free(ptr[j]);
				j++;
			}
			return (free(ptr), 1);
		}
		free(ptr[j]);
		j++;
	}
	return (free(ptr), 0);
}

static int	handlenbr(t_stack **Root, char *av, t_flags *params)
{
	int	x;

	x = ft_atoi(av, params);
	inptaddback(Root, x, params);
	if (params->charflag == true || params->doubleflag == true)
	{
		lstclear(Root);
		return (1);
	}
	return (0);
}

int	parsing(int ac, char **argv, t_stack **RootA)
{
	int		i;
	int		result;
	t_flags	params;

	i = 1;
	if (ac == 1)
		return (0);
	if (argv[1][0] == '\0')
		return (1);
	params.charflag = false;
	params.doubleflag = false;
	while (i < ac)
	{
		if (strchr(argv[i], ' '))
			result = handlestr(RootA, argv[i], &params);
		else if (!strchr(argv[i], ' '))
			result = handlenbr(RootA, argv[i], &params);
		if (result == 1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/*

✅ Valid Cases (Should Work)
	./push_swap 1 3 5 +9 20 -4 50 60 04 08
	./push_swap "3 4 6 8 9 74 -56 +495"
	./push_swap "95 99 -9 10 9"  # -9 and 9 are not considered duplicates
	./push_swap 2147483647 2 4 7
	./push_swap 99 -2147483648 23 545
	./push_swap "2147483647 843 56544 24394"
	./push_swap "1 2 4 3" 76 90 "348 05"

❌ Invalid Cases (Should Return "Error\n")

Non-Numeric Input
	./push_swap 1 3 dog 35 80 -3
	./push_swap a
	./push_swap 1 2 3 5 67b778 947
	./push_swap "12 4 6 8 54fhd 4354"
	./push_swap 1 -- 45 32

Duplicate Numbers
	./push_swap 1 3 58 9 3
	./push_swap 3 03
	./push_swap "49 128 50 38 49"

Out of Integer Range

./push_swap 54867543867438 3
./push_swap -2147483647765 4 5
./push_swap "214748364748385 28 47 29"

💡 Edge Case (Allowed)

	./push_swap "95 99 -9 10 9"  # Works because
		-9 and 9 are not considered duplicates



*/