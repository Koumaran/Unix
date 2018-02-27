#include "malloc.h"

t_heap      *check_heap(t_heap **heap, t_type type, size_t size)
{
    t_heap      *tmp;

    tmp = *heap;
    (void)type;
    (void)size;
    // ici faire la recherche du heap disponible;
    if (!tmp)
    {
        tmp = ft_newheap(g_page->type_size);
        *heap = tmp;
    }
    return (tmp);
}

t_heap      *check_page(size_t size, t_type *type)
{
    static t_page   *page;

    g_page = page;
    if (size <= TINY_SIZE)
    {
        *type = TINY;
        g_page->type_size = TINY_SIZE;
        return (g_page->tiny_heap);
    }
    if (size <= SMALL_SIZE)
    {
        *type = SMALL;
        g_page->type_size = SMALL_SIZE;
        return (g_page->small_heap);
    }
    *type = LARGE;
    g_page->type_size = size;
    return  (g_page->large_heap);
}