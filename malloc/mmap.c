#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>


int main(int ac, char **av)
{
    int nb;
    int i;
    char *str;
    char c;

    if (ac == 3) 
    {
        nb = atoi(av[2]);
        c = av[1][0];
        str = (char*)mmap(0,nb + 1, PROT_READ | PROT_WRITE,
                            MAP_ANON | MAP_PRIVATE, -1, 0);
        i = 0;
        while (i < nb)
            str[i++] = c;
        str[i] = '\0';
        i = getpagesize();
        printf("%s\n%d\n", str, i);
    }
    return (0);
}