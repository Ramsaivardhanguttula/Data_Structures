#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

int main(){

    int ret;

    int write_bytes=0,read_bytes=0;

    int fds[2];

    ret= pipe(fds);

    if(ret<0){

        perror("pipe");

        exit(1);

    }

    char str[]="1-msg-1\n";

    int len=strlen(str);

    write_bytes=write(fds[1],str,len);

    if(write_bytes<0){

        perror("write");

    }

    char str2[]="2-msg-2\n";

    int len2=strlen(str2);

    write_bytes=write(fds[1],str2,len2);

    if(write_bytes<0){

        perror("write");

    }

    char buf[128];

    read_bytes=read(fds[0],buf,128);

    if(read_bytes<0){

        perror("read");

    }

    write(1,buf,read_bytes);

    close(fds[0]);

    close(fds[1]);

    return 0;

}