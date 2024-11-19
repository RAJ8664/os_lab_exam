//To load an executable program in a child processes exec system call.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        perror("Not the Correct argument");
        exit(EXIT_FAILURE);
    }
    int x = fork();
    if (x < 0) {
        printf("Process Creation Failed:\n");
        exit(EXIT_FAILURE);
    }
    else if (x > 0) {
        //Parent Process, need to wait;
        wait(NULL);
        printf("Child Terminated");
        exit(EXIT_SUCCESS);
    }
    else if (x == 0) {
        //child process;
        if (execvp(argv[1], &argv[1]) == -1) {
            perror("Program not found:\n");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
}

//TO use -- > gcc Lab3.c -o Lab3.c
// ----------> ./Lab3 /bin/ls -l
//------------->  output will be having total == ...  followed by all the files in the current directory;
//--------------> here the total = x means x blocks of storage are used by all the files listed;
