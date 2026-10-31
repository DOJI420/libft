*This project has been created as part of the 42 curriculum by me.*

# Libft

## Description

Libft is the first project of the 42 curriculum. The goal is to build my own C library from scratch: re-implement a set of standard C library functions, add several useful utility functions, and provide a small linked list API. The result is a static library, `libft.a`, that I can reuse in all my later projects.

The project teaches how common libc functions work internally, how to manage memory manually (`malloc` / `free`), how to work with pointers and `void *`, how to write clean code under the 42 Norm, and how to automate builds with a Makefile.

### Library description

`libft.a` is a static archive of object files, built with `cc -Wall -Wextra -Werror` and exposed through a single header, `libft.h`. It is split into three parts.

#### Part 1: libc re-implementations

These behave like their standard counterparts, edge cases included.

| Function | Description |
|----------|-------------|
| `ft_isalpha` | Checks if a character is a letter |
| `ft_isdigit` | Checks if a character is a digit |
| `ft_isalnum` | Checks if a character is a letter or digit |
| `ft_isascii` | Checks if a value fits in the 0-127 ASCII range |
| `ft_isprint` | Checks if a character is printable |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills a memory area with a byte |
| `ft_bzero` | Sets a memory area to zero |
| `ft_memcpy` | Copies a memory area (areas must not overlap) |
| `ft_memmove` | Copies a memory area (safe for overlapping areas) |
| `ft_strlcpy` | Copies a string with a size limit, returns source length |
| `ft_strlcat` | Appends a string with a size limit, returns the length it tried to create |
| `ft_toupper` | Converts a letter to uppercase |
| `ft_tolower` | Converts a letter to lowercase |
| `ft_strchr` | Finds the first occurrence of a character in a string |
| `ft_strrchr` | Finds the last occurrence of a character in a string |
| `ft_strncmp` | Compares two strings up to `n` characters |
| `ft_memchr` | Finds a byte in a memory area |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Finds a substring within the first `n` characters of a string |
| `ft_atoi` | Converts a string to an integer |
| `ft_calloc` | Allocates zero-initialized memory |
| `ft_strdup` | Duplicates a string into newly allocated memory |

#### Part 2: additional functions

| Function | Description |
|----------|-------------|
| `ft_substr` | Returns a new string extracted from a string (start index and length) |
| `ft_strjoin` | Returns a new string made of two strings concatenated |
| `ft_strtrim` | Returns a copy of a string with given characters removed from both ends |
| `ft_split` | Splits a string by a delimiter into a NULL-terminated array of new strings |
| `ft_itoa` | Converts an integer to a newly allocated string |
| `ft_strmapi` | Applies a function to each character and returns the resulting new string |
| `ft_striteri` | Applies a function to each character (with its index) in place |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

#### Part 3: linked list functions

The list is built on this node type:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

`content` is a `void *`, so a node can hold any type of data.

| Function | Description |
|----------|-------------|
| `ft_lstnew` | Creates a new node with the given content |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstsize` | Counts the nodes in the list |
| `ft_lstlast` | Returns the last node of the list |
| `ft_lstadd_back` | Adds a node at the end of the list |
| `ft_lstdelone` | Frees one node's content with a given function, then the node |
| `ft_lstclear` | Deletes and frees a node and all the nodes after it |
| `ft_lstiter` | Applies a function to the content of every node |
| `ft_lstmap` | Creates a new list by applying a function to each node's content, cleaning up on allocation failure |

### Technical choices

- **Static library:** the code is archived with `ar rcs` so projects link it with `-lft`.
- **Header dependency in the Makefile:** object files depend on `libft.h`, so a header change triggers recompilation.
- **No relinking:** running `make` twice does nothing the second time.
- **Memory safety:** every function that allocates returns `NULL` on failure, and partially allocated results are freed (for example in `ft_split` and `ft_lstmap`).
- **Generic list content:** `void *` keeps the list type-agnostic, and the caller supplies functions (`del`, `f`) to handle the actual data.

## Instructions

### Compilation

Build the library from the root of the repository:

```bash
make
```

This compiles every source file with `cc -Wall -Wextra -Werror` and creates `libft.a`.

| Rule | Effect |
|------|--------|
| `make` / `make all` | Build `libft.a` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `libft.a` |
| `make re` | Full rebuild |

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Compile your program and link it against the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
./my_program
```

### Example

```c
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	**words;

	words = ft_split("hello from libft", ' ');
	if (words == NULL)
		return (1);
	printf("%s\n", words[1]);
	return (0);
}
```

Output: `from`

## Resources

### References

- `man` pages for the original functions (`man 3 strlcpy`, `man 3 memmove`, etc.)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- [GNU `ar` documentation](https://sourceware.org/binutils/docs/binutils/ar.html)
- *The C Programming Language*, Brian W. Kernighan and Dennis M. Ritchie
- [The 42 Norm](https://github.com/42School/norminette)

### Use of AI

AI was used only as a learning and review aid, never to write the final project code:

- **Concept explanations:** header files, self-referential structures, `.` vs `->`, `void *` and casting rules.
- **Makefile:** understanding how rules, pattern rules, variables and `.PHONY` work, and a line-by-line walkthrough of my Makefile.
- **Testing:** writing small `main` functions to test `ft_lstlast` and `ft_lstsize`, which are not part of the submitted library.
- **Code review:** checking my `ft_lstsize` and test code for mistakes.
- **Documentation:** drafting the structure of this README.

All library functions were written, tested and understood by me.
