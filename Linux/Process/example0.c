#include <unistd.h>
#include<stdio.h>

int main() {
  printf("welcome..pid=%d\n", getpid());
  int ret =  fork();  //intentionally not capturing return value, in this example
  printf("Thank You\n");
  printf("thank you,pid=%d,ppid=%d,ret = %d\n", getpid(), getppid(),ret);
  return 0;
}