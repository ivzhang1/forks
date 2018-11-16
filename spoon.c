#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){
  printf("This is the parent function %d\n", getpid());

  wait(0);
  return 0;
}
