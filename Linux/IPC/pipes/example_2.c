#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

int main(){

    int ret;

    int nbytes=0;

    int fds[2];

    ret= pipe(fds);

    if(ret<0){

        perror("pipe");

        exit(1);

    }

    ret=fork();

    if(ret==0){          // read from child

        close(fds[1]);

        char buf[128];

        nbytes=read(fds[0],buf,128);

        if(nbytes<0){

            perror("read");

        }

        write(1,buf,nbytes);

        close(fds[0]);

    }

    else{     // write from parent

        close(fds[0]);

        char str[]="1-msg-1\n";

        int len=strlen(str);

        nbytes=write(fds[1],str,len);

        if(nbytes<0){

            perror("write");

        }

        char str2[]="2-msg-2\n";

        int len2=strlen(str2);

        nbytes=write(fds[1],str2,len2);

        if(nbytes<0){

            perror("write");

        }

        close(fds[1]);

    }

    return 0;

}

