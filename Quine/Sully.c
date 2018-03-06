#include <stdio.h>
#include <stdlib.h>

#define STR "#include <stdio.h>%c#include <stdlib.h>%c%c#define STR %c%s%c%cint main() {%cFILE *f;%cint n = %d;%cchar cmd[80];%cchar name[80];%cif (n > 0) {%csprintf(name, %cSully_%%d.c%c, --n);%cif ((f = fopen(name, %cw%c))) {%cfprintf(f,STR,10,10,10,34,STR,34,10,10,10,n,10,10,10,10,34,34,10,34,34,10,10,10,34,34,10,10,10);%cfclose(f);%csprintf(cmd, %cclang -Wextra -Wall -Werror -o Sully_%%d Sully_%%d.c; ./Sully_%%d%c, n, n, n);%csystem(cmd);%c}}}%c"
int main() {
FILE *f;
int n = 5;
char cmd[80];
char name[80];
if (n > 0) {
sprintf(name, "Sully_%d.c", --n);
if ((f = fopen(name, "w"))) {
fprintf(f,STR,10,10,10,34,STR,34,10,10,10,n,10,10,10,10,34,34,10,34,34,10,10,10,34,34,10,10,10);
fclose(f);
sprintf(cmd, "clang -Wextra -Wall -Werror -o Sully_%d Sully_%d.c; ./Sully_%d", n, n, n);
system(cmd);
}}}
