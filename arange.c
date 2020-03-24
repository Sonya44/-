#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5


int main()
{
  int a[N];
  int i;
  srand(time(NULL));
  for(i = 0; i < N; i++){
    a[i] = rand()%100;
    printf("%d ",a[i]);
  }
  for(i = 0; i < N - 1; i++){
    if(a[i] > a[i+1]){
        printf("\nFalse");
        return 1;
    }
  }
  printf("\nTrue");
  return 0;
}
