#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

int main() {
  pid_t ret;
  int i, max = 10;
  printf("welcome..pid=%d\n", getpid());
  ret = fork();
  if (ret < 0) {
    perror("fork");
    exit(1);
  }
  if (ret == 0) {
    printf("child--welcome,pid=%d,ppid=%d\n", getpid(), getppid());
    for (i = 1; i <= max; i++)
    {
        printf("child--%d\n", i);
        sleep(1);
    }
      
    exit(0);
  } else // ret>0
  {
    printf("parent--hello,pid=%d,ppid=%d\n", getpid(), getppid());
    for (i = 1; i <= max; i++)
    {
      printf("parent--%d\n", i);
      sleep(1);
    }
  }
  return 0;
}