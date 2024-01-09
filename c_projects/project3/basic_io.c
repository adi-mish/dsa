#include <stdio.h>

/* copy input to output; 2nd version */

int main() 
{
    int c = 0;

    while ((c = getchar()) != EOF){
        putchar(c);
    }

    return 0;
}
