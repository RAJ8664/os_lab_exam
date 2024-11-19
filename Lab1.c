//To create a new child process using fork system call.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
    int val = 10;
    int x = fork();
    if (x < 0) {
        printf("Process Creation Failed\n");
        exit(1);
    }
    else if (x == 0) {
        printf("Child Process Created:\n");
        printf("Process Id of Child Process: %d\n" , getpid());
        printf("Value of val in child Process : %d\n", val);
        printf("Process Id of Parent in child Process : %d\n", getppid());
    }
    else if (x > 0) {
        printf("Parent Process Created:\n");
        printf("Process Id of Parent Process : %d\n", getpid());
        printf("Value of val in Parent Process : %d\n", val);
        printf("Process Id of Parent in Parent Process : %d\n", getppid());
    }
}