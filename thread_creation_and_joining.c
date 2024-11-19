#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>


void *message(void *arg) {
    char *msg = (char*)(arg);
    printf("%s\n", msg);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    //create;
    pthread_create(&thread1, NULL, message, "Hello From thread1!");
    pthread_create(&thread2, NULL, message, "Hello From thread2!");

    //join;
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Thread Terminated:\n");
}

//Note : To Compile use --> gcc -pthread name_of_file.c -o any name;
//       To Run ./name you have given in place of any name;