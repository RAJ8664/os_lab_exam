#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>

int main() {
    int x = 100;
    int f = fork();
    if (f < 0) {
        perror("Process Creation Failed:\n");
        exit(EXIT_FAILURE);
    }
    else if (f == 0) {
        printf("Child Process : \n");
        printf("Value of X before changing its the value : %d\n", x);
        x += 50;
        printf("Value of X after changing its the value : %d\n", x);
    }
    else if (f > 0) {
        printf("Parent Process :\n");
        printf("Value of X before changing its value : %d\n", x);
        x += 50;
        printf("Value of X after changing its value : %d\n", x);
    }
    return 0;
}