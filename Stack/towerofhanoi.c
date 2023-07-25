#include <stdio.h>
#include <stdlib.h>
void TOH(char* source,char* aux,char* dest,int n){
  if (n==1) printf("move disc %d from %s to %s \n",n,source,dest);
  else{
    TOH(source,dest,aux,n-1);
    printf("move disc %d from %s to %s \n",n,source,dest);
    TOH(aux,source,dest,n-1);
  }
}
int main() {
  char* s = "source";
  char* d = "destination";
  char* a = "intermediate";
  int n ;
  printf("Enter number of discs : ");
  scanf("%d",&n);
  TOH(s,a,d,n);
  return 0;
}
