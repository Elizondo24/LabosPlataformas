#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main() {
    int done = FALSE;
    int j=0;

    while (!done) {
        int n = 10000000;
        int* a = ( int* )malloc(n * sizeof ( int ));

        int i ;
        for ( i=0; i < n; i++){
            a[ i ] = i ;
            j++;
            printf("%d\n", i );
            if (j>10)
            {
               return 0;
            }
            
        }
        if (!a) {
            perror(NULL);
            exit (1);
        }  
        free(a);
    }
     
    return 0;

}