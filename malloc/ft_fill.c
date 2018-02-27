#include "malloc.h"

void    fill_info(t_heap **heap, size_t size)
{
    t_heap  *tmp;
    t_heap  *tmp2;
    t_heap  *next;

    tmp = *heap;
    next = tmp->next;
    tmp->next = (t_heap*)tmp->ptr + size;
    tmp2 = tmp->next;
    tmp2->size = tmp->size - size - HEAP_SIZE;
    tmp2->next = next;
    tmp2->ptr = (void*)tmp->next + HEAP_SIZE;
    tmp2->free = 1;
    tmp->free = 0;
    tmp->size = size;
}

void    fill_full(t_heap **heap, size_t size)
{
    t_heap  *tmp;

    tmp = *heap;
    tmp->size = size;
    tmp->free = 0;
}