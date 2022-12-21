#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd, nbytes;
  fd = open("alpha.txt", O_RDONLY);
  if (fd < 0) {
    perror("open");
    exit(1);
  }
  int chksize = 10;
char buf[chksize];
while(1) {
  nbytes = read(fd, buf, chksize);  
  if(nbytes==0) break;                //end of file
  if (nbytes < 0) {
      perror("read");
      exit(2);
  }
  buf[chksize]='\0';
  printf(buf);
  printf("\n");
  //write(1, buf, nbytes);
  printf("\n");

}

}