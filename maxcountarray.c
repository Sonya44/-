#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main()
{
  int a[N];
  int i,n = 1,j,maxn = 1,answ;
  srand(time(NULL));
  for(i = 0; i < N; i++){
    a[i] = rand()%100;
    printf("%d ",a[i]);
  }
  answ = a[0];
  for(i = 0; i < N - 1; i++){
    for(j = i + 1; j < N; j++){
        if(a[i] == a[j]){
            n++;
        }
    }
    if(n > maxn){
        maxn = n;
        n = 1;
        answ = a[i];
    }

  }
  printf("\n%d %d",maxn, answ);
  return 0;
}
