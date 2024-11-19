#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


int counter = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void *increment_counter(void *arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        printf("Incremented counter to %d\n", counter);
        if (counter == 5) {
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *wait_for_counter(void *arg) {
    pthread_mutex_lock(&mutex);
    while (counter < 5) {
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Counter reached 5! Proceeding...\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, wait_for_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
//Note : To Compile use --> gcc -pthread name_of_file.c -o any name;
//       To Run ./name you have given in place of any name;