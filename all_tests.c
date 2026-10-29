/* ************************************************************************** */
/*   all_tests.c : all the int main() tests from your libft, in one file      */
/*                                                                            */
/*   Each old main() is now test_ft_xxx(), and one main() at the bottom       */
/*   calls them all. Comment out any call in main() to skip a test.           */
/*                                                                            */
/*   Build (from your libft folder, after `make`):                            */
/*     cc all_tests.c -I. -L. -lft -lbsd -o run_tests && ./run_tests          */
/*   (-lbsd is only needed for the libc strlcat comparison; drop it if        */
/*    <bsd/string.h> isn't installed.)                                        */
/*                                                                            */
/*   Keep this file OUTSIDE your repo.                                        */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

#if defined(__has_include)
# if __has_include(<bsd/string.h>)
#  include <bsd/string.h>
#  define HAVE_BSD 1
# endif
#endif

/* ------------------------------ ft_atoi --------------------------------- */

static void	test_ft_atoi(void)
{
	printf("\n== ft_atoi ==\n");
	printf("%d\n", ft_atoi("67"));
	printf("%d\n", ft_atoi("-67"));
	printf("%d\n", ft_atoi("--67"));
	printf("%d\n", ft_atoi(" \t  -42069"));
	printf("%d\n", ft_atoi("69 00"));
}

/* ------------------------------ ft_bzero -------------------------------- */

static void	test_ft_bzero(void)
{
	char	s[] = "123456789";
	size_t	num = 5;
	size_t	i;

	printf("\n== ft_bzero ==\n");
	printf("before: %s\n", s);
	ft_bzero(s, num);
	printf("after: ");
	i = 0;
	while (i < sizeof(s) - 1)
	{
		if (s[i] == '\0')
			printf("0");
		if (s[i] != '\0')
			printf("%c", s[i]);
		i++;
	}
	printf("\n");
}

/* ------------------------------ ft_calloc ------------------------------- */

static void	test_ft_calloc(void)
{
	char	*str;
	size_t	len = 0;

	printf("\n== ft_calloc ==\n");
	str = ft_calloc(10, sizeof(char));
	while (len < 10 && str[len] == '\0')
	{
		printf("found one here: %zu\n", len);
		len++;
	}
	free(str);
}

/* ------------------------------- ft_itoa -------------------------------- */

static void	test_ft_itoa(void)
{
	int		i = -123;
	char	*res;

	printf("\n== ft_itoa ==\n");
	res = ft_itoa(i);
	printf("result: %s\n", res);
	free(res);
}

/* ------------------------------ ft_lstlast ------------------------------ */

static void	test_ft_lstlast(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	printf("\n== ft_lstlast ==\n");
	a.content = "wahaaaaad";
	a.next = &b;
	b.content = "joooooooj";
	b.next = &c;
	c.content = "tlataaaaa";
	c.next = NULL;
	printf("%s\n", (char *)ft_lstlast(&a)->content);
}

/* ------------------------------ ft_lstmap ------------------------------- */

static void	*double_it(void *c)
{
	int	*n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = *(int *)c * 2;
	return (n);
}

static void	test_ft_lstmap(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*tmp;
	int		a[3] = {1, 2, 3};
	int		i;

	printf("\n== ft_lstmap ==\n");
	lst = NULL;
	i = 0;
	while (i < 3)
		ft_lstadd_back(&lst, ft_lstnew(&a[i++]));
	new = ft_lstmap(lst, double_it, free);
	tmp = new;
	while (tmp)
	{
		printf("%d\n", *(int *)tmp->content);   // 2 4 6
		tmp = tmp->next;
	}
	ft_lstclear(&new, free);
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

/* ------------------------------ ft_lstnew ------------------------------- */

static void	test_ft_lstnew(void)
{
	t_list	*test_node;
	char	s[] = "we need to cook jessy!";

	printf("\n== ft_lstnew ==\n");
	test_node = ft_lstnew(s);
	printf("%s\n", (char *)test_node->content);
	free(test_node);
}

/* ------------------------------ ft_lstsize ------------------------------ */

static void	test_ft_lstsize(void)
{
	t_list	a;
	t_list	b;
	t_list	c;

	printf("\n== ft_lstsize ==\n");
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	printf("%u\n", ft_lstsize(&a));
}

/* ------------------------------ ft_memchr ------------------------------- */

static void	test_ft_memchr(void)
{
	char	s[] = "abcdefg";
	int		i = 'g';
	size_t	n = 10;
	char	*res;

	printf("\n== ft_memchr ==\n");
	res = ft_memchr(s, i, n);
	if (res)
		printf("%s\n", res);
	if (!res)
		printf("not found.\n");
}

/* ------------------------------ ft_memcmp ------------------------------- */

static void	test_ft_memcmp(void)
{
	char	s1[] = "abcdbf";
	char	s2[] = "abcdaf";
	size_t	n = 5;
	int		res;

	printf("\n== ft_memcmp ==\n");
	res = ft_memcmp(s1, s2, n);
	printf("%d\n", res);
}

/* ------------------------------ ft_memcpy ------------------------------- */
/* Your original called memcpy(NULL, NULL, 5) and ft_memcpy(NULL, NULL, 5),   */
/* which segfaults and would stop every test after it. This version copies    */
/* real buffers and compares your result with libc.                           */

static void	test_ft_memcpy(void)
{
	char	src[] = "maaanmaaan";
	char	dst[10];
	char	dst2[10];
	size_t	count = 5;

	printf("\n== ft_memcpy ==\n");
	memset(dst, 0, sizeof(dst));
	memset(dst2, 0, sizeof(dst2));
	memcpy(dst, src, count);
	ft_memcpy(dst2, src, count);
	printf("   memcpy res: %s\n", dst);
	printf("ft_memcpy res: %s\n", dst2);
}

/* ------------------------------ ft_memmove ------------------------------ */

static void	test_ft_memmove(void)
{
	char	src[] = "abcdefg";
	char	dest[10] = "123456g";
	char	dest2[10] = "123456g";
	size_t	num = 3;

	printf("\n== ft_memmove ==\n");
	ft_memmove(dest2, src, num);
	memmove(dest, src, num);
	printf("   memmove res: %s\n", dest);
	printf("ft_memmove res: %s\n", dest2);
}

/* ------------------------------ ft_memset ------------------------------- */

static void	test_ft_memset(void)
{
	char	str[] = "abcdefg";
	char	str2[] = "abcdefg";
	int		value = 'X';
	size_t	count = 1;

	printf("\n== ft_memset ==\n");
	ft_memset(str2, value, count);
	memset(str, value, count);
	printf("ft_memset res: %s\n", str2);
	printf("   memset res: %s\n", str);
}

/* ----------------------------- ft_putnbr_fd ----------------------------- */
/* Your original used fd = 0 (stdin); fd 1 (stdout) is the usual choice.      */

static void	test_ft_putnbr_fd(void)
{
	int	i = -2147483648;
	int	fd = 1;

	printf("\n== ft_putnbr_fd ==\n");
	fflush(stdout);
	ft_putnbr_fd(i, fd);
	write(1, "\n", 1);
}

/* ------------------------------ ft_split -------------------------------- */

static void	test_ft_split(void)
{
	char	**str;
	int		i = 0;

	printf("\n== ft_split ==\n");
	str = ft_split("hello world 42", ' ');
	while (str[i] != NULL)
	{
		printf("%s\n", str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}

/* ------------------------------ ft_strchr ------------------------------- */

static void	test_ft_strchr(void)
{
	char	s[] = "understanding";
	char	*res;
	char	*expected;

	printf("\n== ft_strchr ==\n");
	res = ft_strchr(s, 't');
	expected = strchr(s, 't');
	printf("mine:     %s\n", res);
	printf("expected: %s\n", expected);
}

/* ------------------------------ ft_strdup ------------------------------- */

static void	test_ft_strdup(void)
{
	char	s[] = "ana hwa ana";
	char	*mine;
	char	*expected;

	printf("\n== ft_strdup ==\n");
	mine = ft_strdup(s);
	expected = strdup(s);
	printf("%s\n", mine);
	printf("%s\n", expected);
	free(mine);
	free(expected);
}

/* ----------------------------- ft_striteri ------------------------------ */

static void	make_upper_iteri(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void	test_ft_striteri(void)
{
	char	s[] = "abcdefgh";

	printf("\n== ft_striteri ==\n");
	ft_striteri(s, make_upper_iteri);
	printf("%s\n", s);
}

/* ------------------------------ ft_strjoin ------------------------------ */

static void	test_ft_strjoin(void)
{
	char	s1[] = "1+1=";
	char	s2[] = "2";
	char	*res;

	printf("\n== ft_strjoin ==\n");
	res = ft_strjoin(s1, s2);
	printf("%s\n", res);
	free(res);
}

/* ------------------------------ ft_strlcat ------------------------------ */

static void	test_ft_strlcat(void)
{
	char	d1[10] = "abc";
	char	d2[10] = "abc";

	printf("\n== ft_strlcat ==\n");
	printf("%zu\n", ft_strlcat(d1, "12345", -10));
#ifdef HAVE_BSD
	printf("%zu\n", strlcat(d2, "12345", -10));
#else
	(void)d2;
	printf("(libc strlcat not available: <bsd/string.h> missing)\n");
#endif
}

/* ------------------------------ ft_strlcpy ------------------------------ */

static void	test_ft_strlcpy(void)
{
	char	s1[] = "hellooo";
	char	s2[10];
	size_t	size = 5;
	size_t	res;

	printf("\n== ft_strlcpy ==\n");
	res = ft_strlcpy(s2, s1, size);
	printf("%zu\n", res);
}

/* ------------------------------ ft_strlen ------------------------------- */

static void	test_ft_strlen(void)
{
	char	str[] = "1234567890";
	size_t	x;

	printf("\n== ft_strlen ==\n");
	x = ft_strlen(str);
	printf("%zu\n", x);
}

/* ------------------------------ ft_strmapi ------------------------------ */

static char	make_upper_mapi(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	test_ft_strmapi(void)
{
	char	s[] = "asdfghjkl";
	char	*res;

	printf("\n== ft_strmapi ==\n");
	res = ft_strmapi(s, make_upper_mapi);
	if (res)
		printf("%s\n", res);
	free(res);
}

/* ------------------------------ ft_strncmp ------------------------------ */

static void	test_ft_strncmp(void)
{
	char	s1[] = "abce";
	char	s2[] = "abcd";
	int		res;
	size_t	n = 3;

	printf("\n== ft_strncmp ==\n");
	res = ft_strncmp(s1, s2, n);
	printf("%d\n", res);
}

/* ------------------------------ ft_strnstr ------------------------------ */

static void	test_ft_strnstr(void)
{
	char	big[] = "understanding";
	char	little[] = "d";
	char	*res;
	size_t	len = 3;

	printf("\n== ft_strnstr ==\n");
	res = ft_strnstr(big, little, len);
	printf("%s\n", res);
}

/* ------------------------------ ft_strrchr ------------------------------ */

static void	test_ft_strrchr(void)
{
	char	s[] = "boomba";
	int		c = 'm';
	char	*i;

	printf("\n== ft_strrchr ==\n");
	i = ft_strrchr(s, c);
	printf("%s\n", i);
}

/* ------------------------------ ft_substr ------------------------------- */

static void	test_ft_substr(void)
{
	char			s[] = "1234567890";
	unsigned int	start = 0;
	size_t			len = 10;
	char			*res;

	printf("\n== ft_substr ==\n");
	res = ft_substr(s, start, len);
	printf("%s\n", res);
	printf("length of the string: %zu\n", ft_strlen(s));
	free(res);
}

/* --------------------------------- main --------------------------------- */

int	main(void)
{
	test_ft_atoi();
	test_ft_bzero();
	test_ft_calloc();
	test_ft_itoa();
	test_ft_lstlast();
	test_ft_lstmap();
	test_ft_lstnew();
	test_ft_lstsize();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_memset();
	test_ft_putnbr_fd();
	test_ft_split();
	test_ft_strchr();
	test_ft_strdup();
	test_ft_striteri();
	test_ft_strjoin();
	test_ft_strlcat();
	test_ft_strlcpy();
	test_ft_strlen();
	test_ft_strmapi();
	test_ft_strncmp();
	test_ft_strnstr();
	test_ft_strrchr();
	test_ft_substr();
	return (0);
}
//cc all_tests.c -I. -L. -lft -lbsd -o run_tests && ./run_tests
