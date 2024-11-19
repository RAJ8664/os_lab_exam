//To block a parent process until child completes using wait system call.
//In child process print all the odd numbers starting from 1 --- > 10;
//In parent process print all the even numbers starting from 2 -- > 10;

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    int x = fork();
    if (x < 0) {
        printf("Process Creation Failed:\n");
        exit(1);
    }
    else if (x > 0) {
        //This is parent process;
        wait(NULL);
        printf("Parent process starts : \n");
        for (int i = 2; i <= 10; i += 2) printf("%d ", i);
        printf("\n");
        printf("Parent Process Ends\n");
    }

    else if (x == 0) {
        //This is child process;
        printf("Child Processs starts:\n");
        for (int i = 1; i <= 10; i += 2) printf("%d ", i);
        printf("\n");
        printf("Child Process Ends\n");
    }
    return 0;
}