#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    /*int a[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};*/
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};


    int i;
    srand(time(NULL));

    int N = sizeof(a)/sizeof(int);


    for(i = 0; i < N; i++)
        printf("%d ", a[i]);

    for(i = 0; i <= N/2; i++){
        if(a[N-1-i] != a[i]){
            printf("\nFalse");
            return 0;
        }
    }

    printf("\nTrue");

    return 0;
}
