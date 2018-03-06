#include <stdio.h>
/*
    Zero difference
*/
#define STR "#include <stdio.h>%c/*%c    Zero difference%c*/%c#define STR %c%s%c%c#define FPRINTF(f) fprintf(f,STR,10,10,10,10,34,STR,34,10,10,34,34,34,34,10,10)%c#define FT(x) int main() { FILE *f; if ((f = fopen(%cGrace_kid.c%c, %cw%c))) { FPRINTF(f); }}%cFT(x)%c"
#define FPRINTF(f) fprintf(f,STR,10,10,10,10,34,STR,34,10,10,34,34,34,34,10,10)
#define FT(x) int main() { FILE *f; if ((f = fopen("Grace_kid.c", "w"))) { FPRINTF(f); }}
FT(x)
