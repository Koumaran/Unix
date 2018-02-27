#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>
# include <stdio.h>

# define HEAP_SIZE (sizeof(t_heap))
# define PAGE_SIZE  (sizeof(t_page))
# define TINY_SIZE ((size_t)getpagesize() * 16)
# define SMALL_SIZE ((size_t)getpagesize() * 64)

# define PROT       PROT_READ | PROT_WRITE
# define MAP        MAP_ANONYMOUS | MAP_PRIVATE

typedef enum        e_type
{
    TINY,
    SMALL,
    LARGE
}                   t_type;

typedef struct      s_heap
{
    void            *ptr;
    size_t          size;
    int             free;
    struct s_heap   *next;
}                   t_heap;

typedef struct      s_page
{
    t_heap          *tiny_heap;
    t_heap          *small_heap;
    t_heap          *large_heap;
    size_t          type_size;
}                   t_page;

t_page              *g_page;

void        *malloc(size_t  size);
void     *ft_malloc(t_heap **heap, size_t size, t_type type);
t_heap      *ft_newheap(size_t size);
void    fill_info(t_heap **heap, size_t size);
void    fill_full(t_heap **heap, size_t size);
t_heap      *check_heap(t_heap **heap, t_type type, size_t size);
t_heap      *check_page(size_t size, t_type *type);

#endif