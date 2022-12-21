#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>

int main() {
  pid_t ret;
  printf("welcome..pid=%d\n", getpid());
  ret = fork();
  if (ret < 0) {
    perror("fork");
    exit(1);
  }
  if (ret == 0) {
    printf("Hello, this is child process\n");
    printf("child--welcome,pid=%d,ppid=%d\n", getpid(), getppid());
    exit(0);
  } else // ret>0
  {
    printf("Hello, this is parent process\n");
    printf("parent--hello,pid=%d,ppid=%d\n", getpid(), getppid());
    sleep(1);
  }
   //printf("thank you,pid=%d,ppid=%d\n", getpid(),getppid());
  return 0;
}