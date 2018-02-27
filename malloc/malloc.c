#include "malloc.h"

void     *ft_malloc(t_heap **heap, size_t size, t_type type)
{
    t_heap  *tmp;

    if ((tmp = check_heap(heap, type, size)) == NULL)
        return (NULL);
    if (tmp->size == size)
        fill_full(&tmp, size);
    else
        fill_info(&tmp, size);
    return (tmp->ptr);
}


void        *malloc(size_t  size)
{
    t_heap          *ptr;
    t_type     type;
    

    if (size <= 0)
        return (NULL);
    ptr = check_page(size, &type);
    return (ft_malloc(&ptr, size, type));
}