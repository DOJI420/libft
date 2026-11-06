*This project has been created as part of the 42 curriculum by yibn-yah.*

LIBFT

DESCRIPTION

Libft is my own C library, built from scratch as part of the 42
curriculum. The goal is to re-implement common C standard library
functions, add some extra utility functions, and write a small linked list.
The result is a static library, libft.a, that I can reuse in later
projects.

The library contains:

  Part1: libc functions

    ft_isalpha    ft_isdigit    ft_isalnum    ft_isascii
    ft_isprint    ft_strlen     ft_memset     ft_bzero
    ft_memcpy     ft_memmove    ft_strlcpy    ft_strlcat
    ft_toupper    ft_tolower    ft_strchr     ft_strrchr
    ft_strncmp    ft_memchr     ft_memcmp     ft_strnstr
    ft_atoi       ft_calloc     ft_strdup

  Part2: extra functions

    ft_substr     ft_strjoin    ft_strtrim    ft_split
    ft_itoa       ft_strmapi    ft_striteri   ft_putchar_fd
    ft_putstr_fd  ft_putendl_fd ft_putnbr_fd

  Part3: linked list functions

    ft_lstnew       ft_lstadd_front   ft_lstsize    ft_lstlast
    ft_lstadd_back  ft_lstdelone      ft_lstclear   ft_lstiter
    ft_lstmap

The list functions use this node type. The content pointer can point to
any type of data:

    typedef struct s_list
    {
        void            *content;
        struct s_list   *next;
    }   t_list;


INSTRUCTIONS

Commands (run them in the folder that contains the Makefile):

    make
        Compiles every .c file into a .o file, then bundles all the .o
        files into the library libft.a. Same as "make all". If nothing
        changed, it does nothing.

    make all
        Same as "make".

    make clean
        Deletes all the .o object files. Keeps libft.a.

    make fclean
        Deletes the .o object files and also libft.a.

    make re
        Rebuilds everything from scratch: runs "make  fclean", then "make all".

To use the library in your own program, add this line at the top of your
source file:

    #include "libft.h"

    Gives your code access to all the libft function prototypes and the
    t_list type.

Then compile your program and link it with the library:

    cc -Wall -Wextra -Werror main.c -L. -lft -o my_program

    cc             the C compiler
    -Wall          turns on the common warnings
    -Wextra        turns on extra warnings
    -Werror        treats every warning as an error and stops the build
    main.c         your source file that uses libft
    -L.            tells the linker to look for libraries in the current
                   folder
    -lft           links the library named libft.a ("lib" and ".a" are
                   added automatically)
    -o my_program  names the resulting executable my_program

Run your program with:

    ./my_program

    Executes the program you just built.


RESOURCES

    - man pages for the original libc function
    (for example,"man 3 strlcpy" opens the manual page of strlcpy)
    - GNU Make manual:
      https://www.gnu.org/software/make/manual/make.html
    - The C Programming Language.

Use of AI: AI was used as a learning aid to explain concepts (header
files, self-referential structures, pointers and casting, Makefiles, functions, header file, etc...).

All library code was written and tested by me.
