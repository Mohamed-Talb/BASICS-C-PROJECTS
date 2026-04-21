
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				data;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
	int				pos;
	int				rank;
	int				abovemed;
}	t_stack;

typedef struct s_flags
{
	bool	charflag;
	bool	doubleflag;
}	t_flags;

// 		LIBFTUTILST
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr, t_flags *params);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// 		LINKED LIST
int		lstsize(t_stack **Root);
void	lstclear(t_stack**Root);
void	lstaddback(t_stack **Root, int content);

//       THE OPERATIONS:
void	swap(t_stack **Root, char option, bool print);
void	rotate(t_stack **Root, char option, bool print);
void	ss(t_stack **RootA, t_stack **RootB, bool print);
void	rr(t_stack **RootA, t_stack **RootB, bool print);
void	rrr(t_stack **RootA, t_stack **RootB, bool print);
void	reverserotate(t_stack **Root, char option, bool print);
void	push(t_stack **RootA, t_stack **RootB, char option, bool print);

//		SORTFUNCTIONS:
char	*getnextline(int fd);
void	sorttwo(t_stack **RootA);
void	sortthree(t_stack **RootA);
t_stack	*cheapest(t_stack **Root);
void	bigsort(t_stack **RootA, t_stack **RootB);
void	cost(t_stack **SrcStack, t_stack **DestStack);
int		parsing(int ac, char **argv, t_stack **RootA);
void	closestbigger(t_stack **RootA, t_stack **RootB);
void	setintop(t_stack *curr, t_stack **cstack, t_stack **tstack);

//UTILS 
void	rank(t_stack **stack);
bool	issorted(t_stack **RootA);
t_stack	*findmin(t_stack **Root);
void	settozero(t_stack **tstack);
void	markabovemedian(t_stack **Root);
#endif 