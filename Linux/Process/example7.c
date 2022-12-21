#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main() {
  pid_t ret;
  int status;
  printf("welcome...pid=%d\n", getpid());
  ret = fork();
  if (ret < 0) {
    perror("fork");
    exit(1);
  }
  if (ret == 0) {
    printf("child--hello,pid=%d,ppid=%d\n", getpid(), getppid());
    int k;
     k = execl("/usr/bin/cal", "cal", "10", "2021", NULL);

    if (k < 0) {
      perror("execv");
      exit(1);
    }
    //printf("ram");
    exit(0);
  } else // ret>0
  {
    printf("parent--hello,pid=%d,ppid=%d\n", getpid(), getppid());
    
    waitpid(-1, &status, NULL);
  }
  return 0;
}