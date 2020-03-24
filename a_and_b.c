#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


int main()
{

    int a[N], b[N];

    int i;
    for(i = 0; i < N; i++){
    a[i] = rand()%100;
    b[i] = rand()%100;
    }

    printf("a:\n");
    for(i = 0; i < N; i++)
        printf("%d ", a[i]);

    printf("\nb:\n");
    for(i = 0; i < N; i++)
        printf("%d ", b[i]);

    int s = 0;
    int j;
    int last = a[N-1];
    for(i = 0; i < N; i++){
        if (a[i] == last)
                continue;
        for(j = 0; j < N; j++){
            if(a[i] == b[j]){
                last = a[i];
                s++;
                j = N;
            }
        }
    }

    printf("\notv \n%d", s);

    return 0;
}
