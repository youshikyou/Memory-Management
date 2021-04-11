#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    int *p = (int *)malloc(sizeof(int)*3);
    printf("address=%p, value=%d\n", p, *p);

    return 0; 
}