#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


int main()
{

    int a[N];

    srand(time(NULL));

    int i;
    for(i = 0; i < N; i++)
        a[i] = rand()%100;

    ;
    for(i = 0; i < N; i++)
        printf("%d ", a[i]);

    int imin, imax;
    imin = imax = 0;
    for(i = 0; i < N; i++){
        if(a[imin] > a[i])
            imin = i;
        if(a[imax] < a[i])
            imax = i;
    }

    printf("\nmin: %d\nmax: %d\n", a[imin], a[imax]);

    int s=0;
    if(imin < imax){
        for(i = imin+1; i < imax; i++)
            s+=a[i];
    }
    else{
        for(i = imax+1; i < imin; i++)
            s+=a[i];
    }

    printf("sum : %d", a[imin], a[imax], s);

    return 0;
}
