#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  pid_t ret;
  int i, status;
  printf("welcome..pid=%d\n", getpid());
  ret = fork();
  if (ret < 0) {
    perror("fork");
    exit(1);
  }
  if (ret == 0) {
    printf("child--welcome,pid=%d,ppid=%d\n", getpid(), getppid());
    for (i = 1; i <= 5; i++) {
      printf("child--pid=%d,ppid=%d\n", getpid(), getppid());
      usleep(100);
    }
    exit(5);
    //exit(0);
  } else // ret>0
  {
    printf("parent--hello,pid=%d,ppid=%d\n", getpid(), getppid());
    // some work by parent
    waitpid(-1, &status, 0); // wait(&status);
    printf("parent--child exit status=%d\n", WEXITSTATUS(status));
  }
  return 0;
}