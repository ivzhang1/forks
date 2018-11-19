#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(){
  srand(time(NULL));
  printf("PREFORKING\n");
  int f = fork();
  int g;
  if(f){
    printf("THIS IS THE PARENT: %d\n", getpid());
    int mac;
    int _pid = wait(&mac);

    printf("Child PID: %d, Sleep Time: %d\n", _pid, WEXITSTATUS(mac));
    printf("Parent done\n");
    return 0;
  }
  else{
    g = fork();
    if(g){
      int rand1 = rand() % 16 + 5;
      printf("THIS IS THE CHILD0: %d\n", getpid());
      sleep(rand1);
      printf("CHILD0. Done sleeping, WOKE\n");
      return rand1;
    }
    else{
      srand(0);
      int rand2 = rand() % 16 + 5;
      printf("THIS IS THE CHILD1: %d\n", getpid());
      sleep(rand2);
      printf("CHILD1. Done sleeping, WOKE\n");
      return rand2;
    }
  }

  return 0;
}
