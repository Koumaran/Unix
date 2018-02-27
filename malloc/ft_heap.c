#include "malloc.h"

t_heap      *ft_newheap(size_t size)
{
    t_heap     *heap;

    if (size <= 0)
        return (NULL);
    heap = (t_heap*)mmap(0, size, PROT, MAP, -1, 0);
    if (heap == MAP_FAILED)
        return (NULL);
    heap->ptr = (void*)heap + HEAP_SIZE;
    heap->size = size - HEAP_SIZE;
    heap->free = 1;
    heap->next = NULL;
    return (heap);
}