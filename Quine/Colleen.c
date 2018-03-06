#include <stdio.h>

void ft_func() {
char *s="#include <stdio.h>%c%cvoid ft_func() {%cchar *s=%c%s%c;%cprintf(s,10,10,10,34,s,34,10,10,10,10,10,10,10,10,10,10,10,10,10);%c}%c/*%c    commentaire 1%c*/%c%cint main() {%c/*%c    commentaire 2%c*/%cft_func();%c}%c";
printf(s,10,10,10,34,s,34,10,10,10,10,10,10,10,10,10,10,10,10,10);
}
/*
    commentaire 1
*/

int main() {
/*
    commentaire 2
*/
ft_func();
}
